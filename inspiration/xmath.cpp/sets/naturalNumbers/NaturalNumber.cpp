/* 
 * File:   NaturalNumber.cpp
 * Author: paul
 * 
 * Created on August 3, 2012, 8:55 PM
 */

#include <string>//for string type

#include "NaturalNumber.h"

using namespace std;

/* Constructors & Destructor */

NaturalNumber::NaturalNumber() {
    this->value = "0";
}

NaturalNumber::NaturalNumber(string v) {
    bool error = false;
    for (int i = 0; i < v.size(); i++)
	if (!this->isBase10Digit(v[i])) {
	    throw v + " contains a non digit character";
	    error = true;
	}
    if (!error)
	this->value = stripLeadingZeros(v); //set the value
}

NaturalNumber::~NaturalNumber() {
}

/* Public functions */
string NaturalNumber::getValue() {
    return this->value;
}

/* Private functions */
bool NaturalNumber::isBase10Digit(char d) {
    return d == '0' || d == '1' || d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8' || d == '9';
}

string NaturalNumber::addDigit(char a, char b) {
    //    cout << "addDigit("<<a<<", "<<b<<"), string(new char(a))="<<string(new char(a))<<endl;
    if (a == '0') return this->charToString(b); //return string(new char(b));//this converts char to string
    if (b == '0') return this->charToString(a); //return string(new char(a));

    if (a == '1') {
	if (b == '1') return "2";
	if (b == '2') return "3";
	if (b == '3') return "4";
	if (b == '4') return "5";
	if (b == '5') return "6";
	if (b == '6') return "7";
	if (b == '7') return "8";
	if (b == '8') return "9";
	if (b == '9') return "10";
    }

    if (a == '2') {
	if (b == '1') return "3";
	if (b == '2') return "4";
	if (b == '3') return "5";
	if (b == '4') return "6";
	if (b == '5') return "7";
	if (b == '6') return "8";
	if (b == '7') return "9";
	if (b == '8') return "10";
	if (b == '9') return "11";
    }

    if (a == '3') {
	if (b == '1') return "4";
	if (b == '2') return "5";
	if (b == '3') return "6";
	if (b == '4') return "7";
	if (b == '5') return "8";
	if (b == '6') return "9";
	if (b == '7') return "10";
	if (b == '8') return "11";
	if (b == '9') return "12";
    }

    if (a == '4') {
	if (b == '1') return "5";
	if (b == '2') return "6";
	if (b == '3') return "7";
	if (b == '4') return "8";
	if (b == '5') return "9";
	if (b == '6') return "10";
	if (b == '7') return "11";
	if (b == '8') return "12";
	if (b == '9') return "13";
    }

    if (a == '5') {
	if (b == '1') return "6";
	if (b == '2') return "7";
	if (b == '3') return "8";
	if (b == '4') return "9";
	if (b == '5') return "10";
	if (b == '6') return "11";
	if (b == '7') return "12";
	if (b == '8') return "13";
	if (b == '9') return "14";
    }

    if (a == '6') {
	if (b == '1') return "7";
	if (b == '2') return "8";
	if (b == '3') return "9";
	if (b == '4') return "10";
	if (b == '5') return "11";
	if (b == '6') return "12";
	if (b == '7') return "13";
	if (b == '8') return "14";
	if (b == '9') return "15";
    }

    if (a == '7') {
	if (b == '1') return "8";
	if (b == '2') return "9";
	if (b == '3') return "10";
	if (b == '4') return "11";
	if (b == '5') return "12";
	if (b == '6') return "13";
	if (b == '7') return "14";
	if (b == '8') return "15";
	if (b == '9') return "16";
    }

    if (a == '8') {
	if (b == '1') return "9";
	if (b == '2') return "10";
	if (b == '3') return "11";
	if (b == '4') return "12";
	if (b == '5') return "13";
	if (b == '6') return "14";
	if (b == '7') return "15";
	if (b == '8') return "16";
	if (b == '9') return "17";
    }

    if (a == '9') {
	if (b == '1') return "10";
	if (b == '2') return "11";
	if (b == '3') return "12";
	if (b == '4') return "13";
	if (b == '5') return "14";
	if (b == '6') return "15";
	if (b == '7') return "16";
	if (b == '8') return "17";
	if (b == '9') return "18";
    }

    throw "addDigit:one parameter is not a digit";
}

