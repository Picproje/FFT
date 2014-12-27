#include "radix2_fft.h"
#include "twiddle_factor.h"


int Real[N],Imag[N];
int Amp[N];

int i,j,k,n1,n2,Index=0;
int TempReal,TempImag;        
long TwiddleReal,TwiddleImag; 

long k1,k2,k3;

void Radix2Fft(void)
{
          
	j = 0;  /*bit-reverse */
	n2 = N/2;
	for (i=1; i<(N-1); i++)
	{
	  n1 = n2;
	  while ( j >= n1 )
	   {
	    j = j - n1;
	    n1 = n1/2;
	   }
	  j = j + n1;
	               
	  if (i < j)
	   {
	    TempReal = Real[i];
	    Real[i] = Real[j];
	    Real[j] = TempReal;
	    TempImag = Imag[i];
	    Imag[i] = Imag[j];
	    Imag[j] = TempImag;
	   }
	}
	                                       	 
                                       
	n1 = 0; /* FFT */
	n2 = 1;
	                                             
	for (i=0; i < Log2N; i++)
	{
		n1 = n2;
		n2 = n2 + n2;
	                                             
		for (j=0; j < n1; j++)
		{
		
			//TwiddleReal = (long)(128*cos(2*pi*j/n2));
			//TwiddleImag = (long)(128*(-sin(2*pi*j/n2)));
			
			TwiddleReal=CosTable[Index];
			TwiddleImag =SinTable[Index];
           	Index++;
		                                            
			for (k=j; k < N; k=k+n2)
			{	

				TempReal = ((TwiddleReal*Real[k+n1]) - (TwiddleImag*Imag[k+n1]))>>7;
			   	TempImag = ((TwiddleImag*Real[k+n1]) + (TwiddleReal*Imag[k+n1]))>>7;

			    Real[k+n1] = (Real[k] - TempReal);
			    Imag[k+n1] = (Imag[k] - TempImag);
			    Real[k] = (Real[k] + TempReal);
			    Imag[k] = (Imag[k] + TempImag);
			 }
		}
	}	                                     
	return;
}  