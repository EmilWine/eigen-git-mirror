#!/bin/bash
mkdir -p build
cd build
#cmake -DEIGEN_TEST_CXX11=ON  ../
cmake -DEIGEN_TEST_CXX11=ON -DEIGEN_TEST_CUSTOM_CXX_FLAGS="-DEIGEN_MKL_DEFAULT  -DEIGEN_USE_MKL" -DEIGEN_TEST_CUSTOM_LINKER_FLAGS="-lmkl_intel_lp64 -lmkl_sequential -lmkl_core" ../
#cmake -DEIGEN_TEST_CXX11=ON -DEIGEN_TEST_CUSTOM_CXX_FLAGS="-DEIGEN_FFTW_DEFAULT" -DEIGEN_TEST_CUSTOM_LINKER_FLAGS="-lfftw3 -lfftw3f -lfftw3l -lfftw3_threads" ../

