/*
 * Subtraction.cpp
 *
 * Created on: Oct 10, 2013
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include "Subtraction.h"
#include "Exception.h" // Exception

namespace math {
namespace grade4 {

NaturalNumber Subtraction::subtract(const NaturalNumber& a, const NaturalNumber& b) {
	// Convert to string
	std::string as = a.digits_;
	std::string bs = b.digits_;
	// Get size
	size_t asSize = as.size();
	size_t bsSize = bs.size();

	// Make them have same size by adding trailing zeroes
	if(asSize > bsSize){
		bs.insert(0, asSize-bsSize, '0');
		bsSize = bs.size();
	}else if(bsSize > asSize){
		as.insert(0, bsSize-asSize, '0');
		asSize = as.size();
	}

	char tempResult[2] = {0, 0};
	char result[asSize+1];// 1 digit for '\0'
	result[asSize+1] = '\0';// marks the end of the string
	for(size_t i = asSize-1; i>0; i--){//when i=0 "i--" gets executed and i becomes MAX_SIZE which is >0 a solution would be //	if(i==0) break; inside for
		Subtraction::subtract(as[i], bs[i], tempResult);// add
		result[i+1] = tempResult[0] + 48;// put the last digit in the final result
	}
	Subtraction::subtract(as[0], bs[0], tempResult);// add
	result[1] = tempResult[0] + 48;// put the last digit in the final result
	char* r = (char*)result;
	r++;

	return NaturalNumber(std::string(r));
}

NaturalNumber& Subtraction::subtractOne(NaturalNumber& n){
	if(n.digits_ == "0") throw Exception("math::grade4::Subtraction::subtractOne(NaturalNumber&): decrement '0'");
	size_t numberSize = n.digits_.size();
	bool decrementNextDigit = false;
	char* currentDigit;
	size_t index = 0; // subtracting one from units
	do{
		currentDigit = &(n.digits_[numberSize-index++-1]);// point to the "index" digit from the right
		(*currentDigit)--; // decrement the digit
		if(*currentDigit == 47) // 47 = '0'-1 if it's -1 then set it to 0 and decrementNextDigit
		{
			*currentDigit = 48; // set it to "0"
			decrementNextDigit = true;
		}else decrementNextDigit = false;
	}while(decrementNextDigit);
	currentDigit = NULL;
	return n;
}

void Subtraction::subtract(char a, char b, char* r) {
	r[0] = a - b - r[1];
	if(r[0] >= 0){
		r[1] = 0;
	}else{
		r[0] = r[0] + 10;
		r[1] = 1;
	}
}
} /* namespace grade1 */
} /* namespace math */
