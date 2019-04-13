module TOP(
    	Clk                     ,
    	Rst_n                   ,
		Rx                      ,
//		TxData						,
//		TxEn							,
    	Tx                      ,
		RxData						,
		RxDone						,
		TxDone						,
		leda,
		ledb,
		ledc,
		ledd,
		lede,
		ledf,
		ledg,
		button_in
	);

/////////////////////////////////////////////////////////////////////////////////////////
input   button_in;        // inputs
		
input					Clk             ; // Clock
input					Rst_n           ; // Reset
input					Rx              ; // RS232 RX line.
//input [7:0]			TxData			 ; // Data to transmit.
//input          	TxEn            ;
output				Tx              ; // RS232 TX line.
output [7:0]		RxData          ; // Received data
output          	RxDone          ; // Reception completed. Data is valid.
output          	TxDone          ; // Trnasmission completed. Data sent.

output 				leda;
output 				ledb;
output 				ledc;
output 				ledd;
output 				lede;
output 				ledf;
output 				ledg;
/////////////////////////////////////////////////////////////////////////////////////////
wire            tick		; // Baud rate clock
wire 			RxEn		;
wire [3:0]      NBits    	;
wire [15:0]    	BaudRate        ; //328; 162 etc... (Read comment in baud rate generator file)
wire [7:0] 	TxDataWire;
wire 			TxEn_wire	;
/////////////////////////////////////////////////////////////////////////////////////////
assign 		RxEn = 1'b1	;
assign 		BaudRate = 16'd651;//325; 	//baud rate set to 9600 for the HC-06 bluetooth module. Why 325? (Read comment in baud rate generator file)
assign 		NBits = 4'b1000	;	//We send/receive 8 bits
/////////////////////////////////////////////////////////////////////////////////////////


//Make connections between Rx module and TOP inputs and outputs and the other modules
UART_rs232_rx I_RS232RX(
    	.Clk(Clk)             	,
		.Rst_n(Rst_n)         	,
    	.RxEn(RxEn)           	,
    	.RxData(RxData)       	,
    	.RxDone(RxDone)       	,
    	.Rx(Rx)               	,
    	.Tick(tick)           	,
    	.NBits(NBits)
    );

//Make connections between Tx module and TOP inputs and outputs and the other modules
UART_rs232_tx I_RS232TX(
		.Clk(Clk)            	,
    	.Rst_n(Rst_n)         	,
    	.TxEn(TxEn_wire)       	,
    	.TxData(TxDataWire)     ,
		.TxDone(TxDone)      	,
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

counterdisplay I_COUNTDISP(
		.clk(Clk),
		.n_reset(Rst_n),
		.button_in(button_in),	       // inputs
		.leda(leda),
		.ledb(ledb),
		.ledc(ledc),
		.ledd(ledd),
		.lede(lede),
		.ledf(ledf),
		.ledg(ledg),
		.tx_en(TxEn_wire),
		.data_out(TxDataWire)
		);

endmodule
