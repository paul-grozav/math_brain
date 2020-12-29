// ========================================================================== //
// Author: Tancredi-Paul Grozav <paul@grozav.info>
// ========================================================================== //
#ifndef MATH_BRAIN__BINARY_OPERATOR_HPP
#define MATH_BRAIN__BINARY_OPERATOR_HPP

#include <string> // std::string
#include <ostream> // std::ostream

#include "math_brain/mathematical_object.hpp"

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
/**
 * Makes the binary_operator printable to an output stream.
 * @param os - The output stream where the binary_operator should be printed.
 * @param bo - The binary_operator that should be printed to that stream.
 * @return The output stream where we wrote the object.
 */
::std::ostream& operator<<(::std::ostream &os, const binary_operator &bo);
} // namespace math_brain
#endif // MATH_BRAIN__BINARY_OPERATOR_HPP
// ========================================================================== //
