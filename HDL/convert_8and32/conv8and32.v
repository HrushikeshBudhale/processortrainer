
module data8and32(
		input [31:0] in_32 ,
		input rx_done,
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
	parameter tx_state5 = 3'b101;
	
	parameter N = 8'b11111111;
	reg [7:0] cnt = 0;	// count 16 pulses for making tx_en low
	reg [2:0] tx_state = tx_state1;
	reg sent = 0;
	
	initial
	begin
		tx_en = 0;
		out_8 = 0;
	end
	// Sends 32 bit data in chunks of 8 bits (from msb to lsb), while waiting till tx_done for every 8 bits.
   always@(posedge tx_done or posedge rx_done)
	begin
      if (reset == 0) 
		begin
			tx_state <= tx_state1;
			tx_en <= 0;
			sent <= 0;
		end
      else if(sent == 0)
		begin
         case (tx_state)
            tx_state1 : begin
									tx_state <= tx_state2;
									out_8 <= in_32[31:24];
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
									tx_state <= tx_state5;
									out_8 <= in_32[7:0];
								end
				tx_state5 : begin
									tx_state <= tx_state1;
									sent <= 1;
								end
         endcase
		end
	end
	
	// generate tx_en pulse
	always@(sys_clk)
	begin
		if(tx_en == 1)
		begin
			if(cnt == N)
				tx_en <= 0;
			cnt <= cnt + 1;
		end
	end
	
	always@(negedge tx_done or posedge rx_done)
	begin
		if(sent == 0)
			tx_en <= 1;
	end
endmodule
