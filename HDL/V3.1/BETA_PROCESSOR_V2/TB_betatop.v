`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:10:29 04/06/2018
// Design Name:   Beta_TOP
// Module Name:   E:/EPD2FINAL/BETA_PROCESSOR/TB_betatop.v
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

module TB_betatop;

	// Inputs
	reg clk;
	reg RESET;
	reg IRQ;
	reg [31:0] D;
	reg [31:0] RD;

	// Outputs
	wire [31:0] IAdr;
	wire [31:0] Adr;
	wire [31:0] WD;
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
		.Adr(Adr), 
		.WD(WD), 
		.MOE(MOE), 
		.MWR(MWR)
	);

	initial begin
		// Initialize Inputs
		clk = 0;	RESET = 1;	IRQ = 0;	D = 0;	RD = 0;	#10;
      clk = 1;	RESET = 1;	IRQ = 0;	D = 0;	RD = 0;	#10;
      clk = 0;	RESET = 0;	IRQ = 0;	D = 0;	RD = 0;	#10;
      D=32'h80400800;  
		#10;clk=~clk;#10;
		D=32'hA0600800;  
		#10;clk=~clk;#10;
		D=32'h90800800;  
		#10;clk=~clk;#10;
		D=32'h98A00800;  
		#10;clk=~clk;#10;
		D=32'h94c10800 ; 
		#10;clk=~clk;#10;
		D=32'h8CE00800;  
		#10;clk=~clk;#10;
		D=32'h89000800;  
		#10;clk=~clk;#10;
		D=32'ha5200800;  
		#10;clk=~clk;#10;
		D=32'hab1400800;  
		#10;clk=~clk;#10;
		D=32'ha5200800;  
		#10;clk=~clk;#10;
		D=32'hb5600800;  
		#10;clk=~clk;#10;
		D=32'hb9800800;  
		#10;clk=~clk;#10;
		D=32'h85a00800;  
		#10;clk=~clk;#10;
		D=32'ha9c00800;  
		#10;clk=~clk;#10;
		
		
		
		repeat(30)
		#10 clk=~clk;
        
		end
      
endmodule

