/*
 * NaturalNumber.cpp
 *
 * Created on: 2013-09-20
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include "NaturalNumber.h"
#include "Addition.h" // Addition::add()
#include "Subtraction.h" // Subtraction::subtract()
#include "Multiplication.h" // Multiplication::multiply()
#include "Exception.h" // Exception

namespace math {
namespace grade4 {

NaturalNumber::NaturalNumber(std::string digits) {
	// Remove leading zeroes
	size_t leadingZeroes = 0;
	size_t numberOfDigits = digits.size();
	for(size_t i=0; i<numberOfDigits-1; i++) // for first N-1 digits
		if(digits.at(i) == '0') leadingZeroes = leadingZeroes + 1; // if it's a zero mark it to be deleted
		else break; // else break
	digits.erase(0, leadingZeroes); // delete all marked zeros

	if(NaturalNumber::isValid(digits))// Check if all digits are between 48 and 57
		digits_ = digits; // set the new value
	else
		throw Exception("math::grade4::NaturalNumber::NaturalNumber(std::string digits) : Invalid digits in number\""+digits+"\"");
}

NaturalNumber::~NaturalNumber() {
}

NaturalNumber NaturalNumber::operator +(const NaturalNumber& anotherNumber) {
	return Addition::add(*this, anotherNumber);
}

NaturalNumber NaturalNumber::operator -(const NaturalNumber& anotherNumber) {
	return Subtraction::subtract(*this, anotherNumber);
}

NaturalNumber NaturalNumber::operator *(const NaturalNumber& anotherNumber) {
	return Multiplication::multiply(*this, anotherNumber);
}

NaturalNumber& NaturalNumber::operator ++(int) {
	Addition::addOne(*this);
	return *this;
}

NaturalNumber& NaturalNumber::operator --(int) {
	Subtraction::subtractOne(*this);
	return *this;
}

bool NaturalNumber::operator ==(const NaturalNumber& otherNumber)const {
	return digits_ == otherNumber.digits_;
}

bool NaturalNumber::operator !=(const NaturalNumber& otherNumber)const {
	return digits_ != otherNumber.digits_;
}

char* NaturalNumber::getTens(NaturalNumber powerOfTen) {
	size_t digitsSize = digits_.size();
	NaturalNumber counter;
	for(size_t i=0; i<digitsSize; i++){
		if(counter == powerOfTen){
			return &(digits_[digitsSize-1-i]);
		}
		counter++;
	}
	throw Exception("math::grade4::NaturalNumber::getTens(NaturalNumber powerOfTen) : No such digit.");
	return NULL;// NOT FOUND
}

bool NaturalNumber::isValid(const std::string& ref){
	 for( std::string::const_iterator i = ref.begin() ; i!=ref.end(); i++ )
		 if(*i <= 47 || *i >= 58)
			 return false;
	 return true;
}

const std::string& NaturalNumber::toString() {
	return digits_;
}

//size_t NaturalNumber::toSizeT() const {
//	std::istringstream iss(digits_);
//	size_t size;
//	iss >> size;
//	return size;
//}

const NaturalNumber NaturalNumber::ZERO = NaturalNumber::NaturalNumber("0");

} /* namespace grade1 */
} /* namespace math */
