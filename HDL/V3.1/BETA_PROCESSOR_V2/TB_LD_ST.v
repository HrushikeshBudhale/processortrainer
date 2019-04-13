`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:24:25 04/06/2018
// Design Name:   Beta_TOP
// Module Name:   E:/EPD2FINAL/BETA_PROCESSOR_V2/TB_LD_ST.v
// Project Name:  BETA_PROCESSOR
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Beta_TOP
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TB_LD_ST;

	// Inputs
	reg clk;
	reg RESET;
	reg IRQ;
	reg [31:0] D;
	reg [31:0] RD;

	// Outputs
	wire [31:0] IAdr;
	wire [31:0] WD;
	wire [31:0] Adr;
	wire MOE;
	wire MWR;

	// Instantiate the Unit Under Test (UUT)
	Beta_TOP uut (
		.clk(clk), 
		.RESET(RESET), 
		.IRQ(IRQ), 
		.D(D), 
		.RD(RD), 
		.IAdr(IAdr), 
		.WD(WD), 
		.Adr(Adr), 
		.MOE(MOE), 
		.MWR(MWR)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		RESET = 0;
		IRQ = 0;
		D = 0;
		RD = 0;
		#10;
		RESET=1;
		repeat(2)
		#10 clk=~clk;
		RESET=0;
		repeat(2)
		#10 clk=~clk;
		RD=82;
		D=32'hA8400800; //0110 0000 1001 1111 0000 0000 0000 1000;
		repeat(2)
		#10 clk=~clk;
		D=32'h00000000;
		repeat(10)
		#10 clk=~clk;
        
		// Add stimulus here

	end
      
endmodule

