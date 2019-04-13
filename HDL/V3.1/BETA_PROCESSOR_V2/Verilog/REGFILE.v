`timescale 1ns / 1ps
module REGFILE(
    input CLK,
    input RA2SEL,
    input WASEL,
    input WERF,
    input [4:0] RA,
    input [4:0] RB,
    input [4:0] RC,
    input [31:0] WDATA,
    output reg [31:0] RADATA,
    output reg [31:0] RBDATA
    );

reg [4:0] rc_i;
reg [4:0] rb_i;
wire [31:0] rd1_i;
wire [31:0] rd2_i;

DRAM32x32 A_DIST (
  .a(rc_i), // input [4 : 0] a
  .d(WDATA), // input [31 : 0] d
  .dpra(RA), // input [4 : 0] dpra
  .clk(CLK), // input clk
  .we(WERF), // input we
  .dpo(rd1_i) // output [31 : 0] dpo
);
DRAM32x32 B_DIST (
  .a(rc_i), // input [4 : 0] a
  .d(WDATA), // input [31 : 0] d
  .dpra(rb_i), // input [4 : 0] dpra
  .clk(CLK), // input clk
  .we(WERF), // input we
  .dpo(rd2_i) // output [31 : 0] dpo
);




always @ (*) begin
	case(WASEL)
		0:rc_i=RC;
		1:rc_i=30;
	endcase
	
	case(RA2SEL)
		0:rb_i=RB;
		1:rb_i=RC;
	endcase
	
	case(RA)
		31:RADATA=0;
		default: RADATA=rd1_i;
	endcase	
	
	case(rb_i)
		31:RBDATA=0;
		default: RBDATA=rd2_i;
	endcase		
end

endmodule


module DRAM32x32(input[4:0] a,dpra,
					  input[31:0] d,
					  input clk,we,
					  output reg [31:0] dpo);

reg[31:0] reg_file[0:31];
initial $readmemh("reg_bank_init.txt",reg_file);

always@(posedge clk)
begin 
	if(we)
	reg_file[a]=d;
end
always@(*)
begin 
dpo=reg_file[dpra];
end
endmodule 	
