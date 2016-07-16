/*
 * Multiplication.h
 *
 * Created on: Oct 11, 2013
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

#include "NaturalNumber.h" // NaturalNumber

namespace math {
namespace grade4 {

/**
 * Multiplication operation starts by knowing how to multiply NaturalNumbers
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class Multiplication {
public:
	/**
	 * Multiplication of natural numbers. The kid says : "Give me two numbers and I'll multiply them for you"
	 * @param a The first NaturalNumber
	 * @param b The second NaturalNumber
	 * @return The new NaturalNumber obtained by multiplying those two numbers
	 */
	static NaturalNumber multiply(const NaturalNumber& a, const NaturalNumber& b);

protected:
	/**
	 * Multiplication of digits. Multiplying two digits always results in one number with maximum two digits those two digits will be stored in a char*
	 * @param a First digit
	 * @param b Second digit
	 * @param r a char pointer. The value it points to will be changed by this function when setting the result
	 */
	static void multiply(char a, char b, char* r);
};

} /* namespace grade1 */
} /* namespace math */
#endif /* MULTIPLICATION_H_ */