string NaturalNumber::subDigit(string a, string b) {
    if (b == "0") return a;
    if (a == b) return "0";

    if (a == "18") {
	if (b == "1") return "17";
	if (b == "2") return "16";
	if (b == "3") return "15";
	if (b == "4") return "14";
	if (b == "5") return "13";
	if (b == "6") return "12";
	if (b == "7") return "11";
	if (b == "8") return "10";
	if (b == "9") return "9";
    }
    if (a == "17") {
	if (b == "1") return "16";
	if (b == "2") return "15";
	if (b == "3") return "14";
	if (b == "4") return "13";
	if (b == "5") return "12";
	if (b == "6") return "11";
	if (b == "7") return "10";
	if (b == "8") return "9";
	if (b == "9") return "8";
    }
    if (a == "16") {
	if (b == "1") return "15";
	if (b == "2") return "14";
	if (b == "3") return "13";
	if (b == "4") return "12";
	if (b == "5") return "11";
	if (b == "6") return "10";
	if (b == "7") return "9";
	if (b == "8") return "8";
	if (b == "9") return "7";
    }
    if (a == "15") {
	if (b == "1") return "14";
	if (b == "2") return "13";
	if (b == "3") return "12";
	if (b == "4") return "11";
	if (b == "5") return "10";
	if (b == "6") return "9";
	if (b == "7") return "8";
	if (b == "8") return "7";
	if (b == "9") return "6";
    }
    if (a == "14") {
	if (b == "1") return "13";
	if (b == "2") return "12";
	if (b == "3") return "11";
	if (b == "4") return "10";
	if (b == "5") return "9";
	if (b == "6") return "8";
	if (b == "7") return "7";
	if (b == "8") return "6";
	if (b == "9") return "5";
    }
    if (a == "13") {
	if (b == "1") return "12";
	if (b == "2") return "11";
	if (b == "3") return "10";
	if (b == "4") return "9";
	if (b == "5") return "8";
	if (b == "6") return "7";
	if (b == "7") return "6";
	if (b == "8") return "5";
	if (b == "9") return "4";
    }
    if (a == "12") {
	if (b == "1") return "11";
	if (b == "2") return "10";
	if (b == "3") return "9";
	if (b == "4") return "8";
	if (b == "5") return "7";
	if (b == "6") return "6";
	if (b == "7") return "5";
	if (b == "8") return "4";
	if (b == "9") return "3";
    }
    if (a == "11") {
	if (b == "1") return "10";
	if (b == "2") return "9";
	if (b == "3") return "8";
	if (b == "4") return "7";
	if (b == "5") return "6";
	if (b == "6") return "5";
	if (b == "7") return "4";
	if (b == "8") return "3";
	if (b == "9") return "2";
    }
    if (a == "10") {
	if (b == "1") return "9";
	if (b == "2") return "8";
	if (b == "3") return "7";
	if (b == "4") return "6";
	if (b == "5") return "5";
	if (b == "6") return "4";
	if (b == "7") return "3";
	if (b == "8") return "2";
	if (b == "9") return "1";
    }
    if (a == "9") {
	if (b == "1") return "8";
	if (b == "2") return "7";
	if (b == "3") return "6";
	if (b == "4") return "5";
	if (b == "5") return "4";
	if (b == "6") return "3";
	if (b == "7") return "2";
	if (b == "8") return "1";
    }
    if (a == "8") {
	if (b == "1") return "7";
	if (b == "2") return "6";
	if (b == "3") return "5";
	if (b == "4") return "4";
	if (b == "5") return "3";
	if (b == "6") return "2";
	if (b == "7") return "1";
    }
    if (a == "7") {
	if (b == "1") return "6";
	if (b == "2") return "5";
	if (b == "3") return "4";
	if (b == "4") return "3";
	if (b == "5") return "2";
	if (b == "6") return "1";
    }
    if (a == "6") {
	if (b == "1") return "5";
	if (b == "2") return "4";
	if (b == "3") return "3";
	if (b == "4") return "2";
	if (b == "5") return "1";
    }
    if (a == "5") {
	if (b == "1") return "4";
	if (b == "2") return "3";
	if (b == "3") return "2";
	if (b == "4") return "1";
    }
    if (a == "4") {
	if (b == "1") return "3";
	if (b == "2") return "2";
	if (b == "3") return "1";
    }
    if (a == "3") {
	if (b == "1") return "2";
	if (b == "2") return "1";
    }
    if (a == "2" && b == "1") return "1";

    return "0";
}

