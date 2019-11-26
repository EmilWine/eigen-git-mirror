C_FLGAS=-O3 -I../common -I../../../../eigen -DEIGEN_USE_MKL -DEIGEN_USE_BLAS -lmkl_intel_lp64 -lmkl_sequential -lmkl_core 
#C_FLGAS=-O0 -g -I../common -I./eigen -DEIGEN_USE_MKL -DEIGEN_USE_BLAS -lmkl_intel_lp64 -lmkl_sequential -lmkl_core 
#C_FLGAS=-O0 -g -I../common -I./eigen 
#C_FLGAS=-O3 -I../common -I./eigen 

all: matrix_scale rankupdate eval_rankupdate matrix_vector eval_matrix_scale

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

#g++  rankupdate.cpp -o test_rankupdate ${C_FLGAS}
#g++  eval_rankupdate.cpp -o test_eval_rankupdate ${C_FLGAS}
#g++  matrix_vector.cpp -o test_matrix_vector ${C_FLGAS}

