`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:42:50 04/07/2018
// Design Name:   Beta_MEM
// Module Name:   E:/EPD2FINAL/BETA_PROCESSOR_V2/TBfinal.v
// Project Name:  BETA_PROCESSOR
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Beta_MEM
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TBfinal;

	// Inputs
	reg clk;
	reg RESET;
	reg IRQ;

	// Outputs
	wire [31:0] IAdr;
	wire [31:0] WD;
	wire MOE;

	// Instantiate the Unit Under Test (UUT)
	Beta_MEM uut (
		.clk(clk), 
		.RESET(RESET), 
		.IRQ(IRQ), 
		.IAdr(IAdr), 
		.WD(WD), 
		.MOE(MOE)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		RESET = 0;
		IRQ = 0;
		#10;
		RESET=1;
		repeat(2)
		#10 clk=~clk;
		RESET=0;
		repeat(100)
		#10 clk=~clk;
		
		
        
		// Add stimulus here

	end
      
endmodule

