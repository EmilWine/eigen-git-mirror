#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "time_bench.h"

using namespace std;
using namespace Eigen;

#define MAT_TYPE complex<float>
#define N 2
#define StorageOrder ColMajor
#define MAT_CLASS  Matrix< MAT_TYPE , Dynamic , Dynamic, StorageOrder>

//typedef Eigen::Map<MAT_CLASS> MatrixMap;
typedef Map<Matrix<MAT_TYPE, Dynamic, Dynamic, StorageOrder>> MatrixMap;

int main()
{
	float alpha = 0.9;
	MAT_CLASS a;

	a.setOnes(2,2);

	MatrixMap ma(a.data(),N,N);
	
	matrix_scale_add<MAT_CLASS>::run(a,alpha);
	//matrix_scale_add<MatrixMap,ConstMatrixMap>::run(ma,mx,alpha);

	cout << a << endl;
}


