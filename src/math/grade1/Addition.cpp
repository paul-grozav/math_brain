/*
 * Addition.cpp
 *
 * Created on: 2013-09-20
 * Begun by: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include "Addition.h"
#include "NaturalNumber.h" // NaturalNumber
#include <iostream> // cout, endl
#include <string> // std::string
#include <sstream> // std::stringstream

using namespace std;

namespace math {
namespace grade1 {

void Addition::add(char a, char b, std::string& r) {
	std::stringstream ss;
	ss << ((r.size() > 1) ? (a + b + 1 - 2 * 48) : (a + b - 2 * 48));
	r = ss.str();
/*// OLD way, based on char[]
	if(r[1] == 0){
		if (a + b - 2 * 48 > 9) { // 48 is '0' in ASCII. We subtract it twice, once for a and once for b
			r[0] = a + b - 2 * 48;
			r[1] = 1;
		} else {
			r[0] = a + b - 2 * 48;
			r[1] = 0;
		}
	}else{
		if (a + b + 1 - 2 * 48 > 9) { // 48 is '0' in ASCII. We subtract it twice, once for a and once for b
			r[0] = a + b + 1 - 2 * 48 - 10;
			r[1] = 1;
		} else {
			r[0] = a + b + 1 - 2 * 48;
			r[1] = 0;
		}
	}
*/
}

NaturalNumber Addition::add(const NaturalNumber& a, const NaturalNumber& b) {
	// Convert to string
	std::string as = a.toString();
	std::string bs = b.toString();
	// Get size
	size_t asSize = as.size();
	size_t bsSize = bs.size();

//	cout << as << " + " << bs << endl;

	// Make them have same size by adding trailing zeroes
	if(asSize > bsSize){
		bs.insert(0, asSize-bsSize, '0');
		bsSize = bs.size();
	}else if(bsSize > asSize){
		as.insert(0, bsSize-asSize, '0');
		asSize = as.size();
	}

//	cout << as << " + " << bs << endl;

	std::string tempSum, finalSum;
	for(size_t i=asSize; i>0; i--){// go from right to left, from the last character to the first one, from N-1 to 0
		add(as.at(i-1), bs.at(i-1), tempSum);
		finalSum = *(tempSum.rbegin()) + finalSum;
//		cout << as.at(i-1) << " + " << bs.at(i-1) << " = " << *(tempSum.rbegin()) << endl;
	}
	if(tempSum.size() > 1)
		finalSum = "1" + finalSum;
/*// OLD WAY, char[] based
	char tempSum[2] = {0, 0};
	char result[strlen(at)+2];//one digit greater than the largest number, we'll remove that digit if needed + 1 digit for '\0'
	for(int i=0; i<5; i++) result[i] = 49;
	result[strlen(at)+1] = 0;
	for(size_t i = strlen(at)-1; i>0; i--){//when i=0 "i--" gets executed and i becomes MAX_SIZE which is >0 a solution would be //	if(i==0) break; inside for
//		for(int j=0; j<5; j++) cout << "result[" << j << "]=" << (int)result[j] << endl;
		Addition::add(at[i], bt[i], tempSum);// add
		result[i+1] = tempSum[0] + 48;// put the last digit in the final result
//		cout <<  at[i] << " + " << bt[i] << " = " << result[i+1] << " r=" << tempSum[1] << endl;
	}
	Addition::add(at[0], bt[0], tempSum);
	result[1] = tempSum[0] + 48;
//	cout <<  at[0] << " + " << bt[0] << " = " << result[1] << " r=" << tempSum[1] << endl;
//	for(int i=0; i<5; i++) cout << "result[" << i << "]=" << (int)result[i] << endl;
	char* r = (char*)result;
	if(tempSum[1] != 1) r++;
	cout << "|" << r << "|" << endl;
*/
	return NaturalNumber(finalSum);
}

} /* namespace grade1 */
} /* namespace math */
