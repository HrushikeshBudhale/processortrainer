import json
import serial
import time

'''
# ! *****************************************************************
def createJSON(Rstr):

    Rstr = Rstr.split(' ')
    r = Rstr[1].split(':')
    m = Rstr[2].split(':')
    RxData = {'pc': 0, 'reg': {}, 'mem': {}}

    RxData['pc'] = int(Rstr[0])
    if len(r[0]) is not 0:
        RxData['reg'][r[0]] = int(r[1])
    if len(m[0]) is not 0:
        RxData['mem'][m[0]] = int(m[1])

    msg = json.dumps(RxData)
    print(msg)


# try:
ser = serial.Serial(port='com5', baudrate=115200)
print("Connected !!")
time.sleep(3)
ser.read_all()
ser.flush()
text = "77BF0002,77BF0001,77BF0000,C01F0001,C03F0001,88000800,C0210001,D8410005,7BA2FFFC,641F0004,77BFFFFF,d"
ser.write(text.encode())
while True:
    time.sleep(0.5)
    if (ser.inWaiting() > 0):
        s = ser.readline().decode()
        createJSON(s)

# except:
#     ser.close()
#     print("Disconnected !!!")
#     print("Port closed")
"""

# ! *****************************************************************

from assembler import asm

A = asm()
code = "B('START1')\nB('START1')\nB('START1')\nADD('R0','R31',1,':START1')\nADD('R1','R31',1)\nMUL('R0','R0','R1',':AGAIN')\nADD('R1','R1',1)\nCMPLE('R2','R1',5)\nBNZ('R2','AGAIN')\nSTORE('R0','R31',4)\nB('HERE',':HERE')\n"
A.setInString(code)
src = A.assemble('hex')
print(src) 

# ! *****************************************************************
'''

import os
import json

os.chdir('examples')
examples = os.listdir(os.curdir)

with open(examples[1], 'r') as exFile:
    data = exFile.read()
    print(data)

examples = [item[:-3] for item in examples]
