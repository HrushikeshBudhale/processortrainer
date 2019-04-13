`timescale 1ns / 1ps 
module WDSEL_MUX(input[31:0] I0,I1,I2,
		 input[1:0] WDSEL,
		 output reg[31:0] WD_in);
	
always@(*)
begin
	case(WDSEL)
	0:WD_in=I0;
	1:WD_in=I1;
	2:WD_in=I2;
	endcase
end 
endmodule

module MUX2_1(input[31:0] I0,I1,
		 input SEL,
		 output reg[31:0] O);
		 
always@(*)
begin 
	case(SEL)
	0:O=I0;
	1:O=I1; 
	endcase
end 

endmodule  

module cmpZero(input [31:0] I,
					output reg Z);
					
always@(*)
begin 
		if(I == 0)
		 Z=1;
		else
		 Z=0;
end


endmodule 