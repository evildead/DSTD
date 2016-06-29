#include "fft.h"

using namespace dstd;

const double PI = 3.141592653589793238460;

void dstd::printCArray(const CArray &arr)
{
    int i;
    for(i = 0; i < (int)arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Cooley–Tukey FFT (in-place, divide-and-conquer)
// Higher memory requirements and redundancy although more intuitive
void dstd::fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;

    // divide
    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];

    // conquer
    fft(even);
    fft(odd);

    // combine
    for (size_t k = 0; k < N/2; ++k) {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}

// inverse fft (in-place)
void dstd::ifft(CArray& x)
{
    // conjugate the complex numbers
    x = x.apply(std::conj);

    // forward fft
    fft( x );

    // conjugate the complex numbers again
    x = x.apply(std::conj);

    // scale the numbers
    x /= x.size();
}

// numeric string to CArray structure
CArray dstd::numericStringToCArray(const std::string &str, int arraySize)
{
    int mySize, strSize, i, x;
    strSize = (int)str.size();
    if(arraySize > -1) {
        mySize = std::max(arraySize, strSize);
    }
    else {
        mySize = strSize;
    }
    CArray myArray(mySize);

    x = 0;
    for(i = strSize-1; i >= 0; i--) {
        Complex myComplex((double)(str.at(i) - '0'));
        myArray[x++] = myComplex;
    }

    if(mySize > strSize) {
        for(i = strSize; i < mySize; i++) {
            myArray[i] = Complex(0.0);
        }
    }

    return myArray;
}

std::string dstd::CArrayToNumericString(const CArray &arr)
{
    std::string myStr;
    int i;

    for(i = 0; i < (int)arr.size(); i++) {
        Complex tmpComplex = arr[i];
        char tmpChar = (char)((int)(tmpComplex.real()) + '0');
        myStr.insert(myStr.begin(), 1, tmpChar);
    }

    return myStr;
}

unsigned long dstd::upperPowerOfTwo(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

std::string dstd::multiplyNumericStringsWithFFT(const std::string &str1, const std::string &str2)
{
    int i;
    unsigned int amountCarriedOver = 0;
    int x = (int)str1.size();
    int y = (int)str2.size();

    // size of final CArray
    int mSize = (int)upperPowerOfTwo(x+y);

    // fft first number
    CArray str1Arr = numericStringToCArray(str1, mSize);
    fft(str1Arr);

    // fft second number
    CArray str2Arr = numericStringToCArray(str2, mSize);
    fft(str2Arr);

    // convolution
    CArray mArr(mSize);
    for(i = 0; i < mSize; i++) {
        double re = (str1Arr[i].real() * str2Arr[i].real()) - (str1Arr[i].imag() * str2Arr[i].imag());
        double im = (str1Arr[i].real() * str2Arr[i].imag()) + (str1Arr[i].imag() * str2Arr[i].real());
        mArr[i] = Complex(re, im);
    }

    // inverse fft
    ifft(mArr);

    // rescale coefficients in base 10
    for(i = 0; i < mSize; i++) {
        int tmpVal = (int)(round(mArr[i].real()));
        tmpVal += amountCarriedOver;
        mArr[i] = Complex(tmpVal % 10, 0.0);
        amountCarriedOver = (int)(tmpVal / 10);
    }

    return CArrayToNumericString(mArr);
}
