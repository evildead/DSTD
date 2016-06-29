#include "bigint.h"
#include "FFT/fft.h"
using namespace dstd;


dstd::BigInt::BigInt(const string& val)
{
    setVal(val);
}

dstd::BigInt::BigInt(long long val)
{
    if(val < 0) {
        sign_ = false;
    }
    else {
        sign_ = true;
    }

    long long absValue = ((val < 0) ? (val * -1) : (val));
    val_ = lltostr(absValue);
}

dstd::BigInt::BigInt(const BigInt& other)
{
    swap(other);
}

dstd::BigInt::~BigInt()
{

}

dstd::BigInt & BigInt::operator= (const BigInt& other)
{
    if(this != &other) {
        swap(other);
    }

    return *this;
}

void dstd::BigInt::swap(const BigInt& other)
{
    this->sign_ = other.sign_;
    this->val_ = other.val_;
}

void dstd::BigInt::setVal(const string &val)
{
    string tmpStr = trim(val, " \t\r\n\0");
    sign_ = true;
    val_ = "";

    if(tmpStr.size() < 1) {
        val_ = "0";
        return;
    }

    unsigned int i = 0;
    if(tmpStr.at(i) == '-') {
        i++;
        sign_ = false;
    }
    else if(tmpStr.at(i) == '+') {
        i++;
        sign_ = true;
    }

    while(i < tmpStr.size()) {
        if((tmpStr.at(i) >= '0') && (tmpStr.at(i) <= '9')) {
            val_.append(1, tmpStr.at(i));
        }
        else {
            val_ = "0";
            sign_ = true;
            return;
        }

        ++i;
    }

    val_ = trimleft(val_, "0");

    if((val_.size() < 1)) {
        val_ = "0";
        sign_ = true;
        return;
    }

    if(val_.compare("0") == 0) {
        sign_ = true;
    }
}

int dstd::BigInt::compareAbsValue(const BigInt& other) const
{
    if(this->val_.size() < other.val_.size()) {
        return -1;
    }
    else if(this->val_.size() > other.val_.size()) {
        return 1;
    }
    // same size
    else {
        for(unsigned int i = 0; i < this->val_.size(); i++) {
            if( this->val_[i] < other.val_[i] ) {
                return -1;
            }
            else if( this->val_[i] > other.val_[i] ) {
                return 1;
            }
        }

        return 0;
    }
}

string dstd::BigInt::getPrintableVal(bool printPlusSign) const
{
    std::stringstream mySStream;

    if( (printPlusSign) || (!sign_) ) {
        mySStream << ((sign_) ? "+" : "-");
    }

    mySStream << val_;

    return mySStream.str();
}

string dstd::BigInt::getAbsoluteVal() const
{
    return val_;
}

bool dstd::BigInt::getSign() const
{
    return sign_;
}

void dstd::BigInt::invertSign()
{
    sign_ = !sign_;
}

void dstd::BigInt::sumAbsoluteVal(const BigInt& other)
{
    string strRes;
    string str1, str2;
    unsigned int amountCarriedOver = 0;

    if(this->val_.size() > other.val_.size()) {
        str1 = strreverse(this->val_);
        str2 = strreverse(other.val_);
    }
    else {
        str2 = strreverse(this->val_);
        str1 = strreverse(other.val_);
    }

    for(unsigned int i = 0; i < str1.size(); i++) {
        int first = (int)(str1.at(i) - '0');
        int second = 0;
        if(str2.size() > i) {
            second = (int)(str2.at(i) - '0');
        }
        int res = first + second + amountCarriedOver;
        int digits = res % 10;
        amountCarriedOver = (int)(res / 10);
        strRes.append(1, (char)(digits + '0'));
    }

    if(amountCarriedOver > 0) {
        strRes.append(1, (char)(amountCarriedOver + '0'));
    }

    this->val_ = strreverse(strRes);
}

void dstd::BigInt::sumAbsoluteValV2(const BigInt& other)
{
    string strRes;
    string str1, str2;
    unsigned int amountCarriedOver = 0;

    str1 = other.val_;
    str2 = this->val_;
    makeSameSize(str1, str2);

    for(int i = (int)(str1.size() - 1); i >= 0; i--) {
        int first = (int)(str1.at(i) - '0');
        int second = 0;
        if((int)(str2.size()) > i) {
            second = (int)(str2.at(i) - '0');
        }
        int res = first + second + amountCarriedOver;
        int digits = res % 10;
        amountCarriedOver = (int)(res / 10);
        strRes.insert(strRes.begin(), 1, (char)(digits + '0'));
    }

    if(amountCarriedOver > 0) {
        strRes.insert(strRes.begin(), 1, (char)(amountCarriedOver + '0'));
    }

    this->val_ = strRes;
}

