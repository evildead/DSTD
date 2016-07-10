#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include "Utilities/utilities.h"
using namespace std;

namespace dstd {

    class BigInt
    {
    protected:
        bool sign_;
        string val_;

    public:
        BigInt(const string& val = "0");

        BigInt(long long val);

        BigInt(const BigInt& other);

        virtual ~BigInt();

        BigInt & operator= (const BigInt& other);

        void setVal(const string &val);

        int compareAbsValue(const BigInt& other) const;

        string getPrintableVal(bool printPlusSign = false) const;

        string getAbsoluteVal() const;

        bool getSign() const;

        void invertSign();

        friend bool operator< (const BigInt& l, const BigInt& r)
        {
            // l negative, r positive -> true
            if( (l.sign_ == false) && (r.sign_ == true) ) {
                return true;
            }
            // l positive, r negative -> false
            else if( (r.sign_ == false) && (l.sign_ == true) ) {
                return false;
            }

            // l and r have the same sign -> check absolute values
            int compareAbsValuesResult = l.compareAbsValue(r);

            // positive
            if(l.sign_) {
                if(compareAbsValuesResult < 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
            // negative
            else {
                if(compareAbsValuesResult > 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }

        inline friend bool operator> (const BigInt& lhs, const BigInt& rhs)
        {
            return rhs < lhs;
        }
        inline friend bool operator<=(const BigInt& lhs, const BigInt& rhs)
        {
            return !(lhs > rhs);
        }
        inline friend bool operator>=(const BigInt& lhs, const BigInt& rhs)
        {
            return !(lhs < rhs);
        }

        friend bool operator==(const BigInt& lhs, const BigInt& rhs)
        {
            if( (lhs.sign_ == rhs.sign_) && (lhs.val_.compare(rhs.val_) == 0) ) {
                return true;
            }
            else {
                return false;
            }
        }

        inline friend bool operator!=(const BigInt& lhs, const BigInt& rhs)
        {
            return !(lhs == rhs);
        }

        friend std::ostream& operator<<(std::ostream& os, const BigInt& obj)
        {
            os << obj.getPrintableVal();
            return os;
        }

        friend std::istream& operator>>(std::istream& is, BigInt& obj)
        {
            string val;
            is >> val;

            obj.setVal(val);
            //if( /* T could not be constructed */ )
            //    is.setstate(std::ios::failbit);

            return is;
        }

        BigInt& operator+=(const BigInt& rhs)
        {
            if(this->sign_ == rhs.sign_) {
                //sumAbsoluteVal(rhs);
                sumAbsoluteValV2(rhs);
            }
            else {
                int compareAbsValuesResult = compareAbsValue(rhs);
                if(compareAbsValuesResult < 0) {
                    this->sign_ = !(this->sign_);
                }
                //subtractAbsoluteVal(rhs);
                subtractAbsoluteValV2(rhs);

                if(this->val_.compare("0") == 0) {
                    this->sign_ = true;
                }
            }

            return *this; // return the result by reference
        }

        BigInt& operator-=(const BigInt& rhs)
        {
            BigInt invRhs(rhs);
            invRhs.invertSign();
            operator +=(invRhs);

            return *this; // return the result by reference
        }

        BigInt& operator*=(const BigInt& rhs)
        {
            if(this->sign_ == rhs.sign_) {
                this->sign_ = true;
            }
            else {
                this->sign_ = false;
            }

            multiplyAbsoluteValFFT(rhs);

            return *this; // return the result by reference
        }

        // friends defined inside class body are inline and are hidden from non-ADL lookup
        friend BigInt operator+(BigInt lhs, const BigInt& rhs)
        {
            lhs += rhs; // reuse compound assignment
            return lhs; // return the result by value (uses move constructor)
        }

        friend BigInt operator-(BigInt lhs, const BigInt& rhs)
        {
            lhs -= rhs; // reuse compound assignment
            return lhs; // return the result by value (uses move constructor)
        }

        friend BigInt operator*(BigInt lhs, const BigInt& rhs)
        {
            lhs *= rhs; // reuse compound assignment
            return lhs; // return the result by value (uses move constructor)
        }

        // pre-increment
        BigInt& operator++()
        {
            operator+=(BigInt(1));
            return *this;
        }

        // post-increment
        BigInt operator++(int)
        {
            BigInt tmp(*this); // copy
            operator++(); // pre-increment
            return tmp;   // return old value
        }

        // pre-decrement
        BigInt& operator--()
        {
            operator-=(BigInt(1));
            return *this;
        }

        // post-decrement
        BigInt operator--(int)
        {
            BigInt tmp(*this); // copy
            operator--(); // pre-increment
            return tmp;   // return old value
        }

        BigInt power(unsigned int exponent);

    protected:
        void swap(const BigInt& other);

        void sumAbsoluteVal(const BigInt& other);
        void sumAbsoluteValV2(const BigInt& other);

        void subtractAbsoluteVal(const BigInt& other);
        void subtractAbsoluteValV2(const BigInt& other);

        void multiplyAbsoluteVal(const BigInt& other);
        void multiplyAbsoluteValFFT(const BigInt& other);

    protected:
        static void makeSameSize(string &a, string &b);
        static void removeLeadingZeroes(string &str);
    };


    BigInt computeFibonacciModified(unsigned int a, unsigned int b, unsigned int n);
    BigInt fibonacci(unsigned int n);
    BigInt factorial(unsigned int n);
}

#endif // BIGINT_H
