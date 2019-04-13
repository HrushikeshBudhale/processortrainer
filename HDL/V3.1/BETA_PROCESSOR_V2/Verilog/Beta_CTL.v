`timescale 1 ns/1 ps 
`include "Beta_Opcode.vh" 
module CTL (
  input [5:0] OP,
  input RESET,
  input IRQ,
  input Z,

  output reg [5:0] ALUFN,
  output reg ASEL,
  output reg BSEL,
  output reg MOE,
  output reg MWR,
  output reg [2:0] PCSEL,
  output reg RA2SEL,
  output reg WASEL,
  output reg [1:0] WDSEL,
  output reg WERF
  );

//internal signals and modules
reg mwr_i;
reg [2:0] pcsel_i;
reg wasel_i;
reg [1:0] wdsel_i;
reg werf_i;

//code body
always @ ( * ) begin
  if(IRQ) begin
    MWR<=0;
    PCSEL<=3'b100;
    WASEL<=1;
    WDSEL<=0;
    WERF<=1;
  end
  else begin
	 if(RESET)
		MWR<=0;
	 else
		MWR<=mwr_i;
    PCSEL<=pcsel_i;
    WASEL<=wasel_i;
    WDSEL<=wdsel_i;
    WERF<=werf_i;
  end
  case(OP)
    `L: begin //LD
      ALUFN<=`ALU_ADD;
      ASEL<=0;
      BSEL<=1;
      MOE<=1;
      mwr_i<=0;
      pcsel_i<=0;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2;
      werf_i<=1;
    end

    `ST: begin //ST
      ALUFN<=`ALU_ADD;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=1;
      pcsel_i<=0;
      RA2SEL<=1;
      wasel_i<=0;
      wdsel_i<=2'b00;
      werf_i<=0;
    end

    `JMP: begin //JMP
      ALUFN<=6'b000000;	//don't care
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b010;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b00;
      werf_i<=1;
    end

    6'b011101: begin //BEQ 
      ALUFN<=6'b000000;	//don't care
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      if(Z==1)
        pcsel_i<=3'b001;
      else
        pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b00;
      werf_i<=1;
    end

    `BNE: begin //BNE
      ALUFN<=6'b000000;	//don't care
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      if(Z==0)
        pcsel_i<=3'b001;
      else
        pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b00;
      werf_i<=1;
    end

    `LDR: begin //LDR
      ALUFN<=`ALU_LDR;
      ASEL<=1;
      BSEL<=0;
      MOE<=1;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b10;
      werf_i<=1;
    end

    `ADD: begin //ADD
      ALUFN<=`ALU_ADD;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end
	 
	 `MUL: begin //MUL
      ALUFN<=`ALU_MUL;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    `DIV: begin //DIV
      ALUFN<=`ALU_DIV;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

	 `SUB: begin //SUB
      ALUFN<=`ALU_SUB;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b100100: begin //CMPEQ
      ALUFN<=`ALU_CMPEQ;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b100101: begin //CMPLT
      ALUFN<=`ALU_CMPLT;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b100110: begin //CMPLE
      ALUFN<=`ALU_CMPLE;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b101000: begin //AND
      ALUFN<=`ALU_AND;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b101001: begin //OR
      ALUFN<=`ALU_OR;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b101010: begin //XOR
      ALUFN<=`ALU_XOR;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    /* 6'b101011: begin //XNOR
      ALUFN<=6'b101001;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
     end*/

    6'b101100: begin //SHL
      ALUFN<=`ALU_SHL;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b101101: begin //SHR
      ALUFN<=`ALU_SHR;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b101110: begin //SRA
      ALUFN<=`ALU_SRA;
      ASEL<=0;
      BSEL<=0;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b110000: begin //ADDC
      ALUFN<=`ALU_ADD;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b110001: begin //SUBC
      ALUFN<=`ALU_SUB;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b110100: begin //CMPEQC
      ALUFN<=`ALU_CMPEQ;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b110101: begin //CMPLTC
      ALUFN<=`ALU_CMPLT;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b110110: begin //CMPLEC
      ALUFN<=`ALU_CMPLE;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b111000: begin //ANDC
      ALUFN<=`ALU_AND;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b111001: begin //ORC
      ALUFN<=`ALU_OR;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b111010: begin //XORC
      ALUFN<=`ALU_XOR;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    /* 6'b111011: begin //XNORC
      ALUFN<=6'b101001;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end
 */
    6'b111100: begin //SHLC
      ALUFN<=`ALU_SHL;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b111101: begin //SHRC
      ALUFN<=`ALU_SHR;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end

    6'b111110: begin //SRAC
      ALUFN<=`ALU_SRA;
      ASEL<=0;
      BSEL<=1;
      MOE<=0;
      mwr_i<=0;
      pcsel_i<=3'b000;
      RA2SEL<=0;
      wasel_i<=0;
      wdsel_i<=2'b01;
      werf_i<=1;
    end
  default: begin
    ALUFN<=6'b000000;
    ASEL<=0;
    BSEL<=0;
    MOE<=0;
    mwr_i<=0;
    pcsel_i<=3'b011;
    RA2SEL<=0;
    wasel_i<=1;
    wdsel_i<=2'b00;
    werf_i<=1;
  end
  endcase
end
endmodule // CTL