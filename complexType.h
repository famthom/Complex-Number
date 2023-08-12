#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

class complexType
{
    friend ostream& operator<<(ostream& output, const complexType& cNum);
    friend istream& operator>>(istream& input, complexType& cNum);

    friend complexType& operator~(complexType&);
    friend double operator!(complexType&);
    public:
        /** Default constructor */
        complexType();

        void getComplexNumber(double& real, double& imag);
        void setComplexNumber(double real, double imag);

        const complexType& operator=(const complexType&);

        complexType operator+(const complexType&) const;
        complexType operator-(const complexType&) const;
        complexType operator*(void) const;
        complexType operator/(const complexType&) const;

        /// Get the conjugate of the complexNumber
        //complexType& operator~(void);
        /// Get the absolute value of the complexNumber
        //double operator!(void) const;

        complexType& operator+=(const complexType&);

        bool operator==(const complexType&) const;

    protected:

    private:
        double realPart; //!< Member variable "realPart"
        double imaginaryPart; //!< Member variable "imaginaryPart"
};

#endif // COMPLEXTYPE_H
