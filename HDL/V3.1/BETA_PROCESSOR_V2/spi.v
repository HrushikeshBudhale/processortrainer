`timescale 1ns/1ps

module spi(data_out, dig_in, addr_in, ss, clk)
	input [7:0] dig_in;
	input [3:0] addr_in;
	input clk, ss;
	output reg dataout;
	reg[15:0] temp;
	parameter max_cnt = 16;
	
	initial
		reg [4:0] cnt = 0;
		
	always @(posedge clk and ss)
      if (cnt == 0)
			temp = {4'bx, addr_in, dig_in};
			
		if (cnt < max_cnt) begin
         cnt = cnt + 1;
			data_out = temp[15];
			temp = {temp[14:1],1'b0};
      end