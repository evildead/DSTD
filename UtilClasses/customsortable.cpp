#include "customsortable.h"
using namespace dstd;

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

/*
void dstd::countingSort(std::vector<CustomSortable> &v)
{
    int vSize = (int)v.size();
    if(vSize < 2) {
        return;
    }

    int i, j, k;

    // compute csmax and csmin
    CustomSortable csmax = v[0];
    CustomSortable csmin = v[0];
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
    std::vector< std::vector<CustomSortable> > C(cSize, std::vector<CustomSortable>());
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
*/
