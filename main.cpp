#include "BigInt/bigint.h"
#include "Utilities/utilities.h"
#include <iostream>

using namespace std;
using namespace dstd;

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

    BigInt myBint("-72634515982734674");
    BigInt myOtherBint(-14293756);
    myBint *= myOtherBint;
    cout << myBint << '\n';

    ++myBint;
    cout << myBint++ << '\n';

    cout << --myBint << '\n';

    myBint--;
    cout << myBint << '\n';

    return 0;
}
