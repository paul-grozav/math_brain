/*
 * NaturalNumber.cpp
 *
 * Created on: 2013-09-20
 * Begun by: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include "NaturalNumber.h"
#include "Addition.h" // Addition::add()
#include <iostream>
using namespace std;

namespace math {
namespace grade1 {

NaturalNumber::NaturalNumber(std::string digits) {
	size_t leadingZeroes = 0;
	size_t numberOfDigits = digits.size();
	for(size_t i=0; i<numberOfDigits-1; i++) // for first N-1 digits
		if(digits.at(i) == '0') leadingZeroes = leadingZeroes + 1; // if it's a zero mark it to be deleted
		else break; // else break
	digits.erase(0, leadingZeroes); // delete all marked zeros
	digits_ = digits; // set the new value
}

NaturalNumber::~NaturalNumber() {
}

bool NaturalNumber::isValid(const std::string& ref){
	 for( std::string::const_iterator i = ref.begin() ; i!=ref.end(); i++ )
		 if(*i <= 47 || *i >= 58)
			 return false;
	 return true;
}
NaturalNumber NaturalNumber::operator +(const NaturalNumber& anotherNumber) {
	return Addition::add(*this, anotherNumber);
}

std::string NaturalNumber::toString() const {
	return digits_;
}

} /* namespace grade1 */
} /* namespace math */
