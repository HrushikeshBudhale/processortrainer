module  counterdisplay 
    (
		input   clk, n_reset, button_in,        // inputs
		output leda,
		output ledb,
		output ledc,
		output ledd,
		output lede,
		output ledf,
		output ledg,
		output reg tx_en,
		output reg [7:0] data_out
	);
	
	reg DB_out;
	reg [3:0] counter;
	reg [6:0] seg_data;
	reg [3:0] counter_reg;
	
    /*
    Parameter N defines the debounce time. Assuming 50 KHz clock,
    the debounce time is 2^(11-1)/ 50 KHz = 20 ms
      
    For 50 MHz clock increase value of N accordingly to 21.
      
    */
    parameter N =11;//11 ;      

    reg  [N-1 : 0]  delaycount_reg;                     
    reg  [N-1 : 0]  delaycount_next;

    reg DFF1, DFF2;                                 
    wire q_add;                                     
    wire q_reset;

	reg  delay_reg ; // Registers for detecting level change of DB_out
	wire level_out;

	always @ ( posedge clk or negedge n_reset )
	begin
		if(n_reset ==  0) // At reset initialize FF and counter 
			begin
				DFF1 <= 1'b0;
				DFF2 <= 1'b0;
				// For level change detection
				delay_reg  <=  1'b0;

				delaycount_reg <= { N {1'b0} };
			end
		else
			begin
				DFF1 <= button_in;
				DFF2 <= DFF1;
				delaycount_reg <= delaycount_next;
					 
				 
				 
				delay_reg  <=  DB_out;// to detect level change
			end
	end
  
    assign q_reset = (DFF1  ^ DFF2); // Ex OR button_in on conecutive clocks
                                       
    assign  q_add = ~(delaycount_reg[N-1]); // Check count using MSB of counter         
  
    always @ ( q_reset, q_add, delaycount_reg)
        begin
            case( {q_reset , q_add})
                2'b00 :
                        delaycount_next <= delaycount_reg;
                2'b01 :
                        delaycount_next <= delaycount_reg + 1;
                default :
                // In this case q_reset = 1 => change in level. Reset the counter 
                        delaycount_next <= { N {1'b0} };
            endcase   
        end
  
    always @ ( posedge clk )
        begin
            if(delaycount_reg[N-1] == 1'b1)
					DB_out <= DFF2;
				else
					DB_out <= DB_out;
        end
          
	
	assign  level_out  =  (delay_reg)  &  (~DB_out);     
    
	always @(posedge  clk )
	begin

		if (DFF1 == 1)
			tx_en <=1;
		else
			tx_en <=0;
		
		
		if ( n_reset == 0)
			counter <= 0;
	
		else if ( level_out == 1'b1)
		begin
			if (counter  < 9)
				counter <= counter +1;
			else 
				counter <= 0;
		end
	end
	
	always @(counter)
	case (counter)
		4'b0000:begin
				seg_data=7'b1111110;
				data_out="0";
				end
		4'b0001:begin
				seg_data=7'b0110000;
				data_out="1";
				end
		4'b0010:begin
				seg_data=7'b1101101;
				data_out="2";
				end
		4'b0011:begin
				seg_data=7'b1111001;
				data_out="3";
				end
		4'b0100:begin
				seg_data=7'b0110011;
				data_out="4";
				end
		4'b0101:begin
				seg_data=7'b1011011;
				data_out="5";
				end
		4'b0110:begin
				seg_data=7'b1011111;
				data_out="6";
				end
		4'b0111:begin
				seg_data=7'b1110000;
				data_out="7";
				end
		4'b1000:begin
				seg_data=7'b1111111;
				data_out="8";
				end
		4'b1001:begin
				seg_data=7'b1111011;
				data_out="9";
				end
		default:begin
				seg_data=7'b1111110;
				data_out="0";
				end
	endcase
	  
	assign leda=seg_data[6];
	assign ledb=seg_data[5];
	assign ledc=seg_data[4];
	assign ledd=seg_data[3];
	assign lede=seg_data[2];
	assign ledf=seg_data[1];
	assign ledg=seg_data[0];
	
endmodule
