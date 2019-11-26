#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "time_bench.h"

using namespace std;
using namespace Eigen;

#define MAT_TYPE complex<float>
#define N 125
#define StorageOrder ColMajor
#define MAT_CLASS  Matrix< MAT_TYPE , N , N, StorageOrder>
//#define VEC_CLASS  Matrix< MAT_TYPE , N , 1,StorageOrder>
#define VEC_CLASS  Matrix< MAT_TYPE , N , Dynamic, StorageOrder>

int main()
{
	int freqs = 257;
	float alpha = 0.9;
	int runs = 1000;
	std::vector<MAT_CLASS> a(freqs);
	std::vector<VEC_CLASS> x(freqs);
	std::vector<VEC_CLASS> y(freqs);
	
	for (int f =0; f < freqs; f++){
		a.at(f).setRandom();
		a.at(f).diagonal().setConstant(5);
		y.at(f).setZero();	
		x.at(f) = MatrixXcf::Random(N,1);
		//x.at(f).setRandom();
	}
	bench *b0 = start_bench();
	for (int i = 0; i < runs; i++)
	{
		for (int f =0; f < freqs; f++){
			y.at(f) = a.at(f).template selfadjointView<Lower>() * x.at(f);	
		}
	}
	end_bench(b0,"RankUpdate - total runtime[ms]: ");
}

