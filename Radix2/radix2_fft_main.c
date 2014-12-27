#include <htc.h>
__CONFIG(1, IESODIS & FCMDIS & HS);    
__CONFIG(2, BORDIS & PWRTEN & WDTDIS); 
__CONFIG(3, MCLRDIS & LPT1DIS & PBDIGITAL & CCP2RC1);
__CONFIG(4, XINSTDIS & DEBUGDIS & LVPDIS & STVREN);
__CONFIG(5, UNPROTECT);
__CONFIG(6, WRTEN);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "delay.c"
#include "universal_usart.c"
#include "radix2_fft.c"


#define pi  3.14159265

#define Fm 50			//Ana harmonik 50Hz
#define Fs (N*Fm)		//örnekleme frekansý
#define Fg 100			//giriþ iþaretinin frekansý
#include "bit_reversal.c"




                 
void main( void )
{	TRISD0=0;
	RD0=1;
	init_comms();
	int asd;
	int asd1;

	for(int i=0;i<N;i++)
	{
		Real[i]=(int)(128*sin(2*pi*(float)i*((float)Fg/Fs)));	//istenilen frekansta giriþ iþaretini örnekle
		Imag[i]=0;									//imajiner kýsým 0 olacak.
	
	}
		
	TRISD0=0;
	RD0=0; 
	Radix2Fft();
	RD0=1;
	
	
	for(int i=0;i<N;i++)
	{
		Amp[i]=(int)abs(Imag[i]/(N/2))+abs(Real[i]/(N/2)); //Harmonik katsayýlarýný hesapla
		printf("%d\n\r",Amp[i]);
	}
	
	


for(;;);	
}//






















