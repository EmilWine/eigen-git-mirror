MKL_FLAGS=$(shell pkg-config --libs --cflags mkl-dynamic-lp64-seq)
#C_FLGAS=-O0 -g -I../common -I../../../../eigen -DEIGEN_USE_MKL -DEIGEN_USE_BLAS  ${MKL_FLAGS}
#C_FLGAS=-O0 -g -I../common -I../../../../eigen #-DEIGEN_USE_MKL -DEIGEN_USE_BLAS  ${MKL_FLAGS}
C_FLGAS=-O3 -I../common -I../../../../eigen -DEIGEN_USE_MKL -DEIGEN_USE_BLAS  ${MKL_FLAGS}

all: matrix_scale rankupdate eval_rankupdate matrix_vector eval_matrix_scale eval_matrix_vector

matrix_scale:
	g++  $@.cpp -o test_$@ ${C_FLGAS}

rankupdate:
	g++  $@.cpp -o test_$@ ${C_FLGAS}

eval_matrix_scale:
	g++  $@.cpp -o test_$@ ${C_FLGAS}

eval_rankupdate:
	g++  $@.cpp -o test_$@ ${C_FLGAS}

matrix_vector:
	g++  $@.cpp -o test_$@ ${C_FLGAS}

eval_matrix_vector:
	g++  $@.cpp -o test_$@ ${C_FLGAS}
