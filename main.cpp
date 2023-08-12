#include <iostream>
#include <iomanip>
#include "complexType.h"

using namespace std;

int main()
{
    complexType clxNum1, clxNum2;
    cout << "Input the first real and so the imaginary number complex (Ex: (4, 5) in sequence: ";
    cin >> clxNum1;
    cout << endl << "Input the second real and so the imaginary number complex: ";
    cin >> clxNum2;
    cout << "Complex Number 1: " << clxNum1 << setw(5) << "Complex Number 2: " << clxNum2 << endl;
    cout << endl << "The absolute value of c.Number one: ";
    cout << !clxNum1 << endl;
    cout << "The conjugate value of c.Number one: ";
    cout << ~clxNum1 << endl;
    cout << endl << "The absolute value of c.Number two: ";
    cout << !clxNum2 << endl;
    cout << "The conjugate value of c.Number two: ";
    cout << ~clxNum2 << endl;
    int x = 0;
    while (x == 0) {
        cout << endl << "Digit what equation do you want to do between them, or just press anything else"
                                << "that will quit in anyways: " << endl;
        cout << "Arithmetic options: + , - , / : ";
        string equa;
        cin >> equa;
        if(equa == "+")
            cout << clxNum1+clxNum2;
        else if(equa == "-")
            cout << clxNum1-clxNum2;
        else if(equa == "/")
            cout << clxNum1/clxNum2;
        cout << endl;

    }
    return 0;
}
