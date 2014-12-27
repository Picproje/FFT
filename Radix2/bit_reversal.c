#define BitTest(var,mask) ((var & (1<<mask)) != 0)
#define BitSetTo(var,num,bit_val) (bit_val>0)?(var |= (1<<num)):(var &= ~(1<<num))
//
#if	N==256

	#define BitReversal(rev,byte){\
		BitSetTo(rev,0,BitTest(byte,7));\
		BitSetTo(rev,1,BitTest(byte,6));\
		BitSetTo(rev,2,BitTest(byte,5));\
		BitSetTo(rev,3,BitTest(byte,4));\
		BitSetTo(rev,4,BitTest(byte,3));\
		BitSetTo(rev,5,BitTest(byte,2));\
		BitSetTo(rev,6,BitTest(byte,1));\
		BitSetTo(rev,7,BitTest(byte,0));\
	}
		
#elif	N==128

	#define BitReversal(rev,byte){\
		BitSetTo(rev,0,BitTest(byte,6));\
		BitSetTo(rev,1,BitTest(byte,5));\
		BitSetTo(rev,2,BitTest(byte,4));\
		BitSetTo(rev,3,BitTest(byte,3));\
		BitSetTo(rev,4,BitTest(byte,2));\
		BitSetTo(rev,5,BitTest(byte,1));\
		BitSetTo(rev,6,BitTest(byte,0));\
	}
		
	
#elif N==64
	#define BitReversal(rev,byte){\
		BitSetTo(rev,0,BitTest(byte,5));\
		BitSetTo(rev,1,BitTest(byte,4));\
		BitSetTo(rev,2,BitTest(byte,3));\
		BitSetTo(rev,3,BitTest(byte,2));\
		BitSetTo(rev,4,BitTest(byte,1));\
		BitSetTo(rev,5,BitTest(byte,0));\
	}
	
#elif N==32


	#define BitReversal(rev,byte){\
		BitSetTo(rev,0,BitTest(byte,4));\
		BitSetTo(rev,1,BitTest(byte,3));\
		BitSetTo(rev,2,BitTest(byte,2));\
		BitSetTo(rev,3,BitTest(byte,1));\
		BitSetTo(rev,4,BitTest(byte,0));\
	}
		
#endif //

