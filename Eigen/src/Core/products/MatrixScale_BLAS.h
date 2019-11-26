#ifndef EIGEN_MATRIX_SCALE_BLAS_H
#define EIGEN_MATRIX_SCALE_BLAS_H

namespace Eigen { 
namespace internal {

#define EIGEN_BLAS_AXPY_SPECIALIZATION(EIGTYPE,BLASTYPE,BLASFUNC) \
template<typename Index>\
struct matrix_scale_add_imp<EIGTYPE,Index>\
{ \
	typedef EIGTYPE Scalar; \
	static void run(Index size, Scalar *dest, const Scalar alpha){ \
		BlasIndex n = internal::convert_index<BlasIndex>(size), incx=1, incy=1; \
		BLASFUNC(&n, (const BLASTYPE*)&numext::real_ref(alpha) ,(BLASTYPE*) dest, &incx); \
	} \
}; \

#ifdef EIGEN_USE_MKL
EIGEN_BLAS_AXPY_SPECIALIZATION(float, float, sscal)
EIGEN_BLAS_AXPY_SPECIALIZATION(double, double, dscal)
EIGEN_BLAS_AXPY_SPECIALIZATION(scomplex, MKL_Complex8, cscal)
EIGEN_BLAS_AXPY_SPECIALIZATION(dcomplex, MKL_Complex16, zscal)
#else
EIGEN_BLAS_AXPY_SPECIALIZATION(float, float, sscal_)
EIGEN_BLAS_AXPY_SPECIALIZATION(double, double, dscal_)
EIGEN_BLAS_AXPY_SPECIALIZATION(scomplex, scomplex, cscal_)
EIGEN_BLAS_AXPY_SPECIALIZATION(dcomplex, dcomplex, zscal_)
#endif

}
}
#endif
