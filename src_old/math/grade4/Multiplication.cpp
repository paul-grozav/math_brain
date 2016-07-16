/*
 * Multiplication.cpp
 *
 * Created on: Oct 11, 2013
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include "Multiplication.h"
#include "NaturalNumber.h" // NaturalNumber

namespace math {
namespace grade4 {

void Multiplication::multiply(char a, char b, char* r) {
	*r = (a-48)*(b-48) + (*r > 9 ? *r/10 : 0); // if there is a carry in then add the carry in(*r/10) to the result
}

/*
// The exact way a kid does it
NaturalNumber Multiplication::multiply(const NaturalNumber& a, const NaturalNumber& b) {
	// Convert to string
	std::string as = a.digits_;
	std::string bs = b.digits_;
	// Get size
	size_t asSize = as.size();
	size_t bsSize = bs.size();

	// Create tempResults
//	cout << as << endl << bs << endl << "---------" << endl;
	char* tempResult = new char();// reserve 1 byte for the computation
	char bsi, asj;
	std::string tempResults[bsSize];
	for(size_t i=0; i<bsSize; i++){
		for(size_t j=0; j<asSize; j++){
			bsi = bs[bsSize-1-i];
			asj = as[asSize-1-j];
			Multiplication::multiply(bsi, asj, tempResult);
			if(*tempResult > 9){
				tempResults[i] = (char)(*tempResult%10+48) + tempResults[i];// -(*tempResult/10) to remove the carryOut and +48 to make it a valid ASCII digit
			}else{
				tempResults[i] = (char)(*tempResult+48) + tempResults[i];// +48 to make it a valid ASCII digit
			}
		}
		if(*tempResult/10 > 0) tempResults[i] = (char)(*tempResult/10+48) + tempResults[i]; // add the last carryOut if there is one
		*tempMultiply = 0;// reset the carryOut
//		cout << tempResults[i] << endl;
	}

	// Sum temp results
	NaturalNumber r;
	for(size_t i=0; i<bsSize; i++){
		tempResults[i].insert(tempResults[i].size(), i, '0');// add i 0's to the end of the number to move it i posisitions to the left
		r = r + NaturalNumber(tempResults[i]);
	}
//	cout << "---------" << endl << r.digits_ << endl;

	return r;
}
*/

NaturalNumber Multiplication::multiply(const NaturalNumber& a, const NaturalNumber& b) {
	// Convert to string
	std::string as = a.digits_;
	std::string bs = b.digits_;

	// Fast computing exceptions
	if(as == "0" || bs == "0") return NaturalNumber("0");
	if(as == "1") return NaturalNumber(bs);
	if(bs == "1") return NaturalNumber(as);
	// END Fast computing exception

	// Get size
	size_t asSize = as.size();
	size_t bsSize = bs.size();

	// Create tempResults
//	cout << as << endl << bs << endl << "---------" << endl;
	char* tempMultiply = new char();// reserve 1 byte for the computation
	std::string tempResult;
	NaturalNumber result;
	for(size_t i=0; i<bsSize; i++){
		for(size_t j=0; j<asSize; j++){
			Multiplication::multiply(bs[bsSize-1-i], as[asSize-1-j], tempMultiply);
			if(*tempMultiply > 9){
				tempResult = (char)(*tempMultiply%10+48) + tempResult;// -(*tempResult/10) to remove the carryOut and +48 to make it a valid ASCII digit
			}else{
				tempResult = (char)(*tempMultiply+48) + tempResult;// +48 to make it a valid ASCII digit
			}
		}
		if(*tempMultiply/10 > 0) tempResult = (char)(*tempMultiply/10+48) + tempResult; // add the last carryOut if there is one
		*tempMultiply = 0;// reset the carryOut
		tempResult.insert(tempResult.size(), i, '0');// add i zeros to the end
		result = result + NaturalNumber(tempResult);
//		cout << tempResult << endl;
		tempResult = "";// reset tempResult
	}

//	cout << "---------" << endl << result.digits_ << endl;

	return result;
}

} /* namespace grade1 */
} /* namespace math */
