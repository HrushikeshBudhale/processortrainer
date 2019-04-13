module address_multiplexer(
		input 				Clk							,
		input					rx_done						,
		input 				Reset							,
		input [7:0] 		addr_in_8             	,
		input [31:0] 		data_inst_32          	,
		input [31:0] 		data_pc_32		        	,
		input [31:0] 		data_cntl_32				,
		input [31:0] 		data_a_32					,
		input [31:0] 		data_b_32					,
		input [31:0] 		data_alu_32					,
		input [31:0] 		data_rf_32					,
		input [31:0] 		data_dm_32					,
		output reg [4:0] 	addr_rf_5					,
		output reg [4:0] 	addr_dm_5					,
		output reg [31:0] data_out_32					,
		output reg			data_rdy
		);
	
	parameter N = 3'b111;
	reg [2:0] wait_cnt = 0;	// count 2^N pulses for making en low
	reg read_wait;


//	The 8 bit address ranges are as follows:
//
//	000 00000	|
//		  |||		|	Register file
//	000 11111	|
//
//	001 -----	|	Program Counter
//	010 -----	|	Instruction
//	011 -----	|	Control Signals
//	100 -----	|	Input A to ALU
//	101 -----	|	Input B to ALU
//	110 -----	|	Output from ALU
//
//	111 00000	|
//		  |||		|	Data Memory
//	111 00000	|


	always@(posedge Reset)
	begin
		addr_rf_5 <= 0;
		addr_dm_5 <= 0;
		data_out_32 <= 0;
		read_wait <= 0;
		data_rdy <= 0;
	end
	
	always @(negedge rx_done)
	begin
		case(addr_in_8[7:5])
			3'b000 : begin	// Register file
							addr_rf_5 <= addr_in_8[4:0];	// Set rf address to display
							read_wait <= 1;
						end
			3'b001 : begin	// Program Counter
							data_out_32 <= data_pc_32;
							data_rdy <= 1;
						end
			3'b010 : begin	// Instruction
							data_out_32 <= data_inst_32;
							data_rdy <= 1;
						end
			3'b011 : begin	// Control Signals
							data_out_32 <= data_cntl_32;
							data_rdy <= 1;
						end
			3'b100 : begin	// Input A to ALU
							data_out_32 <= data_a_32;
							data_rdy <= 1;
						end
			3'b101 : begin	// Input B to ALU
							data_out_32 <= data_b_32;
							data_rdy <= 1;
						end
			3'b110 : begin	// Output from ALU
							data_out_32 <= data_alu_32;
							data_rdy <= 1;
						end
			3'b111 : begin	// Data Memory
							addr_dm_5 <= addr_in_8[4:0];	// Set dm address to display
							read_wait <= 1;
						end
		endcase
	end
	
	// Generate en pulse for memory read operation
	always@(Clk)
	begin
		if(read_wait == 1)
		begin
			if(wait_cnt == N)
			begin
				if(addr_in_8[7:5] ==3'b000)
					data_out_32 <= data_rf_32;		// set data
				else if(addr_in_8[7:5] ==3'b111)
					data_out_32 <= data_dm_32;		// set data
				read_wait <= 0;
				data_rdy <= 1;
			end
			wait_cnt <= wait_cnt + 1;
		end
	end	
	
	// Generate data_rdy pulse for transmit operation
	always@(Clk)
	begin
		if(data_rdy == 1)
		begin
			if(wait_cnt == N)
				data_rdy <= 0;
			wait_cnt <= wait_cnt + 1;
		end
	end
	
endmodule
