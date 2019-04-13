`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:39:15 02/08/2019
// Design Name:   TOP
// Module Name:   C:/Users/HRUSHIKESH/Desktop/proj/sortAddr_32To8_uart2/top_tb.v
// Project Name:  sortAddr_32To8_uart2
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

	// Outputs
	wire Tx;
	
	integer Data = 0;
	integer cnt = 8'b00000010;
	integer i = 0;
	// Instantiate the Unit Under Test (UUT)
	TOP uut (
		.Clk(Clk), 
		.Rst_n(Rst_n), 
		.Rx(Rx), 
		.Tx(Tx)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Rst_n = 1;
		Rx = 1;

		// Wait 100 ns for global reset to finish
		#100;
		Rst_n = 0;
		#100;
      Rst_n = 1;
	
		// Add stimulus here
		repeat(5200)
		#1 Clk = ~Clk;
		
		repeat(8)
		begin
			Data = cnt;
			i = 0;
			repeat(9)
			begin
				Rx = i;
				repeat(10400)
					#1 Clk = ~Clk;
				i = Data % 2;
				Data = Data >> 1;
			end
			cnt = cnt + 8'b00100000;
			Rx = 1;
			repeat(450000)
				#1 Clk = ~Clk;
		end
	end
      
endmodule