void dstd::BigInt::subtractAbsoluteVal(const BigInt& other)
{
    string strRes;
    string str1, str2;
    unsigned int amountCarriedOver = 0;

    int compareAbsValuesResult = compareAbsValue(other);

    if(compareAbsValuesResult > 0) {
        str1 = strreverse(this->val_);
        str2 = strreverse(other.val_);
    }
    else {
        str2 = strreverse(this->val_);
        str1 = strreverse(other.val_);
    }

    for(unsigned int i = 0; i < str1.size(); i++) {
        int first = (int)(str1.at(i) - '0');
        int second = 0;
        if(str2.size() > i) {
            second = (int)(str2.at(i) - '0');
        }
        first -= amountCarriedOver;

        if(first < second) {
            amountCarriedOver = 1;
            first += 10;
        }
        else {
            amountCarriedOver = 0;
        }

        int digits = first - second;

        strRes.append(1, (char)(digits + '0'));
    }

    this->val_ = strreverse(strRes);
}

void dstd::BigInt::subtractAbsoluteValV2(const BigInt& other)
{
    string strRes;
    string str1, str2;
    unsigned int amountCarriedOver = 0;

    int compareAbsValuesResult = compareAbsValue(other);

    if(compareAbsValuesResult > 0) {
        str1 = this->val_;
        str2 = other.val_;
    }
    else {
        str2 = this->val_;
        str1 = other.val_;
    }
    makeSameSize(str1, str2);

    for(int i = (int)(str1.size()-1); i >= 0; i--) {
        int first = (int)(str1.at(i) - '0');
        int second = 0;
        if((int)(str2.size()) > i) {
            second = (int)(str2.at(i) - '0');
        }
        first -= amountCarriedOver;

        if(first < second) {
            amountCarriedOver = 1;
            first += 10;
        }
        else {
            amountCarriedOver = 0;
        }

        int digits = first - second;

        strRes.insert(strRes.begin(), 1, (char)(digits + '0'));
    }

    this->val_ = strRes;
    removeLeadingZeroes(this->val_);
}

void dstd::BigInt::multiplyAbsoluteVal(const BigInt& other)
{
    string str1, str2;
    unsigned int amountCarriedOver = 0;

    if((this->val_.compare("0") == 0) || (other.val_.compare("0") == 0)) {
        val_ = "0";
        return;
    }

    str1 = strreverse(this->val_);
    str2 = strreverse(other.val_);

    BigInt totalSum(0);
    map<int, string> mapVal;
    for(unsigned int i = 0; i < str2.size(); i++) {
        string tmpVal;
        int first = (int)(str2.at(i) - '0');
        if(first == 0) {
            continue;
        }

        if(mapVal.find(first) != mapVal.end()) {
            string valFound = mapVal[first];
            BigInt valToSum = valFound.append(i, '0');
            totalSum += valToSum;
        }
        else {
            for(unsigned int j = 0; j < str1.size(); j++) {
                int second = (int)(str1.at(j) - '0');

                int res = (first * second) + amountCarriedOver;
                int digits = res % 10;
                amountCarriedOver = (int)(res / 10);
                tmpVal.append(1, (char)(digits + '0'));
            }

            if(amountCarriedOver > 0) {
                tmpVal.append(1, (char)(amountCarriedOver + '0'));
            }

            amountCarriedOver = 0;

            string reversedTmpVal = strreverse(tmpVal);
            mapVal[first] = reversedTmpVal;
            BigInt valToSum = reversedTmpVal.append(i, '0');
            totalSum += valToSum;
        }
    }

    this->val_ = totalSum.val_;
}

void dstd::BigInt::multiplyAbsoluteValFFT(const BigInt& other)
{
    setVal( multiplyNumericStringsWithFFT(this->val_, other.val_) );
}

BigInt dstd::BigInt::power(unsigned int exponent)
{
    if(exponent == 0) {
        return BigInt(1);
    }

    if(exponent == 1) {
        return BigInt(*this);
    }

    BigInt tmp(*this); // copy

    for(unsigned int i = 1; i < exponent; i++) {
        tmp *= (*this);
    }

    return tmp;
}

void dstd::BigInt::makeSameSize(string &a, string &b)
{
    int aSize = (int)a.size();
    int bSize = (int)b.size();

    int myMax = max(aSize, bSize);

    int aDiff = myMax - aSize;
    if(aDiff > 0) {
        a.insert(a.begin(), aDiff, '0');
    }

    int bDiff = myMax - bSize;
    if(bDiff > 0) {
        b.insert(b.begin(), bDiff, '0');
    }
}

void dstd::BigInt::removeLeadingZeroes(string &str)
{
    int numOfCharsToErase = 0;
    for(unsigned int i = 0; i < str.size(); i++) {
        if(str.at(i) == '0') {
            numOfCharsToErase++;
        }
        else {
            break;
        }
    }

    if(numOfCharsToErase > 0) {
        str.erase(0, numOfCharsToErase);
    }
}
