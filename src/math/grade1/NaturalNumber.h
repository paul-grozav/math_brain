/*
 * NaturalNumber.h
 *
 * Created on: 2013-09-20
 * Begun by: Tancredi-Paul Grozav <paul@grozav.info>
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
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	NaturalNumber(std::string number = "0");
	/**
	 * Forget the number and it's image
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	virtual ~NaturalNumber();

	/**
	 * Adding this number with another one
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	NaturalNumber operator +(const NaturalNumber& anotherNumber);

	/**
	 * Represent the number using a text
	 * @return The text representing the number
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	std::string toString() const;

	/**
	 * Checks if a given std::string is a valid NaturalNumber
	 * @return true if and only if all the caracters are digits 0 to 9 and false otherwise
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	static bool isValid(const std::string& ref);
protected:
	/**
	 * The image of the number, the sequence of characters that are the representation of this number. The number was constructed starting from this digits
	 */
	std::string digits_;
};

} /* namespace grade1 */
} /* namespace math */
#endif /* _MATH_GRADE1_NATURALNUMBER_H_ */
