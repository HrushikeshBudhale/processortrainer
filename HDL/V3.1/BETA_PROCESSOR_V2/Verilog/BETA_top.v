`timescale 1 ns/1 ps 

module Beta_TOP(input clk,RESET,IRQ,
					 input[31:0] D,RD,
					 output[31:0] IAdr,WD,
					 output wire[31:0] Adr,
					 output  MOE,MWR);

wire RA2SEL,WASEL,Z_wire,WERF,ASEL,BSEL;
wire[1:0] WDSEL;
wire[2:0] PCSEL;
wire[5:0] ALUFN;
wire[31:0] RD1,RD2,PC,PC_PLUS_4,WDATA,ALU_out,WD_RF,A,B,branch_addr;


//assign Z_wire=(RD1 == 0)?1:0;
assign branch_addr = PC_PLUS_4 + {{14{D[15]}},D[15:0],2'b00};
assign A = ASEL?branch_addr:RD1;
//assign B = BSEL?RD2:{{16{D[15]}},D[15:0]};
assign Adr = ALU_out;
assign WD = RD2;
//assign WD_RF =(WDSEL == 0)?PC_PLUS_4:(WDSEL == 1)?ALU_out:RD;
PC ProgramCounter(
						clk,RESET,
						PCSEL,
				      D[15:0],
				      RD1, //jump_addr,/*use in JMP instruction*/
						IAdr,
						PC_PLUS_4);

REGFILE RF(
			 clk,
			 RA2SEL, 
          WASEL,
          WERF,
          D[20:16],//RA
			 D[15:11],//RB
          D[25:21],//RC
          WD_RF,
			 RD1,
			 RD2);
			 
CTL ControlLogic(
					  D[31:26],
					  RESET,
					  IRQ,
					  Z_wire,

					 ALUFN,
					 ASEL,
					 BSEL,
					 MOE,
					 MWR,
					 PCSEL,
					 RA2SEL,
					 WASEL,
					 WDSEL,
					 WERF);
					 
WDSEL_MUX MUX( PC_PLUS_4,ALU_out,RD,
					WDSEL,
					WD_RF);

ALU ArathLogicUnit(
		A,
	   B,
	   ALUFN,
	   ALU_out);

MUX2_1 MUX_B(RD2,{{16{D[15]}},D[15:0]},
				BSEL,
		      B);

cmpZero Zer( RD1,
			   Z_wire);
		 

endmodule 