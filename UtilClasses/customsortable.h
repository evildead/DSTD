#ifndef CUSTOMSORTABLE_H
#define CUSTOMSORTABLE_H

#include <string>
namespace dstd {

    class CustomSortable
    {
    protected:
        std::string strLabel_;
        long long numLabel_;
        long long customSortVal_;

    public:
        CustomSortable(std::string strLabel, long long numLabel, long long customSortVal = -1) :
            strLabel_(strLabel), numLabel_(numLabel), customSortVal_(customSortVal)
        {

        }

        inline long long getNumLabel() const
        {
            return this->numLabel_;
        }

        inline void setNumLabel(long long numLabel)
        {
            this->numLabel_ = numLabel;
        }

        inline long long getCustomSortVal() const
        {
            return this->customSortVal_;
        }

        inline void setCustomSortVal(long long customSortVal)
        {
            this->customSortVal_ = customSortVal;
        }

        inline const std::string& getStrLabel() const
        {
            return this->strLabel_;
        }

        inline void setStrLabel(const std::string &strLabel)
        {
            this->strLabel_ = strLabel;
        }

        friend bool operator< (const CustomSortable& l, const CustomSortable& r)
        {
            if(l.customSortVal_ == r.customSortVal_) {
                return l.numLabel_ < r.numLabel_;
            }
            else {
                return l.customSortVal_ < r.customSortVal_;
            }
        }

        friend bool operator> (const CustomSortable& l, const CustomSortable& r)
        {
            if(l.customSortVal_ == r.customSortVal_) {
                return l.numLabel_ > r.numLabel_;
            }
            else {
                return l.customSortVal_ > r.customSortVal_;
            }
        }
    };

}

#endif // CUSTOMSORTABLE_H
