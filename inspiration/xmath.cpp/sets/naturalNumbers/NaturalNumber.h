/* 
 * File:   NaturalNumber.h
 * Author: paul
 *
 * Created on August 3, 2012, 8:55 PM
 */

#include <iostream>//for string type
#include <sstream>//for converting char to string
#include <string>//for string type

using namespace std;

#ifndef NATURALNUMBER_H
#define	NATURALNUMBER_H

class NaturalNumber {
public:
    NaturalNumber();
    NaturalNumber(string v);
    virtual ~NaturalNumber();
    string getValue();

    friend ostream& operator<<(ostream& os, const NaturalNumber& n);
    bool operator==(NaturalNumber n);
    bool operator!=(NaturalNumber n);
    bool operator<(NaturalNumber n);
    bool operator>(NaturalNumber n);
    bool operator<=(NaturalNumber n);
    bool operator>=(NaturalNumber n);
    NaturalNumber & operator+=(NaturalNumber n);
    NaturalNumber & operator++(int);
    NaturalNumber & operator-=(NaturalNumber n);
    NaturalNumber & operator--(int);
    NaturalNumber & operator*=(NaturalNumber n);
    NaturalNumber operator+(NaturalNumber n);
    NaturalNumber operator-(NaturalNumber n);
    NaturalNumber operator*(NaturalNumber n);
    NaturalNumber operator^(NaturalNumber n);
    
    static NaturalNumber ZERO;
    static NaturalNumber ONE;
    static NaturalNumber TEN;
    static pair<NaturalNumber, NaturalNumber> divmod(NaturalNumber a, NaturalNumber b);
    static NaturalNumber cmmdc(NaturalNumber a, NaturalNumber b);
    static NaturalNumber cmmmc(NaturalNumber a, NaturalNumber b);

private:
    string value;
    bool isBase10Digit(char d);
    string addDigit(char a, char b);
    string subDigit(string a, string b);
    string multiplyDigit(char a, char b);
    bool digitLessThan(char a, char b);
    string charToString(char c);
    string stripLeadingZeros(string v);

};

#endif	/* NATURALNUMBER_H */

