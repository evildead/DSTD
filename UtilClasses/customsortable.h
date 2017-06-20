#ifndef CUSTOMSORTABLE_H
#define CUSTOMSORTABLE_H

#include <string>
#include <vector>

namespace dstd {

    template <class TNumLabel, class TSortVal, class TData = nullptr_t>
    class CustomSortable
    {
    protected:
        TNumLabel numLabel_;
        TSortVal customSortVal_;
        std::string strLabel_;
        TData customData_;

    public:
        CustomSortable(const TNumLabel& numLabel, const TSortVal& customSortVal, std::string strLabel = "", const TData& customData = TData()) :
            numLabel_(numLabel), customSortVal_(customSortVal), strLabel_(strLabel), customData_(customData)
        {

        }

        CustomSortable()
        {

        }

        inline const TNumLabel& getNumLabel() const
        {
            return this->numLabel_;
        }

        inline void setNumLabel(const TNumLabel& numLabel)
        {
            this->numLabel_ = numLabel;
        }

        inline const TSortVal& getCustomSortVal() const
        {
            return this->customSortVal_;
        }

        inline void setCustomSortVal(const TSortVal& customSortVal)
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

        inline const TData& getCustomData() const
        {
            return this->customData_;
        }

        inline void setCustomData(const TData& customData)
        {
            this->customData_ = customData;
        }

        friend bool operator< (const CustomSortable<TNumLabel, TSortVal, TData>& l, const CustomSortable<TNumLabel, TSortVal, TData>& r)
        {
            if(l.customSortVal_ == r.customSortVal_) {
                return l.numLabel_ < r.numLabel_;
            }
            else {
                return l.customSortVal_ < r.customSortVal_;
            }
        }

        friend bool operator> (const CustomSortable<TNumLabel, TSortVal, TData>& l, const CustomSortable<TNumLabel, TSortVal, TData>& r)
        {
            if(l.customSortVal_ == r.customSortVal_) {
                return l.numLabel_ > r.numLabel_;
            }
            else {
                return l.customSortVal_ > r.customSortVal_;
            }
        }
    };


    //void countingSort(std::vector<CustomSortable> &v);
}

#endif // CUSTOMSORTABLE_H
