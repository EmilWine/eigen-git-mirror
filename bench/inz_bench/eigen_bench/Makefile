MKL_FLAGS=$(shell pkg-config --libs --cflags mkl-dynamic-lp64-seq)
C_FLGAS=-O3 -I../common -I../../../../eigen -DEIGEN_USE_MKL -DEIGEN_USE_BLAS 
#C_FLGAS=-O3 -I../common -I../../../../eigen -DEIGEN_USE_MKL -DEIGEN_USE_BLAS -lmkl_intel_lp64 -lmkl_sequential -lmkl_core 
#C_FLGAS=-O0 -g -I../common -I./eigen -DEIGEN_USE_MKL -DEIGEN_USE_BLAS -lmkl_intel_lp64 -lmkl_sequential -lmkl_core 
#C_FLGAS=-O0 -g -I../common -I./eigen 
#C_FLGAS=-O3 -I../common -I./eigen 

all: matrix_scale rankupdate eval_rankupdate matrix_vector eval_matrix_scale

matrix_scale:
	g++  $@.cpp -o test_$@ ${C_FLGAS} ${MKL_FLAGS}

rankupdate:
	g++  $@.cpp -o test_$@ ${C_FLGAS} ${MKL_FLAGS}

eval_matrix_scale:
	g++  $@.cpp -o test_$@ ${C_FLGAS} ${MKL_FLAGS}

eval_rankupdate:
	g++  $@.cpp -o test_$@ ${C_FLGAS} ${MKL_FLAGS}

matrix_vector:
	g++  $@.cpp -o test_$@ ${C_FLGAS} ${MKL_FLAGS}
