# -*- coding: utf-8 -*-
"""
Created on Sat Apr  7 05:11:19 2018

@author: HRUSHIKESH
"""


class asm:

    __tags = {}
    __line = 0
    __remaining = {}
    __opcode = [0x20, 0x30, 0x28, 0x38, 0x1d, 0x1e, 0x24, 0x34, 0x26, 0x36,
                0x25, 0x35, 0x23, 0x33, 0x1b, 0x18, 0x1f, 0x22, 0x32, 0x29,
                0x39, 0x2c, 0x3c, 0x2d, 0x3d, 0x2e, 0x3e, 0x21, 0x31, 0x19,
                0x2a, 0x3a]
    __src = []
    __hexstr = []
    __inString = ""
    __form = "binary"

    def clear(self):
        self.__tags = {}
        self.__line = 0
        self.__remaining = {}
        self.__src = []
        self.__hexstr = []
        self.__inString = ""
        self.__form = "binary"

    def __twos_compliment(self, val):
        """ Compute the 2's complement of int value val """
        bits = 16
        return int(bin(((1 << bits) - 1) & val)[2:], 2)

    def __store_tag(self, word):
        self.__tags[word[1:]] = self.__line

    def __translate(self, op, destinationReg, sourceReg, literal):
        ''' Receive opcode, destination register, source register,
            literal or 2nd source register and convert to respective
            binary string'''
        text = ''
        if type(literal) is str:    # i.e. literal is sourceReg
            text += format(self.__opcode[op], '06b') + \
                format(int(destinationReg[1:]), '05b')
            text += format(int(sourceReg[1:]), '05b') + \
                format(int(literal[1:]), '05b')
            text += format(0, '011b')
        else:   # of type int
            text += format(self.__opcode[op+1], '06b') + \
                format(int(destinationReg[1:]), '05b')
            text += format(int(sourceReg[1:]), '05b') + \
                format(self.__twos_compliment(literal), '016b')
        text += '\n'
        return text

    def __execute_remaining(self):
        for line in self.__remaining:
            self.__line = line - 1
            eval(self.__remaining[line])
            text = self.__src.pop()
            self.__src[line-1] = text

    def assemble(self, form='binary'):
        ''' Assembles the assembly language program after 'scan_file' executed
            and creates '.txt' flie in the same directory'''

        for line in self.__inString:
            eval('self.'+line)

        self.__execute_remaining()

        self.__form = form

        with open('output.txt', 'w+') as f:
            if form == 'binary':
                f.writelines(self.__src)
                return self.__src

            else:
                for line in self.__src:
                    if len(line) > 8:
                        self.__hexstr.append(
                            '{:08X}\n'.format(int(line[:-1], 2)))
                f.writelines(self.__hexstr)
                return self.__hexstr

            print('Program assembled successfully.....!')

    def setInString(self, codeStr):
        self.__inString = codeStr.rstrip().split("\n")

    def ADD(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] + R[literal]
            else
                R[destinationReg] <- R[sourceReg] + literal(15:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            0, destinationReg, sourceReg, literal))

    def AND(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] & R[literal]
            else
                R[destinationReg] <- R[sourceReg] & literal(15:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__src.append(
            self.__translate(2, destinationReg, sourceReg, literal)))

    def B(self, literal, title=None):
        ''' Stack Pointer(R29) <- PC
            PC <-  address(label) - address(curr instr.) - 1
            '''
        destinationReg = 'R29'
        sourceReg = 'R31'
        self.__line += 1
        if title is not None:
            self.__store_tag(title)

        if literal in self.__tags:
            literal = (self.__tags[literal] - self.__line - 1)
            self.__src.append(self.__translate(
                3, destinationReg, sourceReg, literal))
        else:
            self.__src.append('-')
            new_str = 'self.B(\'' + literal + '\')'
            self.__remaining[self.__line] = new_str

    def BZ(self, sourceReg, literal, title=None):
        ''' if R[sourceReg] == 0
                Stack Pointer(R29) <- PC
                PC <-  address(label) - address(curr instr.) - 1
            '''
        destinationReg = 'R29'
        self.__line += 1
        if title is not None:
            self.__store_tag(title)

        if literal in self.__tags:
            literal = self.__tags[literal] - self.__line - 1
            self.__src.append(self.__translate(
                3, destinationReg, sourceReg, literal))
        else:
            self.__src.append('-')
            new_str = 'self.BZ(\'' + sourceReg + '\',\'' + literal + '\')'
            self.__remaining[self.__line] = new_str

    def BNZ(self, sourceReg, literal, title=None):
        ''' if R[sourceReg] != 0
                Stack Pointer(R29) <- PC
                PC <-  address(label) - address(curr instr.) - 1
            '''
        destinationReg = 'R29'
        self.__line += 1
        if title is not None:
            self.__store_tag(title)

        if literal in self.__tags:
            literal = self.__tags[literal] - self.__line - 1
            self.__src.append(self.__translate(
                4, destinationReg, sourceReg, literal))
        else:
            self.__src.append('-')
            new_str = 'self.BNZ(\'' + sourceReg + '\',\'' + literal + '\')'
            self.__remaining[self.__line] = new_str

    def CMPEQ(self, destinationReg, sourceReg, literal, title=None):
        '''if R[sourceReg] == (R[literal] or literal)
                R[destinationReg] <- 1
            else
                R[destinationReg] <- 0 '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            6, destinationReg, sourceReg, literal))

    def CMPLE(self, destinationReg, sourceReg, literal, title=None):
        '''if R[sourceReg] <= (R[literal] or literal)
                R[destinationReg] <- 1
            else
                R[destinationReg] <- 0 '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            8, destinationReg, sourceReg, literal))

    def CMPLT(self, destinationReg, sourceReg, literal, title=None):
        '''if R[sourceReg] < (R[literal] or literal)
                R[destinationReg] <- 1
            else
                R[destinationReg] <- 0 '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            10, destinationReg, sourceReg, literal))

    def DIV(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] / R[literal]
            else
                R[destinationReg] <- R[sourceReg] / literal '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            12, destinationReg, sourceReg, literal))

    def JMP(self, destinationReg,  title=None):
        ''' Stack Pointer(R29) <- PC
            PC <-  R[destinationReg] & 0xFFFFFFFC '''
        sourceReg = 'R29'
        literal = 0
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            13, sourceReg, destinationReg, literal))

    def LOAD(self, destinationReg, sourceReg, literal, title=None):
        ''' R[destinationReg] <- MEM[ R[sourceReg] + literal ] '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            14, destinationReg, sourceReg, literal))

    def LOADR(self, destinationReg, literal, title=None):
        ''' R[destinationReg] <- PC + literal '''
        sourceReg = 'R31'
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            15, destinationReg, sourceReg, literal))

    def MUL(self, destinationReg, sourceReg, literal, title=None):
        ''' if literal is of type str
                R[destinationReg] <- R[sourceReg] * R[literal]
            else
                R[destinationReg] <- R[sourceReg] * literal(15:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            17, destinationReg, sourceReg, literal))

    def OR(self, destinationReg, sourceReg, literal, title=None):
        ''' if literal is of type str
                R[destinationReg] <- R[sourceReg] | R[literal]
            else
                R[destinationReg] <- R[sourceReg] | literal(15:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            19, destinationReg, sourceReg, literal))

    def SHL(self, destinationReg, sourceReg, literal, title=None):
        ''' if literal is of type str
                R[destinationReg] <- R[sourceReg] << R[literal](4:0)
            else
                R[destinationReg] <- R[sourceReg] << literal(4:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            21, destinationReg, sourceReg, literal))

    def SHR(self, destinationReg, sourceReg, literal, title=None):
        ''' if literal is of type str
                R[destinationReg] <- R[sourceReg] >> R[literal](4:0)
            else
                R[destinationReg] <- R[sourceReg] >> literal(4:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            23, destinationReg, sourceReg, literal))

    def SRA(self, destinationReg, sourceReg, literal, title=None):
        ''' if literal is of type str
                R[destinationReg] <- R[sourceReg] >> R[literal](4:0)
            else
                R[destinationReg] <- R[sourceReg] >> literal(4:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            25, destinationReg, sourceReg, literal))

    def SUB(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] - R[literal]
            else
                R[destinationReg] <- R[sourceReg] - literal(15:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            27, destinationReg, sourceReg, literal))

    def STORE(self, sourceReg, destinationReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] & R[literal]
            else
                R[destinationReg] <- R[sourceReg] & literal(15:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            28, sourceReg, destinationReg, literal))

    def XOR(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] ^ R[literal]
            else
                R[destinationReg] <- R[sourceReg] ^ literal(15:0) '''
        self.__line += 1

        if title is not None:
            self.__store_tag(title)

        self.__src.append(self.__translate(
            30, destinationReg, sourceReg, literal))

    def MOVE(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] & R[literal]
            else
                R[destinationReg] <- R[sourceReg] & literal(15:0) '''
        self.__translate(2, destinationReg, sourceReg, literal)

    def PUSH(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] & R[literal]
            else
                R[destinationReg] <- R[sourceReg] & literal(15:0) '''
        self.__translate(2, destinationReg, sourceReg, literal)

    def POP(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] & R[literal]
            else
                R[destinationReg] <- R[sourceReg] & literal(15:0) '''
        self.__translate(2, destinationReg, sourceReg, literal)

    def ALLOCATE(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] & R[literal]
            else
                R[destinationReg] <- R[sourceReg] & literal(15:0) '''
        self.__translate(2, destinationReg, sourceReg, literal)

    def DEALLOCATE(self, destinationReg, sourceReg, literal, title=None):
        '''if literal is of type str
                R[destinationReg] <- R[sourceReg] & R[literal]
            else
                R[destinationReg] <- R[sourceReg] & literal(15:0) '''
        self.__translate(2, destinationReg, sourceReg, literal)
