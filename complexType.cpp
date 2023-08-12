#include "complexType.h"

ostream& operator<<(ostream& output, const complexType& cNum) {
    output << "(" << cNum.realPart << ", " << cNum.imaginaryPart
                    << "i) ";
    return output;
}

istream& operator>>(istream& input, complexType& cNum) {
    char ch;
    input >> ch;
    input >> cNum.realPart;
    input >> ch;
    input >> cNum.imaginaryPart;
    input >> ch;

    return input;
}

void complexType::getComplexNumber(double& real, double& imag) {
    real = realPart;
    imaginaryPart = imag;
}

void complexType::setComplexNumber(double real, double imag) {
    realPart = real;
    imaginaryPart = imag;
}

const complexType& complexType::operator=(const complexType& obj) {
    realPart = obj.realPart;
    imaginaryPart = obj.imaginaryPart;

    return *this;
}

complexType& complexType::operator+=(const complexType& obj) {
    realPart += obj.realPart;
    imaginaryPart += obj.imaginaryPart;

    return *this;
}

complexType complexType::operator+(const complexType& obj) const {
    complexType temp;
    temp.realPart = realPart + obj.realPart;
    temp.imaginaryPart = imaginaryPart + obj.imaginaryPart;

    return temp;
}

complexType complexType::operator-(const complexType& obj) const {
    complexType temp;
    temp.realPart = realPart;
    temp.imaginaryPart = imaginaryPart;

    complexType objTemp;
    objTemp.realPart = obj.realPart;
    objTemp.imaginaryPart = obj.imaginaryPart;

    cout << "(" << temp.realPart << " - (" << objTemp.realPart << ") +";
    cout << "(" << temp.imaginaryPart << " - (" << objTemp.imaginaryPart << ")i " << endl;

    temp.imaginaryPart = temp.imaginaryPart - temp.imaginaryPart - temp.imaginaryPart;
    if (temp.realPart > 0)
        cout << "(" << temp.realPart << " + " << objTemp.realPart << ") +";
    else
        cout << "(" << temp.realPart << " " << objTemp.realPart << ") +";;
    objTemp.imaginaryPart = objTemp.imaginaryPart - objTemp.imaginaryPart - objTemp.imaginaryPart;

    if (temp.imaginaryPart >= 0)
        cout << "(" << temp.imaginaryPart << " + " << objTemp.imaginaryPart << ")i " << endl;
    else
        cout << "(" << temp.imaginaryPart << " " << objTemp.imaginaryPart << ")i " << endl;
    temp.realPart += objTemp.realPart;
    temp.imaginaryPart += objTemp.imaginaryPart;
    cout << temp.realPart << " + ";
    cout << temp.imaginaryPart << "i" << endl;

    return temp;
}

complexType complexType::operator*(void) const {

}

