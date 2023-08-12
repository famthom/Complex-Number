#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

class complexType
{
    // Output the number complex
    friend ostream& operator<<(ostream& output, const complexType& cNum);
    // Input the number complex
    friend istream& operator>>(istream& input, complexType& cNum);

    /// Get the conjugate of a complexNumber using a friend function
    friend complexType operator~(complexType&);

    /// Get the absolute of a complexNumber using a friend function
    friend double operator!(complexType&);
    public:
        /** Default constructor */
        complexType();

        // get the value of a complex number
        void getComplexNumber(double& real, double& imag);
        // set the value of a complex number
        void setComplexNumber(double real, double imag);

        /// Assignation operator
        const complexType& operator=(const complexType&);

        /// Arithmetic operator of atribuition
        complexType operator+(const complexType&) const;

        /// Arithmetic operator of subtraction
        complexType operator-(const complexType&) const;

        /// Add later a function to multiplication
        //complexType operator*(void) const;

        /// Arithmetic operator for division
        complexType operator/(const complexType&) const;

        /// Get the conjugate of the complexNumber
        //complexType& operator~(void);
        /// Get the absolute value of the complexNumber
        //double operator!(void) const;

        /// Arithmetic with assignation operator
        complexType& operator+=(const complexType&);

        /// Relational operator to see if its equal
        bool operator==(const complexType&) const;

    protected:

    private:
        double realPart; //!< Member variable "realPart"
        double imaginaryPart; //!< Member variable "imaginaryPart"
};

#endif // COMPLEXTYPE_H
