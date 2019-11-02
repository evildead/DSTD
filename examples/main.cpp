/*************************************************
 *                                               *
 *   Author: Danilo Carrabino                    *
 *                                               *
 *************************************************/


#include "BigInt/bigint.h"
#include "Utilities/utilities.h"
#include "UtilClasses/customsortable.h"
#include "FFT/fft.h"
#include <iostream>

using namespace std;
using namespace dstd;

int main(int argc, char *argv[])
{
    // A BUNCH OF TESTS

    /*
    // TRIM Tests ///////////////////////////////////////////////////
    cout << "**************************************" << endl;
    cout << "*** String manipulation: TRIM TEST ***" << endl;
    cout << "**************************************" << endl;
    string myStr = "0001000";
    cout << "Trimming 0's on the right of 0001000 returns:" << endl;
    cout << trimright(myStr, "0") << endl;
    cout << endl;
    cout << "Trimming 0's on the left of 0001000 returns:" << endl;
    cout << trimleft(myStr, "0") << endl;
    cout << endl;

    string myStr2 = "\t\n        0001000 \t\t\n\r     ";
    cout << "Function trimright with default parameters on" << endl;
    cout << "\\t\\n        0001000 \\t\\t\\n\\r      returns:" << endl;
    cout << trimright(myStr2) << endl;
    cout << endl;
    cout << "Function trimleft with default parameters on" << endl;
    cout << "\\t\\n        0001000 \\t\\t\\n\\r      returns:" << endl;
    cout << trimleft(myStr2) << endl;
    cout << endl;
    */

    // BigInt Tests /////////////////////////////////////////////////
    /*
    //BigInt myBint("9852084579746529486592485678465494649");
    BigInt myBint("  0000000029764298383429367");
    BigInt myOtherBint(29764298383429367);
    BigInt myThirdBint(19764293383421995);
    myBint += myOtherBint;
    myBint -= myThirdBint;

    cout << myBint << '\n';
    cout << myOtherBint << '\n';
    cout << (myThirdBint - myOtherBint) << '\n';

    if(myBint < myOtherBint) {
        cout << "myBint is smaller than myOtherBint\n";
    }
    else if(myBint > myOtherBint) {
        cout << "myBint is greater than myOtherBint\n";
    }
    */

    /*
    BigInt myBint("-72634515982734674");
    BigInt myOtherBint(-14293756);
    myBint *= myOtherBint;
    cout << myBint << '\n';

    ++myBint;
    cout << myBint++ << '\n';

    cout << --myBint << '\n';

    myBint--;
    cout << myBint << '\n';
    */

    /*
    cout << "**************************" << endl;
    cout << "*** BigInt: Power TEST ***" << endl;
    cout << "**************************" << endl;
    BigInt myBint("72634515982734674");
    myBint = myBint.power(100);
    cout << "72634515982734674 ^ 100 is:" << endl;
    cout << myBint << endl;
    */

    /*
    BigInt myBint("6464827368237648237443432323");
    BigInt myOtherBint("97284664287298375610074623623434");
    cout << "6464827368237648237443432323 multiplied by 97284664287298375610074623623434 is:" << endl;
    cout << myBint * myOtherBint << endl;
    */

    /*
    string str1, str2;
    cin >> str1 >> str2;

    string outStr = multiplyNumericStringsWithFFT(str1, str2);
    cout << BigInt(outStr) << endl;
    */

    /*
    // computeFibonacciModified Test ////////////////////////////////
    unsigned int A, B, N;
    cin >> A;
    cin >> B;
    cin >> N;

    //BigInt val = computeFibonacciModified(A, B, N);
    //BigInt val = fibonacci(A);
    BigInt val = factorial(A);

    cout << val << endl;
    //cout << upperPowerOfTwo(A + B) << endl;
    */

    /*
    // getAnagramsOccurrences Tests /////////////////////////////////
    string haystack, needle;
    cin >> haystack;
    cin >> needle;

    vector<int> occurrences = getAnagramsOccurrences(haystack, needle);

    for(auto i = occurrences.begin(); i != occurrences.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
    */

    /*
    // CustomSortable and countingSort Tests ////////////////////////
    CustomSortable<long long, int, string> myCS1(59273862283437, 4, "59273862283437", "First");
    CustomSortable<long long, int, string> myCS2(14273862283417, 2, "14273862283417", "Second");
    CustomSortable<long long, int, string> myCS3(14277777283417, 1, "14277777283417", "Third");
    CustomSortable<long long, int, string> myCS4(64273888888413, 3, "64273888888413", "Fourth");

    vector<CustomSortable<long long, int, string> > v;
    v.push_back(myCS1);
    v.push_back(myCS2);
    v.push_back(myCS3);
    v.push_back(myCS4);

    countingSort<long long, string>(v);
    */

    /*
    // LCS Tests ////////////////////////////////////////////////////
    vector<string> lcsStrings;
    string a = "ABCDEF";
    string b = "FBDAMN";
    //string a = "SHINCHAN";
    //string b = "NOHARAAA";
    int retVal = lcs(a, b, lcsStrings, true);
    */

    return 0;

}
