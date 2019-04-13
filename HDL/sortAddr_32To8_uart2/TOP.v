module TOP(
    	Clk                     ,
    	Rst_n                   ,
		Rx                      ,
    	Tx                      
//		TxData						,
//		TxEn							,
//		RxData						,
//		RxDone						,
//		TxDone						,
//		in_32
	);

/////////////////////////////////////////////////////////////////////////////////////////
input					Clk             ; // Clock
input					Rst_n           ; // Reset
input					Rx              ; // RS232 RX line.
//input [7:0]			TxData			 ; // Data to transmit.
//input [31:0]			in_32				 ;
//input	          	TxEn            ;

output				Tx              ; // RS232 TX line.
//output [7:0]			RxData          ; // Received data
//output          	RxDone          ; // Reception completed. Data is valid.
//output          	TxDone          ; // Trnasmission completed. Data sent.
/////////////////////////////////////////////////////////////////////////////////////////
wire [7:0]			TxData_wire		;
wire					RxDone_wire		;
wire					TxDone_wire		;
wire					TxEn_wire		;
wire [31:0]			D_32_wire		;
wire [7:0]			RxData_wire		;
wire					data_rdy_wire	;
	
wire            	tick				; // Baud rate clock
wire 					RxEn				;
wire [3:0]      	NBits    		;
wire [15:0]    	BaudRate       ; //328; 162 etc... (Read comment in baud rate generator file)
/////////////////////////////////////////////////////////////////////////////////////////
assign 		RxEn = 1'b1			;
assign 		BaudRate = 16'd325; 	//baud rate set to 9600 for the HC-06 bluetooth module. Why 325? (Read comment in baud rate generator file)
assign 		NBits = 4'b1000	;	//We send/receive 8 bits
/////////////////////////////////////////////////////////////////////////////////////////
parameter rf_data 	= 32'd12;
parameter pc_data 	= 32'd13;
parameter Inst_data 	= 32'd14;
parameter Cntl_data 	= 32'd15;
parameter A_data 		= 32'd16;
parameter B_data 		= 32'd17;
parameter Alu_data 	= 32'd18;
parameter dm_data 	= 32'd19;


//Make connections between Rx module and TOP inputs and outputs and the other modules
UART_rs232_rx I_RS232RX(
    	.Clk(Clk)             	,
		.Rst_n(Rst_n)         	,
    	.RxEn(RxEn)           	,
    	.RxData(RxData_wire)   	,
    	.RxDone(RxDone_wire)   	,
    	.Rx(Rx)               	,
    	.Tick(tick)           	,
    	.NBits(NBits)
    );

//Make connections between Tx module and TOP inputs and outputs and the other modules
UART_rs232_tx I_RS232TX(
		.Clk(Clk)            	,
    	.Rst_n(Rst_n)         	,
    	.TxEn(TxEn_wire)       	,
    	.TxData(TxData_wire)    ,
		.TxDone(TxDone_wire)   	,
		.Tx(Tx)               	,
		.Tick(tick)           	,
		.NBits(NBits)
    );

//Make connections between tick generator module and TOP inputs and outputs and the other modules
UART_BaudRate_generator I_BAUDGEN(
    	.Clk(Clk)               ,
    	.Rst_n(Rst_n)           ,
    	.Tick(tick)             ,
    	.BaudRate(BaudRate)
    );

data8and32 I_DATA8AND32(
		.in_32(D_32_wire)			,
		.data_rdy(data_rdy_wire),
		.tx_done(TxDone_wire)	,
		.sys_clk(Clk)				,
		.reset(Rst_n)				,
		.out_8(TxData_wire)		,
		.tx_en(TxEn_wire)
		);

address_multiplexer I_ADDR_MUX(
		.Clk(Clk)					,
		.rx_done(RxDone_wire)	,
		.Reset(Rst_n)				,
		.addr_in_8(RxData_wire)	,
		.data_inst_32(Inst_data),
		.data_pc_32(pc_data)		,
		.data_cntl_32(Cntl_data),
		.data_a_32(A_data)		,
		.data_b_32(B_data)		,
		.data_alu_32(Alu_data)	,
		.data_rf_32(rf_data)		,
		.data_dm_32(dm_data)		,
		.addr_rf_5()				,
		.addr_dm_5()				,
		.data_out_32(D_32_wire)	,
		.data_rdy(data_rdy_wire)
		);
		
endmodule
