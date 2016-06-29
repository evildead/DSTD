#include "BigInt/bigint.h"
#include "Utilities/utilities.h"
#include "UtilClasses/customsortable.h"
#include "FFT/fft.h"
#include <iostream>

using namespace std;
using namespace dstd;

BigInt computeFibonacciModified(unsigned int a, unsigned int b, unsigned int n)
{
    BigInt prevprev = a;
    BigInt prev = b;
    BigInt val;

    for(unsigned int i = 2; i < n; i++) {
        val = prev.power(2) + prevprev;
        prevprev = prev;
        prev = val;
    }

    return val;
}

BigInt fibonacci(unsigned int n)
{
    if(n < 3) {
        return BigInt(1);
    }

    BigInt prevprev = BigInt(1);
    BigInt prev = BigInt(1);
    BigInt val;

    for(unsigned int i = 3; i <= n; i++) {
        val = prev + prevprev;
        prevprev = prev;
        prev = val;
    }

    return val;
}

BigInt factorial(unsigned int n)
{
    if((n == 0) || (n == 1)) {
        return BigInt(1);
    }
    else if(n == 2) {
        return BigInt(2);
    }

    BigInt val(n);
    for(unsigned int i = (n-1); i >= 1; i--) {
        val *= BigInt(i);
    }

    return val;
}

int main(int argc, char *argv[])
{
    /*
    string myStr = "0001000";
    cout << trimright(myStr, "0") << '\n';
    cout << trimleft(myStr, "0") << '\n';

    string myStr2 = "\t\n        0001000 \t\t\n\r     ";
    cout << trimright(myStr2) << '\n';
    cout << trimleft(myStr2) << '\n';

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
    BigInt myBint("72634515982734674");
    myBint = myBint.power(1000);
    cout << myBint << '\n';
    */

    /*
    BigInt myBint("64");
    BigInt myOtherBint(22);
    cout << myBint * myOtherBint << '\n';
    */

    /*
    string str1, str2;
    cin >> str1 >> str2;

    string outStr = multiplyNumericStringsWithFFT(str1, str2);
    cout << BigInt(outStr) << endl;
    */

    unsigned int A, B, N;
    cin >> A;
    cin >> B;
    cin >> N;

    BigInt val = computeFibonacciModified(A, B, N);
    //BigInt val = fibonacci(A);
    //BigInt val = factorial(A);

    cout << val << '\n';
    //cout << upperPowerOfTwo(A + B) << endl;

    return 0;

}
