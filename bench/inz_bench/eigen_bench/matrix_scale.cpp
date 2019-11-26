#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "time_bench.h"

using namespace std;
using namespace Eigen;

#define MAT_TYPE complex<float>
#define N 125
#define StorageOrder ColMajor
#define MAT_CLASS  Matrix< MAT_TYPE , Dynamic , Dynamic, StorageOrder>
//#define VEC_CLASS  Matrix< MAT_TYPE , N , 1,StorageOrder>
#define VEC_CLASS  Matrix< MAT_TYPE , N , Dynamic, StorageOrder>


int main()
{
	int freqs = 257;
	float alpha = 0.9;
	int runs = 1000;
	std::vector<MAT_CLASS> a(freqs);
	VEC_CLASS x;



	x.setZero(N,1);
	for (int f =0; f < freqs; f++){
		a.at(f).setRandom(N,N);
		a.at(f).diagonal().setConstant(5);
	}

	bench *b0 = start_bench();
	for (int i = 0; i < runs; i++)
	{
		for (int f =0; f < freqs; f++){
			//a.at(f) = a.at(f) * alpha;	
			//matrix_scale_add<MAT_CLASS>::run(a.at(f),x,alpha);
			matrix_scale_add<MAT_CLASS,VEC_CLASS>::run(a.at(f),x,alpha);
		}
	}
	end_bench(b0,"Matrix scale - total runtime[ms]: ");
}

