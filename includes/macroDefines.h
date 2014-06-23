
#ifndef MACRODEFINES_H_
#define MACRODEFINES_H_

/* Generals */

#define CPLX 					(2)

/* LTE constants */

#define N_SC_OVER_PRB 			(12)
#define N_SYM_OVER_PRB			(14)

/* System configurations */

#define N_FFT 					(1024)
#define N_FFT_USED 				(600)

/* System Limitations */

#define MAX_ACTIVE_USERS 		(10)
#define MAX_MUX_USERS 			(8)

#ifdef TEN_MHZ
	#define MAX_SCHBLK_OVER_SF 	(10)
	#define MAX_PRB_OVER_SF		(50)
#elif TWENTY_MHZ
	#define MAX_SCHBLK_OVER_SF 	(20)
	#define MAX_PRB_OVER_SF		(100)
#endif

#define MIN(X,Y) 			((X)<(Y))?(X):(Y)
#define MAX(X,Y) 			((X)>(Y))?(X):(Y)

#define ALIGNMENT_SIZE 			(64)


#endif /* MACRODEFINES_H_ */
