#include "bigint.h"
using namespace dstd;


BigInt::BigInt(const string& val)
{
    setVal(val);
}

BigInt::BigInt(long long val)
{
    if(val < 0) {
        sign_ = false;
    }
    else {
        sign_ = true;
    }

    long long absValue = ((val < 0) ? (val * -1) : (val));
    val_ = lltostr(absValue, 10);
}

BigInt::BigInt(const BigInt& other)
{
    swap(other);
}

BigInt::~BigInt()
{

}

BigInt & BigInt::operator= (const BigInt& other)
{
    if(this != &other) {
        swap(other);
    }

    return *this;
}

void BigInt::swap(const BigInt& other)
{
    this->sign_ = other.sign_;
    this->val_ = other.val_;
}

void BigInt::setVal(const string &val)
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

int BigInt::compareAbsValue(const BigInt& other) const
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

string BigInt::getPrintableVal(bool printPlusSign) const
{
    std::stringstream mySStream;

    if( (printPlusSign) || (!sign_) ) {
        mySStream << ((sign_) ? "+" : "-");
    }

    mySStream << val_;

    return mySStream.str();
}

string BigInt::getAbsoluteVal() const
{
    return val_;
}

bool BigInt::getSign() const
{
    return sign_;
}

void BigInt::invertSign()
{
    sign_ = !sign_;
}

void BigInt::sumAbsoluteVal(const BigInt& other)
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

void BigInt::subtractAbsoluteVal(const BigInt& other)
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

void BigInt::multiplyAbsoluteVal(const BigInt& other)
{
    string strRes;
    string str1, str2;
    unsigned int amountCarriedOver = 0;

    if((this->val_.compare("0") == 0) || (other.val_.compare("0") == 0)) {
        val_ = "0";
        return;
    }

    str1 = strreverse(this->val_);
    str2 = strreverse(other.val_);

    BigInt totalSum(0);
    for(unsigned int i = 0; i < str2.size(); i++) {
        string tmpVal;
        int first = (int)(str2.at(i) - '0');
        if(first == 0) {
            continue;
        }

        tmpVal.append(i, '0');

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

        BigInt valToSum = strreverse(tmpVal);
        totalSum += valToSum;
    }

    this->val_ = totalSum.val_;
}
