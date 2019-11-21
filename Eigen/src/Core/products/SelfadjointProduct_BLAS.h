#ifndef EIGEN_SELFADJOINT_PRODUCT_BLAS_H
#define EIGEN_SELFADJOINT_PRODUCT_BLAS_H

namespace Eigen { 

#define EIGEN_BLAS_HER_SPECIALIZATION(EIGTYPE,EIGREALTYPE,BLASTYPE,BLASFUNC) \
template<typename Index, int UpLo, bool ConjLhs, bool ConjRhs> \
struct selfadjoint_rank1_update<EIGTYPE,Index,ColMajor,UpLo,ConjLhs,ConjRhs> \
{ \
  static void run(Index size, EIGTYPE* mat, Index stride, const EIGTYPE* vecX, const EIGTYPE* vecY, const EIGTYPE& alpha) \
  { \
    char uplo = UpLo == Lower ? 'L':'U'; \
    BlasIndex n = internal::convert_index<BlasIndex>(size), lda=internal::convert_index<BlasIndex>(stride), incx=1, incy=1; \
    typedef Matrix<EIGTYPE, Dynamic, Dynamic, RowMajor> MatrixType; \
    MatrixType a; \
    const EIGTYPE* a_ptr; \
    if (!ConjRhs) { \
      Map<const MatrixType, 0, OuterStride<> > mapA(vecX,n,1,OuterStride<>(incx)); \
      a = mapA.conjugate(); \
      a_ptr = a.data(); \
    } else a_ptr=vecX; \
    BLASFUNC(&uplo,&n, (const EIGREALTYPE*)&numext::real_ref(alpha), (const BLASTYPE*) a_ptr, &incx,(BLASTYPE*)mat,(const BlasIndex*) &lda); \
  } \
}; \
template<typename Index, int UpLo, bool ConjLhs, bool ConjRhs> \
struct selfadjoint_rank1_update<EIGTYPE,Index,RowMajor,UpLo,ConjLhs,ConjRhs> \
{ \
  static void run(Index size, EIGTYPE* mat, Index stride, const EIGTYPE* vecX, const EIGTYPE* vecY, const EIGTYPE& alpha) \
  { \
    char uplo = UpLo == Lower ? 'U':'L'; \
    BlasIndex n = internal::convert_index<BlasIndex>(size), lda=internal::convert_index<BlasIndex>(stride), incx=1, incy=1; \
    typedef Matrix<EIGTYPE, Dynamic, Dynamic, RowMajor> MatrixType; \
    MatrixType a; \
    const EIGTYPE* a_ptr; \
    if (ConjRhs) { \
      Map<const MatrixType, 0, OuterStride<> > mapA(vecX,n,1,OuterStride<>(incx)); \
      a = mapA.conjugate(); \
      a_ptr = a.data(); \
    } else a_ptr=vecX; \
    BLASFUNC(&uplo,&n, (const EIGREALTYPE*)&numext::real_ref(alpha), (const BLASTYPE*) a_ptr, &incx,(BLASTYPE*)mat,(const BlasIndex*) &lda); \
  } \
};

#ifdef EIGEN_USE_MKL
EIGEN_BLAS_HER_SPECIALIZATION(double, double,  double, dsyr)
EIGEN_BLAS_HER_SPECIALIZATION(float,  float,  float,  ssyr)
EIGEN_BLAS_HER_SPECIALIZATION(dcomplex, double, MKL_Complex16, zher)
EIGEN_BLAS_HER_SPECIALIZATION(scomplex, float,MKL_Complex8,  cher)
#else
EIGEN_BLAS_HER_SPECIALIZATION(double, double,  double, dsyr_)
EIGEN_BLAS_HER_SPECIALIZATION(float, float,   float,  ssyr_)
EIGEN_BLAS_HER_SPECIALIZATION(dcomplex, double,dcomplex, zher_)
EIGEN_BLAS_HER_SPECIALIZATION(scomplex, float, scomplex,  cher_)
#endif


//#define EIGEN_BLAS_HERK_SPECIALIZATION(EIGTYPE,EIGREALTYPE,BLASTYPE,BLASFUNC) \
//template<typename Index, int UpLo, int StorageOrder, int MaxColsAtCompileTime, int InnerStrideAtCompileTime, \
//	int OtherStorageOrder, int OtherMaxColsAtCompileTime, bool ConjLhs, bool ConjRhs> \
//struct selfadjoint_rank_k_update<EIGTYPE,Index,UpLo,StorageOrder, MaxColsAtCompileTime, InnerStrideAtCompileTime, \
//OtherStorageOrder, OtherMaxColsAtCompileTime, ConjLhs,ConjRhs> \
//{ \
//    static void EIGEN_STRONG_INLINE run(Index size, Index depth, EIGTYPE* mat, Index stride, const EIGTYPE* other, Index otherStride, const EIGTYPE& alpha)\
//  { \
//    char uplo = UpLo == Lower ? 'L':'U'; \
//    char trans=((StorageOrder==RowMajor) ? 'C':'N');\
//    EIGREALTYPE beta_ = 1.0; \
//    BlasIndex lda= internal::convert_index<BlasIndex>(otherStride), ldc= internal::convert_index<BlasIndex>(stride), \
//	  n= internal::convert_index<BlasIndex>(size), k= internal::convert_index<BlasIndex>(depth); \
//    BLASFUNC(&uplo, &trans, &n, &k, (const EIGREALTYPE*) &numext::real_ref(alpha), (BLASTYPE*)other, &lda, &beta_, (BLASTYPE*) mat, &ldc); \
//  } \
//};
//
//#ifdef EIGEN_USE_MKL
////EIGEN_BLAS_HERK_SPECIALIZATION(double, double,  double, dsyr)
////EIGEN_BLAS_HERK_SPECIALIZATION(float,  float,  float,  ssyr)
//EIGEN_BLAS_HERK_SPECIALIZATION(dcomplex, double, MKL_Complex16, zherk)
//EIGEN_BLAS_HERK_SPECIALIZATION(scomplex, float,MKL_Complex8,  cherk)
//#else
////EIGEN_BLAS_HERK_SPECIALIZATION(double, double,  double, dsyr_)
////EIGEN_BLAS_HERK_SPECIALIZATION(float, float,   float,  ssyr_)
//EIGEN_BLAS_HERK_SPECIALIZATION(dcomplex, double,double, zherk_)
//EIGEN_BLAS_HERK_SPECIALIZATION(scomplex, float, float,  cherk_)
//#endif

} // end namespace Eigen

#endif // EIGEN_SELFADJOINT_PRODUCT_H
