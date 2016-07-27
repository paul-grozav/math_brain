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
     * @brief Will compare two numbers by comparing their string representation.
     * @param other - The other number that is compared with the current
     * instance.
     * @return True if and only if the two numbers are equal.
     */
    bool equals(const number& other) const;

    /**
     * @brief operator == Will compare two numbers by comparing their string
     * representation.
     * @see equals().
     * @param other - The other number that is compared with the current
     * instance.
     * @return True if and only if the two numbers are equal.
     */
    bool operator==(const number& other) const;

};

} // namespace math_brain

#endif // MATH_BRAIN_NUMBER_HPP
