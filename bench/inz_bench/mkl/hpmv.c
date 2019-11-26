#include <stdio.h>
#include <stdlib.h>
#include "time_bench.h"
#include <time.h>

#include "mkl_example.h"

#ifdef DOUBLE_PRECISION
	#define MKL_MAT_TYPE MKL_Complex16
	#define EVAL_FUNC cblas_zhpmv
#else
	#define MKL_MAT_TYPE MKL_Complex8
	#define EVAL_FUNC cblas_chpmv
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
	MKL_INT         m, n, lda, incx;
	MKL_INT 		uplo;
	float           alpha,beta;
	MKL_MAT_TYPE          **a, **x,**y;
	CBLAS_LAYOUT    layout;
	int i,f,freqs;

	srand (time(NULL));

	n = 125;
	incx = 1;
	alpha = 0.9;
	beta = 0.0;
	layout = CblasRowMajor;
	uplo = CblasLower;
	lda = n;
	freqs = 257;

	a = (MKL_MAT_TYPE**)calloc( freqs, sizeof(MKL_MAT_TYPE*)); 
	x = (MKL_MAT_TYPE**)calloc( freqs, sizeof(MKL_MAT_TYPE*)); 
	y = (MKL_MAT_TYPE**)calloc( freqs, sizeof(MKL_MAT_TYPE*)); 
	
	for (f = 0; f < freqs; f++){
		a[f] = (MKL_MAT_TYPE *)calloc( n*n, sizeof(MKL_MAT_TYPE) );
		x[f] = (MKL_MAT_TYPE *)calloc( n, sizeof(MKL_MAT_TYPE) );
		y[f] = (MKL_MAT_TYPE *)calloc( n, sizeof(MKL_MAT_TYPE) );
		fill_array(a[f],n*n);
		fill_array(x[f],n);
		fill_array(y[f],n);
	}

	if( a == NULL || x == NULL) {
		printf( "\n Can't allocate memory for arrays\n");
		return 1;
	}

	bench *b0 = start_bench();
	for (i = 0; i < 1000; i++){
		bench *b1 = start_bench();
		for (f = 0; f < freqs; f++){
			//EVAL_FUNC(layout, uplo, n, alpha, x[f], incx, a[f],lda);
			EVAL_FUNC(layout, uplo, n, &alpha, a[f],x[f],incx,&beta,y[f],incx);
		}
		end_bench(b1,"");
	}
	end_bench(b0,STR(EVAL_FUNC)" - total runtime[ms]: ");
	free(a);
	free(x);
	return 0;
}
