#ifndef _SERIAL_H_
#define _SERIAL_H_

#define BAUD 19200  
#define HIGH_SPEED 1   
#define NINE 0     /* Use 9bit communication? FALSE=8bit */



#if NINE == 1
#define NINE_BITS 0x40
#else
#define NINE_BITS 0
#endif

#if HIGH_SPEED == 1
	#define DIVIDER ((int)(_XTAL_FREQ/(16UL * BAUD) -1))

	#define SPEED 0x4 // BRGH bitini 1 yap
#else
	#define DIVIDER ((int)(_XTAL_FREQ/(64UL * BAUD) -1))

	#define SPEED 0  // BRGH bitini 0 yap
#endif



#warning universal_delah.h - Doðru pinlerin seçildiðinden emin olun.

#if	defined(__PICC18__)

	#define RX_PIN TRISC7
	#define TX_PIN TRISC6
#else

#if defined(_16F87) || defined(_16F88)
	#define RX_PIN TRISB2
	#define TX_PIN TRISB5
#else
	#define RX_PIN TRISC7
	#define TX_PIN TRISC6
#endif
#endif

/* Serial initialization */
#define init_comms()\
	RX_PIN = 1;	\
	TX_PIN = 1;		  \
	SPBRG = DIVIDER;     	\
	RCSTA = (NINE_BITS|0x90);	\
	TXSTA = (SPEED|NINE_BITS|0x20)

void putch(unsigned char);
unsigned char getch(void);
unsigned char getche(void);

#endif
