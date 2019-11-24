#ifndef EIGEN_MATRIX_SCALE_BLAS_H
#define EIGEN_MATRIX_SCALE_BLAS_H

namespace Eigen { 
namespace internal {

#define EIGEN_BLAS_AXPY_SPECIALIZATION(EIGTYPE,BLASTYPE,BLASFUNC) \
template<typename Index>\
struct matrix_scale_add_imp<EIGTYPE,Index>\
{ \
	typedef EIGTYPE Scalar; \
	static void run(Index size, Scalar *dest, const Scalar *in, const Scalar alpha){ \
		BlasIndex n = internal::convert_index<BlasIndex>(size), incx=1, incy=1; \
		BLASFUNC(&n, (const BLASTYPE*)&numext::real_ref(alpha) ,(const BLASTYPE*) in, &incx, (BLASTYPE*)dest, &incy); \
	} \
}; \

#ifdef EIGEN_USE_MKL
EIGEN_BLAS_AXPY_SPECIALIZATION(float, float, saxpy)
EIGEN_BLAS_AXPY_SPECIALIZATION(double, double, daxpy)
EIGEN_BLAS_AXPY_SPECIALIZATION(scomplex, MKL_Complex8, caxpy)
EIGEN_BLAS_AXPY_SPECIALIZATION(dcomplex, MKL_Complex16, zaxpy)
#else
EIGEN_BLAS_AXPY_SPECIALIZATION(float, float, saxpy_)
EIGEN_BLAS_AXPY_SPECIALIZATION(double, double, daxpy_)
EIGEN_BLAS_AXPY_SPECIALIZATION(scomplex, scomplex, caxpy_)
EIGEN_BLAS_AXPY_SPECIALIZATION(dcomplex, dcomplex, zaxpy_)
#endif

}
}
#endif
