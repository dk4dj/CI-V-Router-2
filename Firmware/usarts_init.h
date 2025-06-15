#ifndef _USARTS_INIT_INCLUDED_
#define _USARTS_INIT_INCLUDED_

// USARTC0 receive function
int getchar_usartc0(void);
// USARTC0 transmit function
void putchar_usartc0(char c);
// USARTC0 initialization
void usartc0_init(void);
// USARTC0 Receiver buffer
#define RX_BUFFER_SIZE_USARTC0 64
extern char rx_buffer_usartc0[RX_BUFFER_SIZE_USARTC0];

#if RX_BUFFER_SIZE_USARTC0 <= 256
extern volatile unsigned char rx_wr_index_usartc0,rx_rd_index_usartc0;
#else
extern volatile unsigned int rx_wr_index_usartc0,rx_rd_index_usartc0;
#endif

#if RX_BUFFER_SIZE_USARTC0 < 256
extern volatile unsigned char rx_counter_usartc0;
#else
extern volatile unsigned int rx_counter_usartc0;
#endif

// This flag is set on USARTC0 Receiver buffer overflow
extern uint8_t rx_buffer_overflow_usartc0;
// USARTC1 receive function
int getchar_usartc1(void);
// USARTC1 transmit function
void putchar_usartc1(char c);
// USARTC1 initialization
void usartc1_init(void);
// USARTC1 Receiver buffer
#define RX_BUFFER_SIZE_USARTC1 64
extern char rx_buffer_usartc1[RX_BUFFER_SIZE_USARTC1];

#if RX_BUFFER_SIZE_USARTC1 <= 256
extern volatile unsigned char rx_wr_index_usartc1,rx_rd_index_usartc1;
#else
extern volatile unsigned int rx_wr_index_usartc1,rx_rd_index_usartc1;
#endif

#if RX_BUFFER_SIZE_USARTC1 < 256
extern volatile unsigned char rx_counter_usartc1;
#else
extern volatile unsigned int rx_counter_usartc1;
#endif

// This flag is set on USARTC1 Receiver buffer overflow
extern uint8_t rx_buffer_overflow_usartc1;
// USARTD0 receive function
int getchar_usartd0(void);
// USARTD0 transmit function
void putchar_usartd0(char c);
// USARTD0 initialization
void usartd0_init(void);
// USARTD0 Receiver buffer
#define RX_BUFFER_SIZE_USARTD0 64
extern char rx_buffer_usartd0[RX_BUFFER_SIZE_USARTD0];

#if RX_BUFFER_SIZE_USARTD0 <= 256
extern volatile unsigned char rx_wr_index_usartd0,rx_rd_index_usartd0;
#else
extern volatile unsigned int rx_wr_index_usartd0,rx_rd_index_usartd0;
#endif

#if RX_BUFFER_SIZE_USARTD0 < 256
extern volatile unsigned char rx_counter_usartd0;
#else
extern volatile unsigned int rx_counter_usartd0;
#endif

// This flag is set on USARTD0 Receiver buffer overflow
extern uint8_t rx_buffer_overflow_usartd0;
// USARTD1 receive function
int getchar_usartd1(void);
// USARTD1 transmit function
void putchar_usartd1(char c);
// USARTD1 initialization
void usartd1_init(void);
// USARTD1 Receiver buffer
#define RX_BUFFER_SIZE_USARTD1 64
extern char rx_buffer_usartd1[RX_BUFFER_SIZE_USARTD1];

#if RX_BUFFER_SIZE_USARTD1 <= 256
extern volatile unsigned char rx_wr_index_usartd1,rx_rd_index_usartd1;
#else
extern volatile unsigned int rx_wr_index_usartd1,rx_rd_index_usartd1;
#endif

#if RX_BUFFER_SIZE_USARTD1 < 256
extern volatile unsigned char rx_counter_usartd1;
#else
extern volatile unsigned int rx_counter_usartd1;
#endif

// This flag is set on USARTD1 Receiver buffer overflow
extern uint8_t rx_buffer_overflow_usartd1;
// USARTE0 receive function
int getchar_usarte0(void);
// USARTE0 transmit function
void putchar_usarte0(char c);
// USARTE0 initialization
void usarte0_init(void);
// USARTE0 Receiver buffer
#define RX_BUFFER_SIZE_USARTE0 64
extern char rx_buffer_usarte0[RX_BUFFER_SIZE_USARTE0];

#if RX_BUFFER_SIZE_USARTE0 <= 256
extern volatile unsigned char rx_wr_index_usarte0,rx_rd_index_usarte0;
#else
extern volatile unsigned int rx_wr_index_usarte0,rx_rd_index_usarte0;
#endif

#if RX_BUFFER_SIZE_USARTE0 < 256
extern volatile unsigned char rx_counter_usarte0;
#else
extern volatile unsigned int rx_counter_usarte0;
#endif

// This flag is set on USARTE0 Receiver buffer overflow
extern uint8_t rx_buffer_overflow_usarte0;
// USARTE1 receive function
int getchar_usarte1(void);
// USARTE1 transmit function
void putchar_usarte1(char c);
// USARTE1 initialization
void usarte1_init(void);
// USARTE1 Receiver buffer
#define RX_BUFFER_SIZE_USARTE1 64
extern char rx_buffer_usarte1[RX_BUFFER_SIZE_USARTE1];

#if RX_BUFFER_SIZE_USARTE1 <= 256
extern volatile unsigned char rx_wr_index_usarte1,rx_rd_index_usarte1;
#else
extern volatile unsigned int rx_wr_index_usarte1,rx_rd_index_usarte1;
#endif

#if RX_BUFFER_SIZE_USARTE1 < 256
extern volatile unsigned char rx_counter_usarte1;
#else
extern volatile unsigned int rx_counter_usarte1;
#endif

// This flag is set on USARTE1 Receiver buffer overflow
extern uint8_t rx_buffer_overflow_usarte1;
// USARTF0 receive function
int getchar_usartf0(void);
// USARTF0 transmit function
void putchar_usartf0(char c);
// USARTF0 initialization
void usartf0_init(void);
// USARTF0 Receiver buffer
#define RX_BUFFER_SIZE_USARTF0 64
extern char rx_buffer_usartf0[RX_BUFFER_SIZE_USARTF0];

#if RX_BUFFER_SIZE_USARTF0 <= 256
extern volatile unsigned char rx_wr_index_usartf0,rx_rd_index_usartf0;
#else
extern volatile unsigned int rx_wr_index_usartf0,rx_rd_index_usartf0;
#endif

#if RX_BUFFER_SIZE_USARTF0 < 256
extern volatile unsigned char rx_counter_usartf0;
#else
extern volatile unsigned int rx_counter_usartf0;
#endif

// This flag is set on USARTF0 Receiver buffer overflow
extern uint8_t rx_buffer_overflow_usartf0;

#endif
