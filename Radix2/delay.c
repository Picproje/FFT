//Delay Rutini V1.1
//// >Mihri<

#include "htc.h"
#include "delay.h"
/* HI-TECH PICC compiler */
	#if (_XTAL_FREQ == 4000000)
		#define dly1u _delay(1)
		#define dly2u _delay(2)
	#elif (_XTAL_FREQ == 8000000)
		#define dly1u _delay(2)
		#define dly2u _delay(4)
	#elif (_XTAL_FREQ == 10000000)
		#define dly1u _delay(2)
		#define dly2u _delay(5)	
	#elif (_XTAL_FREQ == 16000000)
		#define dly1u _delay(4)
		#define dly2u _delay(8)
	#elif (_XTAL_FREQ == 20000000)
		#define dly1u _delay(5)
		#define dly2u _delay(10)
	#elif (_XTAL_FREQ == 32000000)
		#define dly1u _delay(8)
		#define dly2u _delay(16)
	#elif (_XTAL_FREQ == 40000000)
		#define dly1u _delay(10);
		#define dly2u _delay(20);
	#else
		#error delay.c - please define _XTAL_FREQ correctly
	#endif

#if	defined(__PICC__)

	#define DelayMs __delay_ms
	#define DelayUs __delay_us

#endif

/* HI-TECH PICC-18 compiler */

#if	defined(__PICC18__)

	
	#if _XTAL_FREQ == 4000000
		#define DelayUs(x) _delay(x)
	#elif _XTAL_FREQ == 8000000
		#define DelayUs(x) _delay(x); _delay(x)
	#elif _XTAL_FREQ == 10000000
		#define DelayUs(x) _delay(x);_delay(x);_delay(x/2)
	#elif _XTAL_FREQ == 16000000
		#define DelayUs(x) _delay(x);_delay(x);_delay(x);_delay(x)
	#elif _XTAL_FREQ == 20000000
		#define DelayUs(x) _delay(x);_delay(x);_delay(x);_delay(x);_delay(x)
	#elif _XTAL_FREQ == 32000000
		#define DelayUs(x) _delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x)
	#elif _XTAL_FREQ == 40000000
		#define DelayUs(x)  _delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x);_delay(x)
	#else
		#error delay.c - please define _XTAL_FREQ correctly
	#endif

	
	void DelayMs(unsigned char cnt)
	{
		unsigned char	i;
		do {
			i = 4;
			do {
				DelayUs(250);
				#if	defined(DelayClrWdt)
					CLRWDT();
				#endif
			} while(--i);
		} while(--cnt);
	}

#endif
