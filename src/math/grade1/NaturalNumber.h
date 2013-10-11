/*
 * NaturalNumber.h
 *
 * Created on: 2013-09-20
 * Author: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#ifndef _MATH_GRADE1_NATURALNUMBER_H_
#define _MATH_GRADE1_NATURALNUMBER_H_

#include <string> // std::string

namespace math {
namespace grade1 {

/**
 * This class describes a Natural Number as a kid should see it in the first grade
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class NaturalNumber {
public:
	/**
	 * Creates a Natural Number starting from the image, the digits, the characters. This method removes trailing zeroes.
	 * @param number (default:"0") The sequence of characters that help the kid to create the number in his head
	 */
	NaturalNumber(std::string number = "0");
	/**
	 * Forget the number and it's image
	 */
	virtual ~NaturalNumber();

	/**
	 * Adding this number with another one
	 * @param anotherNumber the other number that this is added to
	 */
	NaturalNumber operator +(const NaturalNumber& anotherNumber);

	/**
	 * Subtracting an another number from this one
	 * @param anotherNumber the number to subtract from this one
	 */
	NaturalNumber operator -(const NaturalNumber& anotherNumber);

	/**
	 * Postfix operator ( x++ ). Adds one to this number.
	 * @param n ?
	 */
	NaturalNumber& operator ++(int n);

	/**
	 * Compares this number with another one and returns true if the numbers are equal and false otherwise.
	 * @param otherNumber the other number that is compared with this one
	 * @return true if and only if the digits_ are equal and false otherwise
	 */
	bool operator ==(const NaturalNumber& otherNumber)const;

	/**
	 * Compares this number with another one and returns true if the numbers are different and false otherwise.
	 * @param otherNumber the other number that is compared with this one
	 * @return true if and only if the digits_ are different and false otherwise
	 */
	bool operator !=(const NaturalNumber& otherNumber)const;


	/**
	 * Prefix operator ( ++x ). Adds one to this number.
	 * @param n the number to increment
	 */
//	NaturalNumber& operator ++();

	/**
	 * Gets the digit of tens, hundreds, ...
	 * @param powerOfTen Place of the digit. 0 for units, 1 for tens, 2 for hundreds ... 10^powerOfTens
	 */
	char* getTens(NaturalNumber powerOfTen = NaturalNumber("1"));

	/**
	 * Checks if a given std::string is a valid NaturalNumber. Has all digits between "0" and "9"
	 * @param ref Reference to a std::string.
	 * @return true if and only if all the caracters are digits 0 to 9 and false otherwise
	 */
	static bool isValid(const std::string& ref);

	/**
	 * Represent the number using a text
	 * @return The text representing the number
	 */
	const std::string& toString();

	/**
	 * Represent the number as a size_t. I hope size_t can hold laaarge numbers ... :)
	 * @return The size_t value representing the number
	 */
//	size_t toSizeT() const;

	/**
	 * The image of the number, the sequence of characters that are the representation of this number. The number was constructed starting from this digits.
	 * I am making this image public because other agents, functions might want to "change" the number like increment it. That would be done by changing the image of that number, instead of returning a new number
	 */
	std::string digits_;
};

} /* namespace grade1 */
} /* namespace math */
#endif /* _MATH_GRADE1_NATURALNUMBER_H_ */
