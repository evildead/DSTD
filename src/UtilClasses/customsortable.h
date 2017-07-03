/*************************************************
 *                                               *
 *   Author: Danilo Carrabino                    *
 *                                               *
 *************************************************/


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


    /*
    countingSort(A[])
       //Calcolo degli elementi max e min
       max ← A[0]
       min ← A[0]
       for i ← 1 to length[A] do
          if (A[i] > max) then
             max ← A[i]
          else if(A[i] < min) then
             min ← A[i]

       //Costruzione dell'array C
       * crea un array C di dimensione max - min + 1
       for i ← 0 to length[C] do
          C[i] ← 0                                 //inizializza a zero gli elementi di C
       for i ← 0 to length[A] do
          C[A[i] - min] = C[A[i] - min] + 1            //aumenta il numero di volte che si è incontrato il valore

       //Ordinamento in base al contenuto dell'array delle frequenze C
       k ← 0                                       //indice per l'array A
       for i ← 0 to length[C] do
          while C[i] > 0 do                        //scrive C[i] volte il valore (i + min) nell'array A
             A[k] ← i + min
             k ← k + 1
             C[i] ← C[i] - 1
    */
    template <class TNumLabel, class TData = nullptr_t>
    void countingSort(std::vector<CustomSortable<TNumLabel, int, TData> > &v)
    {
        int vSize = (int)v.size();
        if(vSize < 2) {
            return;
        }

        int i, j, k;

        // compute csmax and csmin
        CustomSortable<TNumLabel, int, TData> csmax = v[0];
        CustomSortable<TNumLabel, int, TData> csmin = v[0];
        for(i = 1; i < vSize; i++) {
            if((v[i] > csmax)) {
                csmax = v[i];
            }
            else if((v[i] < csmin)) {
                csmin = v[i];
            }
        }

        // build array C
        int cSize = (int)(csmax.getCustomSortVal() - csmin.getCustomSortVal() + 1);
        std::vector< std::vector<CustomSortable<TNumLabel, int, TData> > > C(cSize, std::vector<CustomSortable<TNumLabel, int, TData> >());
        for(i = 0; i < vSize; i++) {
            int tmpIndex = (int)(v[i].getCustomSortVal() - csmin.getCustomSortVal());
            C[tmpIndex].push_back(v[i]);
        }

        // Sort based on content of frequency array C
        k = 0;
        for(i = 0; i < cSize; i++) {
            for(j = 0; j < (int)C[i].size(); j++) {
                v[k++] = C[i][j];
            }
        }
    }
}

#endif // CUSTOMSORTABLE_H
