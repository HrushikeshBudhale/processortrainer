`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:35:06 02/07/2019
// Design Name:   TOP
// Module Name:   C:/Users/HRUSHIKESH/Desktop/proj/convert_8and32/top_tb.v
// Project Name:  convert_8and32
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: TOP
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module top_tb;

	// Inputs
	reg Clk;
	reg Rst_n;
	reg Rx;
	reg [31:0] in_32;

	// Outputs
	wire Tx;
	wire [7:0] RxData;
	
	integer Data = 10;
	integer cnt = 142;
	integer i = 0;
	
	// Instantiate the Unit Under Test (UUT)
	TOP uut (
		.Clk(Clk), 
		.Rst_n(Rst_n), 
		.Rx(Rx), 
		.Tx(Tx), 
		.RxData(RxData), 
		.in_32(in_32)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Rst_n = 1;
		Rx = 0;
		in_32 = 2190650042;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		repeat(520)
			#1 Clk <= ~Clk;
		
	end
   
	always
	begin
		#1 Clk <= ~Clk;
		if(Data == 10)
		begin
			Data <= cnt;
			#1000;
			repeat(9)
			begin
				Rx <= i;
				repeat(10400)
					#1 Clk <= ~Clk;
				i <= Data % 2;
				Data <= Data >> 1;
			end
			Rx <= 1;
		end
	end
	
endmodule

