`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:56:40 01/22/2019
// Design Name:   TOP
// Module Name:   C:/Users/HRUSHIKESH/Desktop/EPD2/comm/UART_tb.v
// Project Name:  comm
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

module UART_tb;

	// Inputs
	reg Clk;
	reg Rst_n;
	reg Rx;
	reg [7:0] TxData;
	reg TxEn;

	// Outputs
	wire Tx;
	wire [7:0] RxData;
	wire RxDone;
	wire TxDone;
	
	integer num = 83;
	integer Data = 0;
	integer cnt = 85;
	integer i = 0;
	// Instantiate the Unit Under Test (UUT)
	TOP uut (
		.Clk(Clk), 
		.Rst_n(Rst_n), 
		.Rx(Rx), 
		.TxData(TxData), 
		.TxEn(TxEn), 
		.Tx(Tx), 
		.RxData(RxData), 
		.RxDone(RxDone), 
		.TxDone(TxDone)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Rst_n = 1;
		Rx = 1;
		TxData = 0;
		TxEn = 0;
		// Wait 100 ns for global reset to finish
		#100;
		// Add stimulus here
		repeat(52000)
		#1 Clk = ~Clk;
		
//		repeat(5)
//		begin
//			Data = cnt;
//			i = 0;
//			repeat(9)
//			begin
//				Rx = i;
//				repeat(10400)
//					#1 Clk = ~Clk;
//				i = Data % 2;
//				Data = Data >> 1;
//			end
//			cnt = cnt + 1;
//			Rx = 1;
//			repeat(20400)
//				#1 Clk = ~Clk;
//		end
	end
    
	always @(negedge TxDone)
	begin
		num = num + 1;
		TxData = num;
		#10
		TxEn = 1;
		#10
		TxEn = 0;
	end

	always begin
		#1 Clk = ~Clk;
	end
	
endmodule

