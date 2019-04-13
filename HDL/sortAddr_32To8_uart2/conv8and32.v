
module data8and32(
		input [31:0] in_32 ,
		input data_rdy,
		input tx_done,
		input sys_clk,
		input reset,
		output reg [7:0] out_8,
		output reg tx_en
		);

	parameter tx_state1 = 3'b001;
   parameter tx_state2 = 3'b010;
   parameter tx_state3 = 3'b011;
   parameter tx_state4 = 3'b100;
	
	parameter N = 8'b11111111;
	reg [7:0] cnt = 0;	// count 16 pulses for making tx_en low
	reg [2:0] tx_state = tx_state1;
	reg sent = 0;
	reg tx_en1;
	reg tx_en2;

	// Sends 32 bit data in chunks of 8 bits (from msb to lsb), while waiting till tx_done for every 8 bits.
   always@(posedge tx_done or posedge data_rdy or negedge reset)
	begin
		if(reset == 0)
		begin
			tx_en1 <= 0;
			out_8 <= 0;
			sent <= 1;
			tx_state <= tx_state2;
			cnt <= 0;
		end
      else if (data_rdy == 1) 
		begin
			tx_state <= tx_state2;
			out_8 <= in_32[31:24];
			tx_en1 <= 1;
			sent <= 0;
		end
      else if(sent == 0)
		begin
         case (tx_state)
				tx_state1 : begin
									tx_state <= tx_state2;
									sent <= 1;
								end
				tx_state2 : begin
									tx_state <= tx_state3;
									out_8 <= in_32[23:16];
								end
            tx_state3 :	begin
									tx_state <= tx_state4;
									out_8 <= in_32[15:8];
								end
            tx_state4 : begin
									tx_state <= tx_state1;
									out_8 <= in_32[7:0];
								end
         endcase
		end
	end

	// generate tx_en pulse
	always@(sys_clk or negedge tx_done)
	begin
		if(tx_done == 0 && sent == 0)
			tx_en2 <= 1;
		else if(tx_en == 1)
		begin
			if(cnt == N)
				tx_en2 <= 0;
			cnt <= cnt + 1;
		end
	end
	
	always
	begin
		tx_en <= tx_en2 && tx_en1;
	end
endmodule
