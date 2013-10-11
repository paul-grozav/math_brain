/*
 * Addition.cpp
 *
 * Created on: 2013-09-20
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include "Addition.h"
#include "NaturalNumber.h" // NaturalNumber
#include <string> // std::string
#include <sstream> // std::stringstream
#include <iostream> // std::cout
#include <cstring> // strlen()

using namespace std;

namespace math {
namespace grade1 {

void Addition::add(char a, char b, char* r) {
	r[0] = a + b + r[1] - 2 * 48; // set the result. We subtract 48 twice, once for a and once for b
	if (r[0] > 9) {
		r[0] = r[0] - 10; // get last digit of number( since >9 )
		r[1] = 1;// set the carryOut ( r[1] )
	} else {
		r[1] = 0;// set the carryOut ( r[1] )
	}
}

NaturalNumber Addition::add(const NaturalNumber& a, const NaturalNumber& b) {
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

	char tempSum[2] = {0, 0};
	char result[asSize+2];// One digit greater than the largest number, we'll remove that digit if needed + 1 digit for '\0'
	result[asSize+1] = '\0';// Marks the end of the string
	result[0] = '1';// Needed if the sum is one digit larger than the terms like in 9+8 ... always starts with a 1
	for(size_t i = asSize-1; i>0; i--){//when i=0 "i--" gets executed and i becomes MAX_SIZE which is >0 a solution would be //	if(i==0) break; inside for
		Addition::add(as[i], bs[i], tempSum);// add
		result[i+1] = tempSum[0] + 48;// put the last digit in the final result
	}
	Addition::add(as[0], bs[0], tempSum);
	result[1] = tempSum[0] + 48;
	char* r = (char*)result;
	if(tempSum[1] != 1) r++;

	return NaturalNumber(std::string(r));
}

NaturalNumber& Addition::addOne(NaturalNumber& n){
	size_t numberSize = n.digits_.size();
	bool incrementNextDigit = false;
	char* currentDigit;
	size_t index = 0; // adding one to units
	do{
		currentDigit = &(n.digits_[numberSize-index++-1]);// point to the "index" digit from the right
		(*currentDigit)++; // increment the digit
		if(*currentDigit == 58) // 58 = "9"+1 if it's 10 then set it to 0 and incrementNextDigit
		{
			*currentDigit = 48; // set it to "0"
			incrementNextDigit = true;
		}else incrementNextDigit = false;
	}while(incrementNextDigit);
	currentDigit = NULL;
	return n;
}


} /* namespace grade1 */
} /* namespace math */