complexType complexType::operator/(const complexType& obj) const {
    /// Temp works likes the conjugate of complexType obj
    complexType temp;
    temp.realPart = obj.realPart;
    temp.imaginaryPart = obj.imaginaryPart;

    /// It substitute the class complexType values to not touch into the caller base type;
    complexType baseTemp;
    baseTemp.realPart = realPart;
    baseTemp.imaginaryPart = imaginaryPart;

    /// It substitute the parameter class complexType obj, to not interfer in its values;
    complexType objBaseTemp;
    objBaseTemp.realPart = obj.realPart;
    objBaseTemp.imaginaryPart = obj.imaginaryPart;

    ~temp;
    cout << setw(7) << "(" << baseTemp.realPart << ", " << baseTemp.imaginaryPart << "i) " << setw(3)
                        << "(" << temp.realPart << ", " << temp.imaginaryPart << "i) "<< endl;
    cout << setw(4) << setfill('-') << setw(17) << " X " << setw(17) << " " << setfill(' ') << endl;
    cout << setw(7) << "(" << objBaseTemp.realPart << ", " << objBaseTemp.imaginaryPart << "i) "  << setw(3)
                    << "(" << temp.realPart << temp.imaginaryPart << "i) " << endl << endl;

    double realPart2;
    double imagPart2;

    baseTemp.realPart *= temp.realPart;
    realPart2 = realPart * temp.imaginaryPart;
    baseTemp.imaginaryPart *= temp.realPart;
    imagPart2 = imaginaryPart * temp.imaginaryPart;

    double objRealP2;
    double objImagP2;

    objBaseTemp.realPart *= temp.realPart;
    objRealP2 = obj.realPart * temp.imaginaryPart;
    objBaseTemp.imaginaryPart *= temp.realPart;
    objImagP2 = obj.imaginaryPart * temp.imaginaryPart;

    cout << setw(7) << baseTemp.realPart << " + " << realPart2 << "i + " << baseTemp.imaginaryPart << "i + " << imagPart2 << "(-1) " << endl;
    cout << setfill('-') << setw(17) << " X " << setw(17) << " " << setfill(' ') << endl;
    cout << setw(7) << objBaseTemp.realPart << " + " << objRealP2 << "i + " << objBaseTemp.imaginaryPart << "i + " << objImagP2 << "(-1) " << endl;

    baseTemp.imaginaryPart = realPart2 + baseTemp.imaginaryPart;
    imagPart2 = imagPart2 - imagPart2 - imagPart2;


    objBaseTemp.imaginaryPart = objBaseTemp.imaginaryPart + objRealP2;
    objImagP2 = objImagP2 - objImagP2 - objImagP2;


    cout << endl;
    cout << setw(7) << baseTemp.realPart << " + " << baseTemp.imaginaryPart << "i + " << imagPart2 << endl;
    cout << setfill('-') << setw(17) << " X " << setw(17) << " " << setfill(' ') << endl;
    cout << setw(7) << objBaseTemp.realPart << " + " << objBaseTemp.imaginaryPart << "i + " << objImagP2 << endl;

    baseTemp.realPart = baseTemp.realPart + imagPart2;
    objBaseTemp.realPart = objBaseTemp.realPart + objImagP2;
    cout << endl;
    cout << setw(7) << baseTemp.realPart << " + " << baseTemp.imaginaryPart << "i " << endl;
    cout << setfill('-') << setw(20) << " " << setfill(' ') << endl;
    cout << setw(7) << objBaseTemp.realPart << " + " << objBaseTemp.imaginaryPart << "i " << endl;

    cout << endl;
    cout << setfill('*') << setw(10) << "Final result: " << setw(10) << setfill(' ') << endl;
    cout << setw(10) << baseTemp.realPart << setw(7) << baseTemp.imaginaryPart << endl;
    cout << setw(6) << " " << setfill('-') << setw(6) << " " << setfill(' ') << setw(1) << " " << setfill('-') << setw(6) << " " << setfill(' ') << endl;
    cout << setw(10) << objBaseTemp.realPart << setw(7) << objBaseTemp.realPart << endl;

    cout << endl << "The result of the fraction is:  " << baseTemp.realPart / objBaseTemp.realPart
                    << " + " << baseTemp.imaginaryPart / objBaseTemp.realPart << "i " << endl;
    return baseTemp;
}

/// Return the absolute value of the number
/*double complexType::operator!(void) const {
    complexType temp;
    double absoluteNumber;
    temp.realPart = realPart * realPart;
    temp.imaginaryPart = imaginaryPart * imaginaryPart;
    absoluteNumber = temp.realPart + temp.imaginaryPart;
    absoluteNumber = sqrt(absoluteNumber);

    return absoluteNumber;
}*/

double operator!(complexType& obj) {
    complexType temp;
    double absoluteNumber;
    temp.realPart = obj.realPart * obj.realPart;
    temp.imaginaryPart = obj.imaginaryPart * obj.imaginaryPart;
    absoluteNumber = temp.realPart + temp.imaginaryPart;
    absoluteNumber = sqrt(absoluteNumber);

    return absoluteNumber;
}

/// Returns the conjugate of the number
//complexType& complexType::operator~(void) {
//    imaginaryPart = imaginaryPart - imaginaryPart - imaginaryPart;
//    return *this;
//}

complexType& operator~(complexType& obj) {
    obj.imaginaryPart = obj.imaginaryPart - obj.imaginaryPart - obj.imaginaryPart;
    return obj;
}

bool complexType::operator==(const complexType& obj) const {
    return (realPart == obj.realPart) && (imaginaryPart == obj.imaginaryPart);
}

complexType::complexType()
{
    //ctor
}