string NaturalNumber::multiplyDigit(char a, char b) {
    //    cout << "multiplyDigit("<<a<<", "<<b<<")"<<endl;
    if (a == '0' || b == '0') return "0";
    if (a == '1') return this->charToString(b);
    if (b == '1') return this->charToString(a);

    if (a == '2') {
	if (b == '2') return "4";
	if (b == '3') return "6";
	if (b == '4') return "8";
	if (b == '5') return "10";
	if (b == '6') return "12";
	if (b == '7') return "14";
	if (b == '8') return "16";
	if (b == '9') return "18";
    }

    if (a == '3') {
	if (b == '2') return "6";
	if (b == '3') return "9";
	if (b == '4') return "12";
	if (b == '5') return "15";
	if (b == '6') return "18";
	if (b == '7') return "21";
	if (b == '8') return "24";
	if (b == '9') return "27";
    }

    if (a == '4') {
	if (b == '2') return "8";
	if (b == '3') return "12";
	if (b == '4') return "16";
	if (b == '5') return "20";
	if (b == '6') return "24";
	if (b == '7') return "28";
	if (b == '8') return "32";
	if (b == '9') return "36";
    }

    if (a == '5') {
	if (b == '2') return "10";
	if (b == '3') return "15";
	if (b == '4') return "20";
	if (b == '5') return "25";
	if (b == '6') return "30";
	if (b == '7') return "35";
	if (b == '8') return "40";
	if (b == '9') return "45";
    }

    if (a == '6') {
	if (b == '2') return "12";
	if (b == '3') return "18";
	if (b == '4') return "24";
	if (b == '5') return "30";
	if (b == '6') return "36";
	if (b == '7') return "42";
	if (b == '8') return "48";
	if (b == '9') return "54";
    }

    if (a == '7') {
	if (b == '2') return "14";
	if (b == '3') return "21";
	if (b == '4') return "28";
	if (b == '5') return "35";
	if (b == '6') return "42";
	if (b == '7') return "49";
	if (b == '8') return "56";
	if (b == '9') return "63";
    }

    if (a == '8') {
	if (b == '2') return "16";
	if (b == '3') return "24";
	if (b == '4') return "32";
	if (b == '5') return "40";
	if (b == '6') return "48";
	if (b == '7') return "56";
	if (b == '8') return "64";
	if (b == '9') return "72";
    }

    if (a == '9') {
	if (b == '2') return "18";
	if (b == '3') return "27";
	if (b == '4') return "36";
	if (b == '5') return "45";
	if (b == '6') return "54";
	if (b == '7') return "63";
	if (b == '8') return "72";
	if (b == '9') return "81";
    }

    throw "one parameter is not a digit";
}

