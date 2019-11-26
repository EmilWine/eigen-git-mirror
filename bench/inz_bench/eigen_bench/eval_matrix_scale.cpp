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
typedef Map<const Matrix<MAT_TYPE, Dynamic, Dynamic, StorageOrder>> ConstMatrixMap;

int main()
{
	float alpha = 0.9;
	MAT_CLASS a,x;

	
	x.setOnes(2,2);
	x.diagonal().setConstant(5);
	a.setZero(2,2);

	ConstMatrixMap mx(x.data(),N,N);
	MatrixMap ma(a.data(),N,N);
	
	matrix_scale_add<MAT_CLASS,MAT_CLASS>::run(a,x,alpha);
	//matrix_scale_add<MatrixMap,ConstMatrixMap>::run(ma,mx,alpha);

	cout << a << endl;
}


