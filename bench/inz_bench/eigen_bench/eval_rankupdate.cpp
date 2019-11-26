#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "time_bench.h"

using namespace std;
using namespace Eigen;

#define MAT_TYPE complex<float>
#define N 2
#define StorageOrder ColMajor
#define MAT_CLASS  Matrix< MAT_TYPE , N , N, StorageOrder>
//#define MAT_CLASS  Matrix< MAT_TYPE , N , N, StorageOrder>
//#define VEC_CLASS  Matrix< MAT_TYPE , N , 1>
#define VEC_CLASS  Matrix< MAT_TYPE , N , Dynamic, StorageOrder>
int main()
{
	float alpha = 1.0;
	MAT_CLASS a;
	VEC_CLASS x,y;
	
	a.setOnes();
	a.diagonal().setConstant(5);
	//x.setRandom();
	x = 3*MatrixXcf::Random(N,2);

	//cout << "################ BEFORE ###############\n";
	//cout  <<"A\n----\n" << a<< endl;
	//cout << "X * X'\n----\n" << x * x.conjugate().transpose()<< endl;
	//cout << "A + X * X'\n----\n" << a + x * x.conjugate().transpose() << endl;

	//a.template selfadjointView<Lower>().rankUpdate(x,alpha);	


	//cout << "################ AFTER ###############\n";
	//cout <<"A\n----\n" << a<< endl;

	y = a.template selfadjointView<Lower>() * x;	
	cout << y << endl;
}

