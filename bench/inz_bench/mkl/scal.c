#include <stdio.h>
#include <stdlib.h>
#include "time_bench.h"
#include <time.h>

#include "mkl_example.h"

#ifdef DOUBLE_PRECISION
	#define MKL_MAT_TYPE MKL_Complex16
	#define EVAL_FUNC cblas_zdscal
#else
	#define MKL_MAT_TYPE MKL_Complex8
	#define EVAL_FUNC cblas_csscal
#endif

#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)

void fill_array(MKL_MAT_TYPE *arr, int len){
	int r;
	for (int i=0; i < len; i++){
		r = rand();
		arr[i].real = (float)r; arr[i].imag = (float)r * 2.0;
	}
}

int main()
{
	MKL_INT         n,  incx;
	float           alpha;
	MKL_MAT_TYPE    **a;
	int i,f,freqs;
	srand (time(NULL));

	n = 125;
	incx = 1;
	alpha = 0.8;
	freqs = 257;

	a = (MKL_MAT_TYPE**)calloc( freqs, sizeof(MKL_MAT_TYPE*)); 
	
	for (f = 0; f < freqs; f++){
		a[f] = (MKL_MAT_TYPE *)calloc( n*n, sizeof(MKL_MAT_TYPE) );
		fill_array(a[f],n*n);
	}

	if( a == NULL ) {
		printf( "\n Can't allocate memory for arrays\n");
		return 1;
	}

	bench *b0 = start_bench();
	for (i = 0; i < 1000; i++){
		for (f = 0; f < freqs; f++){
			EVAL_FUNC(n*n, alpha, a[f], incx);
		}
	}
	end_bench(b0,STR(EVAL_FUNC)" - total runtime[ms]: ");
	free(a);
	return 0;
}
