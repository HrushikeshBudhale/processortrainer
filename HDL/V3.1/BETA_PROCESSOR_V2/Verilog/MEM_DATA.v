//`timescale  1 ns / 1 ps 
//module MEM_DATA(input[31:0] WD,Adr,
//					 input Wr,	
//					 output reg[31:0] RD);
//				 
//reg[31:0] MEM[0:1024];
//initial $readmemh("output.txt",MEM);
//
//always@(*)
//begin
//	 if(Wr)
//	 MEM[Adr]=WD;
//	 else 
//	 RD=MEM[Adr];
//	 
//end
//
//endmodule 

`timescale  1 ns / 1 ps 
module MEM_DATA(input[31:0] WD,Adr,
					 input Wr,clk,	
					 output reg[31:0] RD);
				 
reg[31:0] MEM[0:1024];
initial $readmemh("output.txt",MEM);


 
always@(posedge clk)
begin 
	
	 RD = MEM[Adr];
	
	if(Wr)
	 MEM[Adr]<=WD;
end 


endmodule 