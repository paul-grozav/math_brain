#ifndef MATH_BRAIN_ARITHMETIC_HPP
#define MATH_BRAIN_ARITHMETIC_HPP

#include "number.hpp"

/**
 * math_brain namespace holds all the project logic.
 */
namespace math_brain
{
namespace arithmetic
{

// ========================================================================== //
/**
 * @brief add - Adds two numbers together and forms a new number.
 * @param a - The left hand side number.
 * @param b - The right hand side number.
 * @return A new number instance that will be created as the sum of the given
 * numbers.
 */
number add(const number &a, const number &b);

/**
 * @brief add_digits - Adds two digits and the carry in and then sets the result
 * in the third parameter.
 * @param a - The first digit to be part of the sum, the digit should have a
 * value 48 <= value <= 57. That means that we use values like '1' not 1 or 49
 * not 1.
 * @param b - The first digit to be part of the sum, the digit should have a
 * value 48 <= value <= 57. That means that we use values like '1' not 1 or 49
 * not 1.
 * @param r - an array of two characters, the result of the sum of one digit
 * numbers will always have one or two digits.
 *
 * @note r[0] will be the result of the addition. And r[1] will be the carry in
 * and carry out.
 *
 * @note r[0], the result of the addition will be between [48 and 57], between
 * '0' and '9', not between 0 and 9.
 *
 * @note you can think of r[0] as of a digit, and you can think of r[1] as a
 * flag that's true(1) if the result has a carry out, and it's false(0) if the
 * result does not have a carry out.
 *
 * When the function is called, the result(r[0]) will be set the the sum of the
 * two digits and the carry in(r[1]) then, if the result has more than one digit
 * we'll subtract 10 from the result, and set the carry out to 1, otherwise, if
 * the result does not have more than one digit, we'll set the carry out to 0.
 *
 * For example:
 * char r[2] = {'0',0};
 * add_digits('1', '8', r); // r will become {'9',0} - without carry out
 * add_digits('1', '9', r); // r will become {'0',1} - with carry out 1
 * // or ...
 * r = {'0', 1}; // start with a carry out and use it as carry in
 * add_digits('1', '8', r); // r will become {'0',1} because of 1+8+(1 carry in)
 */
void add_digits(char a, char b, char *r);
// ========================================================================== //

} // namespace arithmetic
} // namespace math_brain

#endif // MATH_BRAIN_ARITHMETIC_HPP
