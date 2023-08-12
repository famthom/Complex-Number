#include <iostream>
#include <iomanip>
#include "complexType.h"

using namespace std;

int main()
{
    complexType clxNum1, clxNum2;
    clxNum1.setComplexNumber(6, 20);
    clxNum2.setComplexNumber(5, 14);
    //cout << !clxNum1;
    //cout << ~clxNum1;

    cout << clxNum1 / clxNum2;
    int a = 10, b = -19;
    b += a;
    return 0;
}