bool NaturalNumber::digitLessThan(char a, char b) {
    if (a != '0' && b == '0') return false;
    if (a == '0' && b != '0') return true;

    if (b == '1' && a == '0') return true;
    if (b == '2' && (a == '0' || a == '1')) return true;
    if (b == '3' && (a == '0' || a == '1' || a == '2')) return true;
    if (b == '4' && (a == '0' || a == '1' || a == '2' || a == '3')) return true;
    if (b == '5' && (a == '0' || a == '1' || a == '2' || a == '3' || a == '4')) return true;
    if (b == '6' && (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5')) return true;
    if (b == '7' && (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6')) return true;
    if (b == '8' && (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7')) return true;
    if (b == '9' && (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8')) return true;

    return false;
}

string NaturalNumber::stripLeadingZeros(string v) {
    while (v.substr(0, 1) == "0" && v.size() > 1)
	v = v.substr(1);
    return v;
}

/* Operators */

/* Addition */
NaturalNumber & NaturalNumber::operator+=(NaturalNumber n) {
    string as = this->getValue();
    string bs = n.getValue();

    //adding leading zeros
    while (as.size() != bs.size()) {
	if (as.size() < bs.size())
	    as = "0" + as;
	else
	    bs = "0" + bs;
    }
    //    cout<<"as="<<as<<endl<<"bs="<<bs<<endl;

    string s = "", st;
    bool carryIn = false; //if false carryIn=0 else carryIn=1
    for (int i = as.size() - 1; i >= 0; i--) {
	st = this->addDigit(as.at(i), bs.at(i)); //we add digits by column
	//        cout << "carryIn="<<carryIn<<", st="<<st<<" created from as.at("<<i<<")="<<as.at(i)<<" + "<<bs.at(i)<<"=bs.at("<<i<<")"<<endl;
	if (carryIn) {//to the sum we add a carryIn, if we have one
	    //If there is a carryIn then it is '1' and it's added to the last digit
	    if (st.size() == 2) {
		st = st.at(0) + addDigit(st.at(1), '1');
	    } else {
		st = addDigit(st.at(0), '1');
	    }
	}
	if (st.size() == 2) {//if the sum is a number we set the carryIn to true
	    if (i != 0) {
		carryIn = true;
		s = st.at(1) + s;
	    } else {
		s = st + s; //there is no point in setting carryIn
	    }
	} else {
	    carryIn = false;
	    s = st + s;
	}
	//    cout << "s="<<s<<endl;
    }

    this->value = stripLeadingZeros(s);
    return *this;
}

NaturalNumber NaturalNumber::operator+(NaturalNumber n) {
    NaturalNumber r = *this;
    r += n;
    return r;
}

NaturalNumber & NaturalNumber::operator++(int n) {
    //    NaturalNumber snu("791");
    //    if(*this==snu){
    //        cout<<"this="<<this->getValue()<<endl;
    //        *this += one;
    //        cout<<"this incremented is ="<<this->getValue()<<endl;
    //    }else
    //    cout << "++ OPERATOR Before +1 =|"<<this->getValue()<<"|"<<endl;
    *this += NaturalNumber::ONE;
    //    cout << "++ OPERATOR After +1 =|"<<this->getValue()<<"|"<<endl;
    return *this;
}

/* Multiplication */
NaturalNumber & NaturalNumber::operator*=(NaturalNumber n) {
    /*Takes 9->10 seconds to compute 666 666 * 666 666*/
    /*
	NaturalNumber p("0");
	for(NaturalNumber i("0"); i<n; i++){
    //        cout << "*= operator 1, this="<<this->getValue()<<", p="<<p.getValue()<< ", i="<<i.getValue() << endl;
	    p += *this;
    //        cout << "*= operator 2, this="<<this->getValue()<<", p="<<p.getValue()<< ", i="<<i.getValue() << endl;
	}
	this->value = p.getValue();
     */

    /*Takes 500ms seconds to compute 250*250*...*250 250 times*/
    char m = '0';
    string rp[n.getValue().size()];
    //    cout << this->getValue() << endl << n.getValue() << endl << "========== *" << endl;

    for (int i = n.getValue().size() - 1; i >= 0; i--) {//for each digit in the bottom number
	for (int j = 1; j < n.getValue().size() - i; j++) {
	    if (rp[n.getValue().size() - i - 1] != "")
		rp[n.getValue().size() - i - 1] = "0" + rp[n.getValue().size() - i - 1];
	    else
		rp[n.getValue().size() - i - 1] = "0";
	}

	for (int j = this->getValue().size() - 1; j > 0; j--) {
	    //            cout << n.getValue().at(i) << "*" << this->getValue().at(j) << "=" << this->multiplyDigit(n.getValue().at(i), this->getValue().at(j));
	    NaturalNumber rt(this->multiplyDigit(n.getValue().at(i), this->getValue().at(j)));
	    if (m != '0') {
		NaturalNumber mn(charToString(m));
		rt += mn;
	    }
	    //            cout << "+m=" << rt.getValue() << " => scriem ";
	    if (rp[n.getValue().size() - i - 1] != "")
		rp[n.getValue().size() - i - 1] = rt.getValue().at(rt.getValue().size() - 1) + rp[n.getValue().size() - i - 1];
	    else
		rp[n.getValue().size() - i - 1] = rt.getValue().at(rt.getValue().size() - 1);
	    //            cout << "rp[" << (n.getValue().size() - i - 1) << "]=" << rp[n.getValue().size() - i - 1];
	    if (rt.getValue().size() > 1)
		m = rt.getValue().at(0);
	    else
		m = '0';
	    //            cout << " si tinem minte m=" << m << endl;
	}
	//        cout << n.getValue().at(i) + "*" << this->getValue().at(0) << "=" << this->multiplyDigit(n.getValue().at(i), this->getValue().at(0));
	NaturalNumber rt(this->multiplyDigit(n.getValue().at(i), this->getValue().at(0)));
	if (m != '0') {
	    NaturalNumber mn(charToString(m));
	    rt += mn;
	}
	//        cout << "+m=" << rt.getValue() << " => scriem ";
	if (rp[n.getValue().size() - i - 1] != "")
	    rp[n.getValue().size() - i - 1] = rt.getValue() + rp[n.getValue().size() - i - 1];
	else
	    rp[n.getValue().size() - i - 1] = rt.getValue();
	m = '0';
	//        cout << rp[n.getValue().size() - i - 1] << endl;
    }

    NaturalNumber r = NaturalNumber::ZERO;
    for (int i = 0; i < (sizeof rp / sizeof (string)); i++) {
	NaturalNumber tn(rp[i]);
	r += tn;
    }
    this->value = r.getValue();
    return *this;
}

NaturalNumber NaturalNumber::operator*(NaturalNumber n) {
    NaturalNumber r = n;
    r *= *this;
    return r;
}

/* Substraction */
NaturalNumber & NaturalNumber::operator-=(NaturalNumber n) {
    if (*this<n)
	throw "impossible";
    else if (*this == n){
	*this = ZERO;
	return *this;
    }else if (n == ZERO)
	return *this;
    else {
	/* 9 999 999 - 1 calculated in 149 seconds using this algorithm */
	//	NaturalNumber d = NaturalNumber::ZERO;
	//	while(d+n!=*this)
	//	    d += NaturalNumber::ONE;
	//	this->value = d.getValue();

	/* 9 999 999 -1 calculated in 118 milliseconds using this algorithm*/
	string as = this->getValue();
	string bs = n.getValue();
	while (bs.size() < as.size())
	    bs = "0" + bs;
	//	cout << as << "-\n" << bs << endl;
	string d = "", dt;
	for (int i = as.size() - 1; i >= 0; i--) {
	    if (digitLessThan(as.at(i), bs.at(i))) {
		dt = as.at(i);
		for (int j = i - 1; j >= 0; j--)
		    if (as.at(j) == '0') {
			as = as.substr(0, j) + '9' + as.substr(j + 1, as.size());
			//			cout << "nu o putut sa se imprumute si am setat la j=" << j << " pe 9 => as=" << as << endl;
		    } else {
			as = as.substr(0, j) + subDigit(charToString(as.at(j)), "1") + as.substr(j + 1, as.length());
			//			cout << "mi-o imprumutat la j=" << j << " => as=" << as << endl;
			break;
		    }
		dt = subDigit("1" + dt, charToString(bs.at(i)));
		//		cout << "1" << dt << "-" << string(bs.at(i)) << " => dt=" << dt << endl;
	    } else {
		dt = subDigit(charToString(as.at(i)), charToString(bs.at(i)));
		//		cout << string(as.at(i) << "-" << string(bs.at(i)) << " => dt=" << dt << endl;
	    }
	    d = dt + d;
	    //	    cout << dt << endl;
	}
	this->value = stripLeadingZeros(d);
    }
}

NaturalNumber & NaturalNumber::operator--(int n) {
    *this -= NaturalNumber::ONE;
    return *this;
}

NaturalNumber NaturalNumber::operator-(NaturalNumber n) {
    NaturalNumber r = *this;
    r -= n;
    return r;
}

/* Exponentiation */
NaturalNumber NaturalNumber::operator^(NaturalNumber n) {
    if (n == NaturalNumber::ONE) return NaturalNumber::ONE;
    if (n == NaturalNumber::ONE) return *this;
    if (*this == NaturalNumber::ONE) return NaturalNumber::ONE;

    NaturalNumber p = NaturalNumber::ONE;
    for (NaturalNumber i("1"); i <= n; i++)
	p *= *this;

    return p;
}

/*Equality and inequality operators*/

bool NaturalNumber::operator==(NaturalNumber n) {
    return this->getValue() == n.getValue();
}

bool NaturalNumber::operator!=(NaturalNumber n) {
    return this->getValue() != n.getValue();
}

bool NaturalNumber::operator<(NaturalNumber n) {
    if (this->getValue().size() < n.getValue().size()) return true;
    else if (n.getValue().size() < this->getValue().size()) return false;
    else {
	for (int i = 0; i<this->getValue().size(); i++) {
	    if (this->digitLessThan(this->getValue()[i], n.getValue()[i]))
		return true;
	    else if (this->getValue()[i] != n.getValue()[i])
		return false;
	}
	return false;
    }

}

bool NaturalNumber::operator>(NaturalNumber n) {
    return *this != n && n<*this;
}

bool NaturalNumber::operator<=(NaturalNumber n) {
    return *this<n || *this == n;
}

bool NaturalNumber::operator>=(NaturalNumber n) {
    return *this>n || *this == n;
}

/* OTHER STUFF */
string NaturalNumber::charToString(char c) {
    stringstream ss;
    string s;
    ss << c;
    ss >> s;
    return s;
}

ostream& operator<<(ostream& os, const NaturalNumber& n) {
    os << n.value;
}

/* STATIC STUFF */

NaturalNumber NaturalNumber::ZERO = NaturalNumber("0");
NaturalNumber NaturalNumber::ONE = NaturalNumber("1");
NaturalNumber NaturalNumber::TEN = NaturalNumber("10");

pair<NaturalNumber, NaturalNumber> NaturalNumber::divmod(NaturalNumber a, NaturalNumber b) {
    pair<NaturalNumber, NaturalNumber> p;
    p.first = NaturalNumber::ZERO;
    while (((p.first + NaturalNumber::ONE) * b) <= a)
	p.first += NaturalNumber::ONE;
    p.second = a - (p.first * b);
    return p;
}
NaturalNumber NaturalNumber::cmmdc(NaturalNumber a, NaturalNumber b){
    NaturalNumber r = divmod(a,b).second;
    while(r != ZERO){
	a = b;
	b = r;
	r = divmod(a, b).second;
    }
    return b;
}
NaturalNumber NaturalNumber::cmmmc(NaturalNumber a, NaturalNumber b){
    return divmod( a*b , cmmdc(a,b) ).first;
}

/*End of file NaturalNumber.cpp*/