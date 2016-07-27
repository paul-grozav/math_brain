#ifndef MATH_BRAIN_BINARY_OPERATOR_HPP
#define MATH_BRAIN_BINARY_OPERATOR_HPP

#include "mathematical_object.hpp"

#include <string> // std::string
#include <ostream> // std::ostream

/**
 * math_brain namespace holds all the project logic.
 */
namespace math_brain
{

// ========================================================================== //
/**
 * A binary operator is defined by it's string representation.
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class binary_operator : public mathematical_object
{
public:

    /**
     * Creates a binary operator instance using the given string representation.
     * @param str - A binary operator represented as a string. This value will
     * be copied into this binary operator instance.
     */
    binary_operator(std::string &str);

    /**
     * Creates a binary operator instance using the given string representation.
     * @param c_str - A binary operator represented as constant char array.
     * A new string will be created from this char[] and it will be assigned to
     * this instance.
     */
    binary_operator(const char c_str[]);

    /**
     * Creates a binary operator instance using the given character
     * representation.
     * @param c - A binary operator represented as a char.
     * A new string will be created from this char and it will be assigned to
     * this instance.
     */
    binary_operator(const char c);

    /**
     * @brief Will compare two binary operators by comparing their string
     * representation.
     * @param other - The other binary operator that is compared with the
     * current instance.
     * @return True if and only if the two binary operators are equal.
     */
    bool equals(const binary_operator& other) const;

    /**
     * @brief operator == Will compare two binary operators by comparing their
     * string representation.
     * @see equals().
     * @param other - The other binary operator that is compared with the
     * current instance.
     * @return True if and only if the two binary operators are equal.
     */
    bool operator==(const binary_operator& other) const;

};

} // namespace math_brain

#endif // MATH_BRAIN_BINARY_OPERATOR_HPP
