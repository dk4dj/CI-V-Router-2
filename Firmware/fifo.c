#include <main.h>

typedef struct {
	uint8_t datalen;
	uint8_t dest;
	uint8_t src;
	uint8_t data[MAXDATA];
} FRAME;

FRAME framebuf[FRAMEBUFANZ];
uint8_t wridx = 0;
uint8_t rdidx = 0;

void FrameIntoFifo(uint8_t *data, uint8_t len)
{
	// ein CIV Frame ist immer mindestens 3 Byte lang
	if(len < 3) return;
	
	// zu lang ?
	if(len >= FRAMELEN) return;
	
	// prüfe ob im Fifo noch Platz ist
	if(((wridx+1) % FRAMEBUFANZ) == rdidx)
	return;
	
	// schreibe Daten in den Fifo
	framebuf[wridx].dest = data[0];
	framebuf[wridx].src = data[1];
	framebuf[wridx].datalen = len-2;
	memcpy(framebuf[wridx].data,data+2,len-2);
	
	// Schreibzeiger weiterstellen
	if(++wridx == FRAMEBUFANZ) wridx = 0;
}

uint8_t GetFrameFromFifo(uint8_t *data)
{
	uint8_t len;

	// ist was im Fifo drin ?
	if(rdidx == wridx)
	return 0;   // Fifo ist leer
	
	// lese Daten
	data[0] = framebuf[rdidx].dest;
	data[1] = framebuf[rdidx].src;
	len = framebuf[rdidx].datalen;
	if(len >= FRAMELEN) return 0;
	
	memcpy(data+2,framebuf[rdidx].data,len);
	
	// stelle Lesezeiger weiter
	if(++rdidx == FRAMEBUFANZ) rdidx = 0;
	
	return len+2;
}
