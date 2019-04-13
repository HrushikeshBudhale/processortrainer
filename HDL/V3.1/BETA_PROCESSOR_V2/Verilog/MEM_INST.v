`timescale 1ns / 1ps 
module MEM_INS(input[31:0] adr,
				  output[31:0] data);
				 
reg[31:0] MEM[0:2048];
initial $readmemh("output.txt",MEM);


assign data=MEM[adr/4];

endmodule 