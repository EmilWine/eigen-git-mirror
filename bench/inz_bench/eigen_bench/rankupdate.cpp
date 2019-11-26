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
#define VEC_CLASS  Matrix< MAT_TYPE , N , 2,StorageOrder>
//#define VEC_CLASS  Matrix< MAT_TYPE , N , Dynamic, StorageOrder>
int main()
{
	int freqs = 257;
	float alpha = 0.9;
	std::vector<MAT_CLASS> a(freqs);
	std::vector<VEC_CLASS> x(freqs);
	
	for (int f =0; f < freqs; f++){
		a.at(f).setRandom();
		a.at(f).diagonal().setConstant(5);
		x.at(f).setRandom();	
		//x.at(f) = MatrixXcf::Random(N,1);
	}
	bench *b0 = start_bench();
	for (int i = 0; i < 1000; i++){
		for (int f =0; f < freqs; f++){
			a.at(f).template selfadjointView<Lower>().rankUpdate(x.at(f),alpha);	
		}
	}
	end_bench(b0,"RankUpdate - total runtime[ms]: ");

	//cout << a.at(0).template selfadjointView<Lower>()*x.at(1) << endl;
}

