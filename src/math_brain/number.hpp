#ifndef MATH_BRAIN_NUMBER_HPP
#define MATH_BRAIN_NUMBER_HPP

#include "mathematical_object.hpp"

/**
 * math_brain namespace holds all the project logic.
 */
namespace math_brain
{

// ========================================================================== //
/**
 * A number is defined by it's string representation.
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class number : public mathematical_object
{
public:

    /**
     * Creates a number instance using the given string representation.
     * @param str - A number represented as a string. This value will be copied
     * into this number instance.
     */
    number(std::string &str);

    /**
     * Creates a number instance using the given string representation.
     * @param c_str - A number represented as constant char array. A new string
     * will be created from this char[] and it will be assigned to this
     * instance.
     */
    number(const char c_str[]);

    /**
     * Checks if the current instance(number) is less than another(given)
     * number. To determine this it compares the strings, digit by digit.
     * @param n - The other number that will be compared with this instance.
     * @return True if and only if the current instance is strictly smaller than
     * the other given instance.
     */
    bool less_than(const number &n) const;

    /**
     * @brief operator > Will check if the current number is less than another
     * one given.
     * @see less_than(const number &n).
     * @param other - The other number that is compared with the current
     * instance.
     * @return True if and only if the current number is strictly smaller than
     * the other one.
     */
    bool operator<(const number& other) const;

    /**
     * Checks if the current instance(number) is greater than another(given)
     * number. To determine this it compares the strings, digit by digit.
     * @param n - The other number that will be compared with this instance.
     * @return True if and only if the current instance is strictly greater than
     * the other given instance.
     */
    bool greater_than(const number &n) const;

    /**
     * @brief operator > Will check if the current number is greater than
     * another one given.
     * @see greater_than(const number &n).
     * @param other - The other number that is compared with the current
     * instance.
     * @return True if and only if the current number is strictly greater than
     * the other one.
     */
    bool operator>(const number& other) const;

};
/**
 * Makes the number printable to an output stream.
 * @param os - The output stream where the number should be printed.
 * @param n - The number that should be printed to that stream.
 * @return The output stream where we wrote the object.
 */
::std::ostream& operator<<(::std::ostream &os, const number &n);

} // namespace math_brain

#endif // MATH_BRAIN_NUMBER_HPP
