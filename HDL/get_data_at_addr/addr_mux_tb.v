`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:24:12 02/07/2019
// Design Name:   address_multiplexer
// Module Name:   C:/Users/HRUSHIKESH/Desktop/proj/get_data_at_addr/addr_mux_tb.v
// Project Name:  get_data_at_addr
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: address_multiplexer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module addr_mux_tb;

	// Inputs
	reg Clk;
	reg rx_done;
	reg Reset;
	reg [7:0] addr_in_8;
	reg [31:0] data_inst_32;
	reg [31:0] data_pc_32;
	reg [31:0] data_cntl_32;
	reg [31:0] data_a_32;
	reg [31:0] data_b_32;
	reg [31:0] data_alu_32;
	reg [31:0] data_rf_32;
	reg [31:0] data_dm_32;

	// Outputs
	wire [4:0] addr_rf_5;
	wire read_rf_en;
	wire [4:0] addr_dm_5;
	wire read_dm_en;
	wire [31:0] data_out_32;

	integer addr = 8'b00000010;
	// Instantiate the Unit Under Test (UUT)
	address_multiplexer uut (
		.Clk(Clk), 
		.rx_done(rx_done), 
		.Reset(Reset), 
		.addr_in_8(addr_in_8), 
		.data_inst_32(data_inst_32), 
		.data_pc_32(data_pc_32), 
		.data_cntl_32(data_cntl_32), 
		.data_a_32(data_a_32), 
		.data_b_32(data_b_32), 
		.data_alu_32(data_alu_32), 
		.data_rf_32(data_rf_32), 
		.data_dm_32(data_dm_32), 
		.addr_rf_5(addr_rf_5), 
		.read_rf_en(read_rf_en), 
		.addr_dm_5(addr_dm_5), 
		.read_dm_en(read_dm_en), 
		.data_out_32(data_out_32)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		rx_done = 0;
		Reset = 0;
		addr_in_8 = 1;
		
		data_inst_32 = 3;
		data_pc_32 = 2;
		data_cntl_32 = 4;
		data_a_32 = 5;
		data_b_32 = 6;
		data_alu_32 = 7;
		data_rf_32 = 1;
		data_dm_32 = 8;
		// Wait 100 ns for global reset to finish
		#100;
      Reset = 1;
		// Add stimulus here
		
		repeat(8)
		begin
			repeat(100)
				#1 Clk <= ~Clk;
			addr_in_8 = addr;
			rx_done = 1;
			repeat(10)
				#1 Clk <= ~Clk;
			rx_done = 0;
			repeat(100)
				#1 Clk <= ~Clk;
			addr = addr + 8'b00100000;
		end
	end
      
endmodule

