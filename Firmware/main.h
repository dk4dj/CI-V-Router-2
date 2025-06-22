#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 32000000UL
#include <util/delay.h>
#include <string.h>
#include "clock_init.h"
#include "ports_init.h"
#include "usarts_init.h"
#include "timers_init.h"

typedef unsigned char uint8_t;

void civ_tx(uint8_t data, uint8_t serIF);
void led_rx(uint8_t civ);
void led_tx(uint8_t civ);
void handle_leds();
void read_civ();
void send_fifo();
void FrameIntoFifo(uint8_t *data, uint8_t len);
uint8_t GetFrameFromFifo(uint8_t *data);
void rs232_leds();
void init_tx();
void handle_routing_lifetime();
void einschaltblinken();

extern uint8_t civ_adr[7];

enum _CIVIF_ {
	CIV1 = 0,
	CIV2,
	CIV3,
	CIV4,
	CIV5,
	CIV6,
	CIV7,
	RS232
};

#define ON 1
#define OFF 0

//#define LEDONTIME_RD   2  // in 10ms
//#define LEDONTIME_GN   4  // in 10ms

#define LEDONTIME_RD   100  // in 10ms
#define LEDONTIME_GN   100   // in 10ms

#define RXBUFLEN    64
#define ROUTERID    0x55
#define LIFETIME    20      // Lifetime des Routingtab Eintrags in Sekunden

// FIFO
#define MAXDATA 30      // max. Datenlaenge im Buffer (max Framelen = MAXDATA+3)
#define FRAMELEN MAXDATA+3
#define FRAMEBUFANZ 40 // max. Anzahl von Frames im Buffer
