MKL_FLAGS=$(shell pkg-config --libs --cflags mkl-dynamic-lp64-seq)
C_FLGAS=-O3 -I../common
#PRECISION=-DDOUBLE_PRECISION
all:
	gcc -o test_her her.c   ${MKL_FLAGS} ${C_FLGAS} ${PRECISION}
	gcc -o test_herk herk.c   ${MKL_FLAGS} ${C_FLGAS} ${PRECISION}
	gcc -o test_hpr hpr.c   ${MKL_FLAGS} ${C_FLGAS} ${PRECISION}
	gcc -o test_hemv hemv.c ${MKL_FLAGS} ${C_FLGAS} ${PRECISION}
	gcc -o test_hpmv hpmv.c ${MKL_FLAGS} ${C_FLGAS} ${PRECISION}
	gcc -o test_scal scal.c ${MKL_FLAGS} ${C_FLGAS} ${PRECISION}
