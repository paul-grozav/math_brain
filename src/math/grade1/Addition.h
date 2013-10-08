/*
 * Addition.h
 *
 * Created on: 2013-09-20
 * Begun by: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#ifndef _MATH_GRADE1_ADDITION_H_
#define _MATH_GRADE1_ADDITION_H_

#include "NaturalNumber.h" // NaturalNumber

namespace math {
namespace grade1 {

/**
 * Addition operation starts by knowing how to add NaturalNumbers
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class Addition {
public:
	/**
	 * Addition of natural numbers. The kid says : "Give me two numbers and I'll add them for you"
	 * @param a The first NaturalNumber
	 * @param b The second NaturalNumber
	 * @return The new NaturalNumber obtained by adding those two numbers
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	static NaturalNumber add(const NaturalNumber& a, const NaturalNumber& b);
protected:
	/**
	 * Addition of digits. Adds a with b and uses r[1] as the carryIn and then sets r[0] as the result and r[1] as the carryOut
	 * In other words it sets the string reference as the result converted to std::string (always between 0=0+0 and 18=9+9)
	 * @param a First digit
	 * @param b Second digit
	 * @param r reference to a std::string having 2 bytes one for the result digit and one for the carry
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	static void add(char a, char b, std::string& r);
};

} /* namespace grade1 */
} /* namespace math */
#endif /* _MATH_GRADE1_ADDITION_H_ */
