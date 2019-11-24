#ifndef EIGEN_MATRIX_SCALE_H
#define EIGEN_MATRIX_SCALE_H

namespace Eigen { 
namespace internal {

template<typename Scalar, typename Index>
struct matrix_scale_add_imp;

template<typename Scalar, typename Index>
struct matrix_scale_add_imp
{
	static void run(Index size, Scalar *dest, const Scalar *in, const Scalar alpha){
		typedef Map<Matrix<Scalar,Dynamic,1> > ResMap;
		typedef Map<const Matrix<Scalar,Dynamic,1> > OtherMap;
		ResMap dest_map = ResMap(dest, size);
		OtherMap in_map = OtherMap(in, size);
		dest_map = alpha*in_map +dest_map; 
	}
};

}

template<typename MatrixType>
struct matrix_scale_add
{
	static void run(MatrixType& dest, const MatrixType& x, const typename MatrixType::Scalar& alpha)
	{
		internal::matrix_scale_add_imp<typename MatrixType::Scalar, Index>::run(dest.size(),dest.data(),x.data(),alpha);
	}
};
}
#endif
