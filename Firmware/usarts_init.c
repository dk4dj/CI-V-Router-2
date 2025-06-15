#include <main.h>

// USARTC0 initialization
void usartc0_init(void)
{
	// Note: The correct PORTC direction for the RxD, TxD and XCK signals
	// is configured in the ports_init function.

	// Transmitter is enabled
	// Set TxD=1
	PORTC.OUTSET=0x08;

	// Communication mode: Asynchronous USART
	// Data bits: 8
	// Stop bits: 1
	// Parity: Disabled
	USARTC0.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

	// Receive complete interrupt: Medium Level
	// Transmit complete interrupt: Disabled
	// Data register empty interrupt: Disabled
	USARTC0.CTRLA=(USARTC0.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_MED_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

	// Required Baud rate: 4800
	// Real Baud Rate: 4800,5 (x1 Mode), Error: 0,0 %
	USARTC0.BAUDCTRLA=0xFD;
	USARTC0.BAUDCTRLB=((0x0D << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

	// Receiver: On
	// Transmitter: On
	// Double transmission speed mode: Off
	// Multi-processor communication mode: Off
	USARTC0.CTRLB=(USARTC0.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm;
}

// Note: RX_BUFFER_SIZE_USARTC0 is #define-d in 'usarts_init.h' with the value 64
char rx_buffer_usartc0[RX_BUFFER_SIZE_USARTC0];

#if RX_BUFFER_SIZE_USARTC0 <= 256
volatile unsigned char rx_wr_index_usartc0=0,rx_rd_index_usartc0=0;
#else
volatile unsigned int rx_wr_index_usartc0=0,rx_rd_index_usartc0=0;
#endif

#if RX_BUFFER_SIZE_USARTC0 < 256
volatile unsigned char rx_counter_usartc0=0;
#else
volatile unsigned int rx_counter_usartc0=0;
#endif

// This flag is set on USARTC0 Receiver buffer overflow
uint8_t rx_buffer_overflow_usartc0=0;

// USARTC0 Receiver interrupt service routine
//interrupt [USARTC0_RXC_vect] void usartc0_rx_isr(void)
ISR(USARTC0_RXC_vect)
{
	unsigned char status;
	char data;

	status=USARTC0.STATUS;
	data=USARTC0.DATA;
	if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
	{
		rx_buffer_usartc0[rx_wr_index_usartc0++]=data;
		#if RX_BUFFER_SIZE_USARTC0 == 256
		// special case for receiver buffer size=256
		if (++rx_counter_usartc0 == 0) rx_buffer_overflow_usartc0=1;
		#else
		if (rx_wr_index_usartc0 == RX_BUFFER_SIZE_USARTC0) rx_wr_index_usartc0=0;
		if (++rx_counter_usartc0 == RX_BUFFER_SIZE_USARTC0)
		{
			rx_counter_usartc0=0;
			rx_buffer_overflow_usartc0=1;
		}
		#endif
	}
}

// Receive a character from USARTC0
//#pragma used+
int getchar_usartc0(void)
{
	char data;

	if (rx_counter_usartc0==0) return -1;
	
	data=rx_buffer_usartc0[rx_rd_index_usartc0++];
	#if RX_BUFFER_SIZE_USARTC0 != 256
	if (rx_rd_index_usartc0 == RX_BUFFER_SIZE_USARTC0) rx_rd_index_usartc0=0;
	#endif
	
	cli(); //#asm("cli")
	--rx_counter_usartc0;
	sei(); //#asm("sei")

	return data;
}
//#pragma used-

// Write a character to the USARTC0 Transmitter
//#pragma used+
void putchar_usartc0(char c)
{
	while ((USARTC0.STATUS & USART_DREIF_bm) == 0);
	USARTC0.DATA=c;
}
//#pragma used-

// USARTC1 initialization
void usartc1_init(void)
{
	// Note: The correct PORTC direction for the RxD, TxD and XCK signals
	// is configured in the ports_init function.

	// Transmitter is enabled
	// Set TxD=1
	PORTC.OUTSET=0x80;

	// Communication mode: Asynchronous USART
	// Data bits: 8
	// Stop bits: 1
	// Parity: Disabled
	USARTC1.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

	// Receive complete interrupt: Medium Level
	// Transmit complete interrupt: Disabled
	// Data register empty interrupt: Disabled
	USARTC1.CTRLA=(USARTC1.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_MED_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

	// Required Baud rate: 4800
	// Real Baud Rate: 4800,5 (x1 Mode), Error: 0,0 %
	USARTC1.BAUDCTRLA=0xFD;
	USARTC1.BAUDCTRLB=((0x0D << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

	// Receiver: On
	// Transmitter: On
	// Double transmission speed mode: Off
	// Multi-processor communication mode: Off
	USARTC1.CTRLB=(USARTC1.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm;
}

// Note: RX_BUFFER_SIZE_USARTC1 is #define-d in 'usarts_init.h' with the value 64
char rx_buffer_usartc1[RX_BUFFER_SIZE_USARTC1];

#if RX_BUFFER_SIZE_USARTC1 <= 256
volatile unsigned char rx_wr_index_usartc1=0,rx_rd_index_usartc1=0;
#else
volatile unsigned int rx_wr_index_usartc1=0,rx_rd_index_usartc1=0;
#endif

#if RX_BUFFER_SIZE_USARTC1 < 256
volatile unsigned char rx_counter_usartc1=0;
#else
volatile unsigned int rx_counter_usartc1=0;
#endif

// This flag is set on USARTC1 Receiver buffer overflow
uint8_t rx_buffer_overflow_usartc1=0;

// USARTC1 Receiver interrupt service routine
//interrupt [USARTC1_RXC_vect] void usartc1_rx_isr(void)
ISR(USARTC1_RXC_vect)
{
	unsigned char status;
	char data;

	status=USARTC1.STATUS;
	data=USARTC1.DATA;
	if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
	{
		rx_buffer_usartc1[rx_wr_index_usartc1++]=data;
		#if RX_BUFFER_SIZE_USARTC1 == 256
		// special case for receiver buffer size=256
		if (++rx_counter_usartc1 == 0) rx_buffer_overflow_usartc1=1;
		#else
		if (rx_wr_index_usartc1 == RX_BUFFER_SIZE_USARTC1) rx_wr_index_usartc1=0;
		if (++rx_counter_usartc1 == RX_BUFFER_SIZE_USARTC1)
		{
			rx_counter_usartc1=0;
			rx_buffer_overflow_usartc1=1;
		}
		#endif
	}
}

// Receive a character from USARTC1
//#pragma used+
int getchar_usartc1(void)
{
	char data;

	if (rx_counter_usartc1==0) return -1;
	data=rx_buffer_usartc1[rx_rd_index_usartc1++];
	#if RX_BUFFER_SIZE_USARTC1 != 256
	if (rx_rd_index_usartc1 == RX_BUFFER_SIZE_USARTC1) rx_rd_index_usartc1=0;
	#endif
	cli(); //#asm("cli")
	--rx_counter_usartc1;
	sei(); //#asm("sei")
	return data;
}
//#pragma used-

// Write a character to the USARTC1 Transmitter
//#pragma used+
void putchar_usartc1(char c)
{
	while ((USARTC1.STATUS & USART_DREIF_bm) == 0);
	USARTC1.DATA=c;
}
//#pragma used-

// USARTD0 initialization
void usartd0_init(void)
{
	// Note: The correct PORTD direction for the RxD, TxD and XCK signals
	// is configured in the ports_init function.

	// Transmitter is enabled
	// Set TxD=1
	PORTD.OUTSET=0x08;

	// Communication mode: Asynchronous USART
	// Data bits: 8
	// Stop bits: 1
	// Parity: Disabled
	USARTD0.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

	// Receive complete interrupt: Medium Level
	// Transmit complete interrupt: Disabled
	// Data register empty interrupt: Disabled
	USARTD0.CTRLA=(USARTD0.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_MED_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

	// Required Baud rate: 4800
	// Real Baud Rate: 4800,5 (x1 Mode), Error: 0,0 %
	USARTD0.BAUDCTRLA=0xFD;
	USARTD0.BAUDCTRLB=((0x0D << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

	// Receiver: On
	// Transmitter: On
	// Double transmission speed mode: Off
	// Multi-processor communication mode: Off
	USARTD0.CTRLB=(USARTD0.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm;
}

// Note: RX_BUFFER_SIZE_USARTD0 is #define-d in 'usarts_init.h' with the value 64
char rx_buffer_usartd0[RX_BUFFER_SIZE_USARTD0];

#if RX_BUFFER_SIZE_USARTD0 <= 256
volatile unsigned char rx_wr_index_usartd0=0,rx_rd_index_usartd0=0;
#else
volatile unsigned int rx_wr_index_usartd0=0,rx_rd_index_usartd0=0;
#endif

#if RX_BUFFER_SIZE_USARTD0 < 256
volatile unsigned char rx_counter_usartd0=0;
#else
volatile unsigned int rx_counter_usartd0=0;
#endif

// This flag is set on USARTD0 Receiver buffer overflow
uint8_t rx_buffer_overflow_usartd0=0;

// USARTD0 Receiver interrupt service routine
//interrupt [USARTD0_RXC_vect] void usartd0_rx_isr(void)
ISR(USARTD0_RXC_vect)
{
	unsigned char status;
	char data;

	status=USARTD0.STATUS;
	data=USARTD0.DATA;
	if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
	{
		rx_buffer_usartd0[rx_wr_index_usartd0++]=data;
		#if RX_BUFFER_SIZE_USARTD0 == 256
		// special case for receiver buffer size=256
		if (++rx_counter_usartd0 == 0) rx_buffer_overflow_usartd0=1;
		#else
		if (rx_wr_index_usartd0 == RX_BUFFER_SIZE_USARTD0) rx_wr_index_usartd0=0;
		if (++rx_counter_usartd0 == RX_BUFFER_SIZE_USARTD0)
		{
			rx_counter_usartd0=0;
			rx_buffer_overflow_usartd0=1;
		}
		#endif
	}
}

// Receive a character from USARTD0
//#pragma used+
int getchar_usartd0(void)
{
	char data;

	if (rx_counter_usartd0==0) return -1;
	data=rx_buffer_usartd0[rx_rd_index_usartd0++];
	#if RX_BUFFER_SIZE_USARTD0 != 256
	if (rx_rd_index_usartd0 == RX_BUFFER_SIZE_USARTD0) rx_rd_index_usartd0=0;
	#endif
	cli(); //#asm("cli")
	--rx_counter_usartd0;
	sei(); //#asm("sei")
	return data;
}
//#pragma used-

// Write a character to the USARTD0 Transmitter
//#pragma used+
void putchar_usartd0(char c)
{
	while ((USARTD0.STATUS & USART_DREIF_bm) == 0);
	USARTD0.DATA=c;
}
//#pragma used-

// USARTD1 initialization
void usartd1_init(void)
{
	// Note: The correct PORTD direction for the RxD, TxD and XCK signals
	// is configured in the ports_init function.

	// Transmitter is enabled
	// Set TxD=1
	PORTD.OUTSET=0x80;

	// Communication mode: Asynchronous USART
	// Data bits: 8
	// Stop bits: 1
	// Parity: Disabled
	USARTD1.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

	// Receive complete interrupt: Medium Level
	// Transmit complete interrupt: Disabled
	// Data register empty interrupt: Disabled
	USARTD1.CTRLA=(USARTD1.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_MED_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

	// Required Baud rate: 4800
	// Real Baud Rate: 4800,5 (x1 Mode), Error: 0,0 %
	USARTD1.BAUDCTRLA=0xFD;
	USARTD1.BAUDCTRLB=((0x0D << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

	// Receiver: On
	// Transmitter: On
	// Double transmission speed mode: Off
	// Multi-processor communication mode: Off
	USARTD1.CTRLB=(USARTD1.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm;
}

// Note: RX_BUFFER_SIZE_USARTD1 is #define-d in 'usarts_init.h' with the value 64
char rx_buffer_usartd1[RX_BUFFER_SIZE_USARTD1];

#if RX_BUFFER_SIZE_USARTD1 <= 256
volatile unsigned char rx_wr_index_usartd1=0,rx_rd_index_usartd1=0;
#else
volatile unsigned int rx_wr_index_usartd1=0,rx_rd_index_usartd1=0;
#endif

#if RX_BUFFER_SIZE_USARTD1 < 256
volatile unsigned char rx_counter_usartd1=0;
#else
volatile unsigned int rx_counter_usartd1=0;
#endif

// This flag is set on USARTD1 Receiver buffer overflow
uint8_t rx_buffer_overflow_usartd1=0;

// USARTD1 Receiver interrupt service routine
//interrupt [USARTD1_RXC_vect] void usartd1_rx_isr(void)
ISR(USARTD1_RXC_vect)
{
	unsigned char status;
	char data;

	status=USARTD1.STATUS;
	data=USARTD1.DATA;
	if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
	{
		rx_buffer_usartd1[rx_wr_index_usartd1++]=data;
		#if RX_BUFFER_SIZE_USARTD1 == 256
		// special case for receiver buffer size=256
		if (++rx_counter_usartd1 == 0) rx_buffer_overflow_usartd1=1;
		#else
		if (rx_wr_index_usartd1 == RX_BUFFER_SIZE_USARTD1) rx_wr_index_usartd1=0;
		if (++rx_counter_usartd1 == RX_BUFFER_SIZE_USARTD1)
		{
			rx_counter_usartd1=0;
			rx_buffer_overflow_usartd1=1;
		}
		#endif
	}
}

// Receive a character from USARTD1
//#pragma used+
int getchar_usartd1(void)
{
	char data;

	if (rx_counter_usartd1==0) return -1;
	data=rx_buffer_usartd1[rx_rd_index_usartd1++];
	#if RX_BUFFER_SIZE_USARTD1 != 256
	if (rx_rd_index_usartd1 == RX_BUFFER_SIZE_USARTD1) rx_rd_index_usartd1=0;
	#endif
	cli(); //#asm("cli")
	--rx_counter_usartd1;
	sei(); //#asm("sei")
	return data;
}
//#pragma used-

// Write a character to the USARTD1 Transmitter
//#pragma used+
void putchar_usartd1(char c)
{
	while ((USARTD1.STATUS & USART_DREIF_bm) == 0);
	USARTD1.DATA=c;
}
//#pragma used-

// USARTE0 initialization
void usarte0_init(void)
{
	// Note: The correct PORTE direction for the RxD, TxD and XCK signals
	// is configured in the ports_init function.

	// Transmitter is enabled
	// Set TxD=1
	PORTE.OUTSET=0x08;

	// Communication mode: Asynchronous USART
	// Data bits: 8
	// Stop bits: 1
	// Parity: Disabled
	USARTE0.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

	// Receive complete interrupt: Medium Level
	// Transmit complete interrupt: Disabled
	// Data register empty interrupt: Disabled
	USARTE0.CTRLA=(USARTE0.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_MED_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

	// Required Baud rate: 4800
	// Real Baud Rate: 4800,5 (x1 Mode), Error: 0,0 %
	USARTE0.BAUDCTRLA=0xFD;
	USARTE0.BAUDCTRLB=((0x0D << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

	// Receiver: On
	// Transmitter: On
	// Double transmission speed mode: Off
	// Multi-processor communication mode: Off
	USARTE0.CTRLB=(USARTE0.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm;
}

// Note: RX_BUFFER_SIZE_USARTE0 is #define-d in 'usarts_init.h' with the value 64
char rx_buffer_usarte0[RX_BUFFER_SIZE_USARTE0];

#if RX_BUFFER_SIZE_USARTE0 <= 256
volatile unsigned char rx_wr_index_usarte0=0,rx_rd_index_usarte0=0;
#else
volatile unsigned int rx_wr_index_usarte0=0,rx_rd_index_usarte0=0;
#endif

#if RX_BUFFER_SIZE_USARTE0 < 256
volatile unsigned char rx_counter_usarte0=0;
#else
volatile unsigned int rx_counter_usarte0=0;
#endif

// This flag is set on USARTE0 Receiver buffer overflow
uint8_t rx_buffer_overflow_usarte0=0;

// USARTE0 Receiver interrupt service routine
//interrupt [USARTE0_RXC_vect] void usarte0_rx_isr(void)
ISR(USARTE0_RXC_vect)
{
	unsigned char status;
	char data;

	status=USARTE0.STATUS;
	data=USARTE0.DATA;
	if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
	{
		rx_buffer_usarte0[rx_wr_index_usarte0++]=data;
		#if RX_BUFFER_SIZE_USARTE0 == 256
		// special case for receiver buffer size=256
		if (++rx_counter_usarte0 == 0) rx_buffer_overflow_usarte0=1;
		#else
		if (rx_wr_index_usarte0 == RX_BUFFER_SIZE_USARTE0) rx_wr_index_usarte0=0;
		if (++rx_counter_usarte0 == RX_BUFFER_SIZE_USARTE0)
		{
			rx_counter_usarte0=0;
			rx_buffer_overflow_usarte0=1;
		}
		#endif
	}
}

// Receive a character from USARTE0
//#pragma used+
int getchar_usarte0(void)
{
	char data;

	if (rx_counter_usarte0==0) return -1;
	data=rx_buffer_usarte0[rx_rd_index_usarte0++];
	#if RX_BUFFER_SIZE_USARTE0 != 256
	if (rx_rd_index_usarte0 == RX_BUFFER_SIZE_USARTE0) rx_rd_index_usarte0=0;
	#endif
	cli(); //#asm("cli")
	--rx_counter_usarte0;
	sei(); //#asm("sei")
	return data;
}
//#pragma used-

// Write a character to the USARTE0 Transmitter
//#pragma used+
void putchar_usarte0(char c)
{
	while ((USARTE0.STATUS & USART_DREIF_bm) == 0);
	USARTE0.DATA=c;
}
//#pragma used-

// USARTE1 initialization
void usarte1_init(void)
{
	// Note: The correct PORTE direction for the RxD, TxD and XCK signals
	// is configured in the ports_init function.

	// Transmitter is enabled
	// Set TxD=1
	PORTE.OUTSET=0x80;

	// Communication mode: Asynchronous USART
	// Data bits: 8
	// Stop bits: 1
	// Parity: Disabled
	USARTE1.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

	// Receive complete interrupt: Medium Level
	// Transmit complete interrupt: Disabled
	// Data register empty interrupt: Disabled
	USARTE1.CTRLA=(USARTE1.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_MED_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

	// Required Baud rate: 4800
	// Real Baud Rate: 4800,5 (x1 Mode), Error: 0,0 %
	USARTE1.BAUDCTRLA=0xFD;
	USARTE1.BAUDCTRLB=((0x0D << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

	// Receiver: On
	// Transmitter: On
	// Double transmission speed mode: Off
	// Multi-processor communication mode: Off
	USARTE1.CTRLB=(USARTE1.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm;
}

// Note: RX_BUFFER_SIZE_USARTE1 is #define-d in 'usarts_init.h' with the value 64
char rx_buffer_usarte1[RX_BUFFER_SIZE_USARTE1];

#if RX_BUFFER_SIZE_USARTE1 <= 256
volatile unsigned char rx_wr_index_usarte1=0,rx_rd_index_usarte1=0;
#else
volatile unsigned int rx_wr_index_usarte1=0,rx_rd_index_usarte1=0;
#endif

#if RX_BUFFER_SIZE_USARTE1 < 256
volatile unsigned char rx_counter_usarte1=0;
#else
volatile unsigned int rx_counter_usarte1=0;
#endif

// This flag is set on USARTE1 Receiver buffer overflow
uint8_t rx_buffer_overflow_usarte1=0;

// USARTE1 Receiver interrupt service routine
//interrupt [USARTE1_RXC_vect] void usarte1_rx_isr(void)
ISR(USARTE1_RXC_vect)
{
	unsigned char status;
	char data;

	status=USARTE1.STATUS;
	data=USARTE1.DATA;
	if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
	{
		rx_buffer_usarte1[rx_wr_index_usarte1++]=data;
		#if RX_BUFFER_SIZE_USARTE1 == 256
		// special case for receiver buffer size=256
		if (++rx_counter_usarte1 == 0) rx_buffer_overflow_usarte1=1;
		#else
		if (rx_wr_index_usarte1 == RX_BUFFER_SIZE_USARTE1) rx_wr_index_usarte1=0;
		if (++rx_counter_usarte1 == RX_BUFFER_SIZE_USARTE1)
		{
			rx_counter_usarte1=0;
			rx_buffer_overflow_usarte1=1;
		}
		#endif
	}
}

// Receive a character from USARTE1
//#pragma used+
int getchar_usarte1(void)
{
	char data;

	if (rx_counter_usarte1==0) return -1;
	data=rx_buffer_usarte1[rx_rd_index_usarte1++];
	#if RX_BUFFER_SIZE_USARTE1 != 256
	if (rx_rd_index_usarte1 == RX_BUFFER_SIZE_USARTE1) rx_rd_index_usarte1=0;
	#endif
	cli(); //#asm("cli")
	--rx_counter_usarte1;
	sei(); //#asm("sei")
	return data;
}
//#pragma used-

// Write a character to the USARTE1 Transmitter
//#pragma used+
void putchar_usarte1(char c)
{
	while ((USARTE1.STATUS & USART_DREIF_bm) == 0);
	USARTE1.DATA=c;
}
//#pragma used-

// USARTF0 initialization
void usartf0_init(void)
{
	// Note: The correct PORTF direction for the RxD, TxD and XCK signals
	// is configured in the ports_init function.

	// Transmitter is enabled
	// Set TxD=1
	PORTF.OUTSET=0x08;

	// Communication mode: Asynchronous USART
	// Data bits: 8
	// Stop bits: 1
	// Parity: Disabled
	USARTF0.CTRLC=USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;

	// Receive complete interrupt: Medium Level
	// Transmit complete interrupt: Disabled
	// Data register empty interrupt: Disabled
	USARTF0.CTRLA=(USARTF0.CTRLA & (~(USART_RXCINTLVL_gm | USART_TXCINTLVL_gm | USART_DREINTLVL_gm))) |
	USART_RXCINTLVL_MED_gc | USART_TXCINTLVL_OFF_gc | USART_DREINTLVL_OFF_gc;

	// Required Baud rate: 4800
	// Real Baud Rate: 4800,5 (x1 Mode), Error: 0,0 %
	USARTF0.BAUDCTRLA=0xFD;
	USARTF0.BAUDCTRLB=((0x0D << USART_BSCALE_gp) & USART_BSCALE_gm) | 0x0C;

	// Receiver: On
	// Transmitter: On
	// Double transmission speed mode: Off
	// Multi-processor communication mode: Off
	USARTF0.CTRLB=(USARTF0.CTRLB & (~(USART_RXEN_bm | USART_TXEN_bm | USART_CLK2X_bm | USART_MPCM_bm | USART_TXB8_bm))) |
	USART_RXEN_bm | USART_TXEN_bm;
}

// Note: RX_BUFFER_SIZE_USARTF0 is #define-d in 'usarts_init.h' with the value 64
char rx_buffer_usartf0[RX_BUFFER_SIZE_USARTF0];

#if RX_BUFFER_SIZE_USARTF0 <= 256
volatile unsigned char rx_wr_index_usartf0=0,rx_rd_index_usartf0=0;
#else
volatile unsigned int rx_wr_index_usartf0=0,rx_rd_index_usartf0=0;
#endif

#if RX_BUFFER_SIZE_USARTF0 < 256
volatile unsigned char rx_counter_usartf0=0;
#else
volatile unsigned int rx_counter_usartf0=0;
#endif

// This flag is set on USARTF0 Receiver buffer overflow
uint8_t rx_buffer_overflow_usartf0=0;

// USARTF0 Receiver interrupt service routine
//interrupt [USARTF0_RXC_vect] void usartf0_rx_isr(void)
ISR(USARTF0_RXC_vect)
{
	unsigned char status;
	char data;

	status=USARTF0.STATUS;
	data=USARTF0.DATA;
	if ((status & (USART_FERR_bm | USART_PERR_bm | USART_BUFOVF_bm)) == 0)
	{
		rx_buffer_usartf0[rx_wr_index_usartf0++]=data;
		#if RX_BUFFER_SIZE_USARTF0 == 256
		// special case for receiver buffer size=256
		if (++rx_counter_usartf0 == 0) rx_buffer_overflow_usartf0=1;
		#else
		if (rx_wr_index_usartf0 == RX_BUFFER_SIZE_USARTF0) rx_wr_index_usartf0=0;
		if (++rx_counter_usartf0 == RX_BUFFER_SIZE_USARTF0)
		{
			rx_counter_usartf0=0;
			rx_buffer_overflow_usartf0=1;
		}
		#endif
	}
}

// Receive a character from USARTF0
//#pragma used+
int getchar_usartf0(void)
{
	char data;

	if (rx_counter_usartf0==0) return -1;
	data=rx_buffer_usartf0[rx_rd_index_usartf0++];
	#if RX_BUFFER_SIZE_USARTF0 != 256
	if (rx_rd_index_usartf0 == RX_BUFFER_SIZE_USARTF0) rx_rd_index_usartf0=0;
	#endif
	cli(); //#asm("cli")
	--rx_counter_usartf0;
	sei(); //#asm("sei")
	return data;
}
//#pragma used-

// Write a character to the USARTF0 Transmitter
//#pragma used+
void putchar_usartf0(char c)
{
	while ((USARTF0.STATUS & USART_DREIF_bm) == 0);
	USARTF0.DATA=c;
}
//#pragma used-

