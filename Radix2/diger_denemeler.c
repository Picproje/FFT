void fft(void)
{
	
	int i,j,k,n1,n2;
	int TempReal,TempImag;        
	long TwiddleReal,TwiddleImag;         
	  

	                                       	 
	                                           
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
			
			TwiddleReal=CosTable[xx1];
			TwiddleImag =SinTable[xx1];
			
			printf("%+4d",(int)TwiddleReal);
           	if (xx1<(N-1))     printf(",");
           	if ((xx1+1)%16 == 0) printf("\n\r");
           	xx1++;
		                                            

		}
	}
	                                     
	return;
}  




void fft1(void)
{
	int NumOfProblems=1;
	int ProblemSize=N;
	int HalfSize;
	int K;
	int JFirst;
	int JLast;
	int JTwiddle;
	int TempReal;
	int TempImag;
	int TwiddleReal;
	int TwiddleImag;
	int J;
	
	while(ProblemSize>1)
	{
		HalfSize=ProblemSize/2;
		for(K=0;K<(NumOfProblems-1);K++)
		{
			JFirst=K*ProblemSize;
			JLast=JFirst+HalfSize-1;
			JTwiddle=0;
			for(J=JFirst;J<JLast;J++)
			{
				TwiddleReal=(int)(cos(2*pi*(double)JTwiddle/N)*32);
				TwiddleImag=(int)(-sin(2*pi*(double)JTwiddle/N)*32);
				TempReal=Real[J];
				TempImag=Imag[J];
				Real[J]=TempReal+Real[J+HalfSize];
				Imag[J]=TempImag+Imag[J+HalfSize];
				Real[J+HalfSize]=(long)TwiddleReal*(TempReal-Real[J+HalfSize])/32-(long)TwiddleImag*(TempImag-Imag[J+HalfSize])/32;
				Imag[J+HalfSize]=(long)TwiddleReal*(TempImag-Imag[J+HalfSize])/32+(long)TwiddleImag*(TempReal-Real[J+HalfSize])/32;
				JTwiddle=JTwiddle+NumOfProblems;
			}
		}
		NumOfProblems=2*NumOfProblems;
		ProblemSize=HalfSize;
	}
}


void fft2(void)
{
	int NumOfProblem=1;
	int ProblemSize=N;
	int Distance=1;
	
	
	int i,j,k,n1,n2;
	int TempReal,TempImag;        
	long TwiddleReal,TwiddleImag;         
	  
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
	
	
	
	while(ProblemSize>1)
	{
		for(int JFirst=0;JFirst<(NumOfProblem-1);JFirst++)
		{
			int J=JFirst, JTwiddle=0;
			while(J<((int)N-1))
			{
				char rev;
				BitReversal(rev,JTwiddle);
				int WReal=(int)(32*cos(2*pi*(double)rev/N));
				int WImag=(int)(-32*sin(2*pi*(double)rev/N));
				TempReal=Real[J];
				TempImag=Imag[J];
				
				Real[J]=TempReal+Real[J+Distance];
				Imag[J]=TempImag+Imag[J+Distance];
				Real[J+Distance]=((long)(TempReal-Real[J+Distance])*WReal)/32-((long)(TempImag-Imag[J+Distance])*WImag)/32;
				Imag[J+Distance]=((long)(TempImag-Imag[J+Distance])*WReal)/32+((long)(TempReal-Real[J+Distance])*WImag)/32;
				JTwiddle+=1;
				J+=2*NumOfProblem;
			}
		}
		NumOfProblem*=2;
		ProblemSize/=2;
		Distance*=2;
	}
}
