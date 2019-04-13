`timescale 1ns/1ps
module PC(
				input clk,RESET,
				input[2:0] PCSEL,
				input[15:0] offset,
				input[31:0] jump_addr,/*use in JMP instruction*/
				//input[31:0] branch_addr,/* for symulation purpose*/
				//inout[31:0] branch_addr,/* for synthesize */
				output reg[31:0] PC,
				output [31:0] PC_PLUS_4);
				
//reg[31:0] PC;
wire[30:0] PC_inc;
wire[31:0] nPC;
wire[31:0] branch_addr;

assign PC_inc= PC+4;
assign PC_PLUS_4={PC[31],PC_inc};

//Branch address = pc  + 4 + 4*sext(offset)
assign branch_addr = {1'b0,PC_inc + {{13{offset[15]}},offset[15:0],2'b00}};

assign nPC = RESET ? 32'h80000000 :
				 (PCSEL == 0) ? {PC[31],PC_inc} :
				 (PCSEL == 1) ? {PC[31],branch_addr[30:0]} :
				 (PCSEL == 2) ? {PC[31] & jump_addr[31],jump_addr[30:0]} :
				 (PCSEL == 3) ? 32'h80000004 :
				 (PCSEL == 4) ? 32'h80000008 :
				 32'hxxxxxxxx;

always@( posedge clk)
	PC<= nPC;
	endmodule 