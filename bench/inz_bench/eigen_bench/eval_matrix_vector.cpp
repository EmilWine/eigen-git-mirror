#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "time_bench.h"

using namespace std;
using namespace Eigen;

#define MAT_TYPE complex<float>
#define N 4
#define StorageOrder RowMajor
#define MAT_CLASS  Matrix< MAT_TYPE , N , N, StorageOrder>
#define VEC_CLASS  Matrix< MAT_TYPE , N , Dynamic, StorageOrder>
int main()
{
	float alpha = 0.5;
	float beta = 2;
	MAT_CLASS a;
	VEC_CLASS x,y1,y2;
	
	a.setOnes();
	a.diagonal().setConstant(5);
	a(1,0) = {3.3,-0.7};
	a(0,1) = {3.3,0.7};

	x = MAT_TYPE({3,0.5})*MatrixXcf::Ones(N,1);

	y1 = a.template selfadjointView<Lower>() * x;	
	y2 = a * x;	

	cout <<"x\n" << x<< endl;
	cout <<"a\n" << a<< endl;
	cout <<"dy\n" << y1-y2<< endl;

	//y = a.template selfadjointView<Lower>() * x;	
	//cout << y << endl;
}

