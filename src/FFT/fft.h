/*************************************************
 *                                               *
 *   Author: Danilo Carrabino                    *
 *                                               *
 *************************************************/


#ifndef FFT_H
#define FFT_H

#include <complex>
#include <iostream>
#include <valarray>
#include <string>
#include <algorithm>
#include <cmath>

namespace dstd {
    typedef std::complex<double> Complex;
    typedef std::valarray<Complex> CArray;

    void printCArray(const CArray &arr);
    void fft(CArray& x);
    void ifft(CArray& x);
    CArray numericStringToCArray(const std::string &str, int arraySize = -1);
    std::string CArrayToNumericString(const CArray &arr);
    unsigned long upperPowerOfTwo(unsigned long v);
    std::string multiplyNumericStringsWithFFT(const std::string &str1, const std::string &str2);
}

#endif // FFT_H
