`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:20:06 02/07/2019
// Design Name:   TOP
// Module Name:   C:/Users/HRUSHIKESH/Desktop/proj/uart_led_test/top2_tb.v
// Project Name:  uart_led_test
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

module top2_tb;

	// Inputs
	reg Clk;
	reg Rst_n;
	reg Rx;
	reg button_in;

	// Outputs
	wire Tx;
	wire [7:0] RxData;
	wire RxDone;
	wire TxDone;
	wire leda;
	wire ledb;
	wire ledc;
	wire ledd;
	wire lede;
	wire ledf;
	wire ledg;

	// Instantiate the Unit Under Test (UUT)
	TOP uut (
		.Clk(Clk), 
		.Rst_n(Rst_n), 
		.Rx(Rx), 
		.Tx(Tx), 
		.RxData(RxData), 
		.RxDone(RxDone), 
		.TxDone(TxDone), 
		.leda(leda), 
		.ledb(ledb), 
		.ledc(ledc), 
		.ledd(ledd), 
		.lede(lede), 
		.ledf(ledf), 
		.ledg(ledg), 
		.button_in(button_in)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Rst_n = 1;
		Rx = 0;
		button_in = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
   
	always @(negedge TxDone)
	begin
		#1000;
		button_in = 1;
		#100000;	// need to be hold till 0.1 millisecond
		button_in = 0;
		#100;
	end

	always begin
		#5 Clk = ~Clk;
	end
	  
endmodule

