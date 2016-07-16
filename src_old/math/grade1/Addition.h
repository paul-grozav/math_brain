/*
 * Addition.h
 *
 * Created on: 2013-09-20
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#ifndef _MATH_GRADE1_ADDITION_H_
#define _MATH_GRADE1_ADDITION_H_

#include "NaturalNumber.h" // NaturalNumber
#include <string> // std::string

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
	 */
	static NaturalNumber add(const NaturalNumber& a, const NaturalNumber& b);

	/**
	 * Adds one to the given number and returns it back. Increments it, successor function
	 * @param n The NaturalNumber to be incremented
	 * @return The NaturalNumber incremented
	 */
	static NaturalNumber& addOne(NaturalNumber& n);
protected:
	/**
	 * Addition of digits. Adds a with b and uses r[1] as the carryIn and then sets r[0] as the result and r[1] as the carryOut
	 * @param a First digit
	 * @param b Second digit
	 * @param r a 2 char array with r[0] being 1 if b was subtracted from 10+a and 0 if b was subtracted from a. r[1] is the result of the subtraction
	 */
	static void add(char a, char b, char* r);

};

} /* namespace grade1 */
} /* namespace math */
#endif /* _MATH_GRADE1_ADDITION_H_ */
