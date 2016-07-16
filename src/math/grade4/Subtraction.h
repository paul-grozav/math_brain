/*
 * Subtraction.h
 *
 * Created on: Oct 10, 2013
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_

#include "NaturalNumber.h" // NaturalNumber

namespace math {
namespace grade4 {

/**
 * Subtraction operation starts by knowing how to subtract NaturalNumbers
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class Subtraction {
public:

	/**
	 * Subtraction of natural numbers. The kid says : "Give me two numbers and I'll subtract the second one from the first one"
	 * @param a The first NaturalNumber
	 * @param b The second NaturalNumber that is subtracted from the first one
	 * @return The new NaturalNumber obtained by subtracting the second natural number form the first one
	 */
	static NaturalNumber subtract(const NaturalNumber& a, const NaturalNumber& b);

	/**
	 * Subtracts one from the given number and returns it back. Decrements it
	 * @param n The NaturalNumber to be decremented
	 * @return The NaturalNumber decremented
	 */
	static NaturalNumber& subtractOne(NaturalNumber& n);

protected:
	/**
	 * Subtraction of digits.
	 * In other words it sets the r[1] equal to the result and r[0] is the borrowFlag
	 * @param a First digit
	 * @param b Second digit
	 * @param r pointer to a char array having 2 bytes one for the result digit and one for the borrowFlag
	 */
	static void subtract(char a, char b, char* r);

};

} /* namespace grade1 */
} /* namespace math */
#endif /* SUBTRACTION_H_ */
