`timescale 1 ns/1 ps 
`include "Beta_Opcode.vh" 

module ALU (
	  input [31:0] A,
	  input [31:0] B,
	  input [5:0] FN,
	  output reg [31:0] Y
	  //output reg Z,V,N
  );
  
 always@(*)
 begin 
	case(FN)
		`ALU_ADD: Y<=A+B;
		`ALU_SUB: Y<=A-B;
		`ALU_AND: Y<=A&B;
		`ALU_OR: Y<=A|B;
		`ALU_XOR: Y<=A^B;
		`ALU_LDR: Y<=A;
		`ALU_SHL: Y<=A<<B[4:0];
		`ALU_SHR: Y<=A>>B[4:0];
		`ALU_SRA: Y<=A>>>B[4:0];
		`ALU_CMPEQ: Y<=(A == B)?1:0;
		`ALU_CMPLT: Y<=(A < B)?1:0;
		`ALU_CMPLE: Y<=(A <= B)?1:0;
		`ALU_MUL:Y<=A*B;
		`ALU_DIV:Y<=A/B;
	endcase 
//	Z=(A == B)?1'b1:1'b0;
//	N=Y[31];
//	V=(A+B<A|A+B<B|A-B>A)?1'b1:1'b0;		
end 
endmodule 
 
