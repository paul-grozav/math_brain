/*
 * Expression.cpp
 *
 * Created on: Oct 8, 2013
 * Begun by: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include "../NaturalNumber.h" // NaturalNumber
#include <iostream> // std::cout, std::endl
#include <string> // std::string
using namespace std;
#include "Expression.h"

using namespace std;

namespace math {
namespace grade4 {
namespace lexicalAnalysis {

//const NaturalNumber NaturalNumber::ZERO;

Expression::Expression(const std::string& exp) {
	cout << "Expression:\"" << exp << "\"" << endl;
	size_t expSize = exp.size();

	// Search for '(' and matching ')'
	size_t openBracket = expSize;
	size_t bracketsOpened = 0;
	for(size_t i=0; i<exp.size(); i++){
		if(exp[i] == '('){
			if(openBracket == expSize) openBracket = i;
			bracketsOpened++;
		}
		if(exp[i] == ')'){
			bracketsOpened--;
			if(bracketsOpened == 0){
				tokens_.push_back(Expression(exp.substr(openBracket+1, i-openBracket-1)));
				openBracket = expSize;
			}
		}
	}

}

Expression::~Expression() {
}

} /* namespace lexicalAnalysis */
} /* namespace grade1 */
} /* namespace math */
