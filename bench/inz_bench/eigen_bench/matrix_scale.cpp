#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "time_bench.h"

using namespace std;
using namespace Eigen;

#define MAT_TYPE complex<float>
#define N 125
#define StorageOrder ColMajor
//#define MAT_CLASS  Matrix< MAT_TYPE , N , N, StorageOrder>
#define MAT_CLASS  Matrix< MAT_TYPE , Dynamic , Dynamic, StorageOrder>


int main()
{
	int freqs = 257;
	float alpha = 0.8;
	int runs = 1000;
	std::vector<MAT_CLASS> a(freqs);


	for (int f =0; f < freqs; f++)
	{
		a.at(f).setRandom(N,N);
		//a.at(f).diagonal().setConstant(5);
	}

	bench *b0 = start_bench();
	for (int i = 0; i < runs; i++) {
		for (int f =0; f < freqs; f++){
			matrix_scale_add<MAT_CLASS>::run(a.at(f),alpha);
		}
	}
	end_bench(b0,"Matrix scale - total runtime[ms]: ");
}

