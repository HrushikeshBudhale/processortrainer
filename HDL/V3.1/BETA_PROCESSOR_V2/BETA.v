`timescale 1ns/1ps 

module Beta_MEM(input clk,RESET,IRQ,
					 output wire[31:0] IAdr,WD,
					 output MOE);

wire[31:0] D,RD,Adr;	
wire MWR;			
Beta_TOP core(clk,RESET,IRQ,
					  D,RD,
					  IAdr,WD,
					  Adr,
					 MOE,MWR);
					
MEM_INS MEM_I({1'b0,IAdr[30:0]},
				  D);
				  
MEM_DATA MEM_D(WD,Adr, 
					MWR,clk,	
			      RD);

endmodule 
				 
				  

