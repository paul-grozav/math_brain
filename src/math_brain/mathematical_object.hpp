// ========================================================================== //
// Author: Tancredi-Paul Grozav <paul@grozav.info>
// ========================================================================== //
#ifndef MATH_BRAIN__MATHEMATICAL_OBJECT_HPP
#define MATH_BRAIN__MATHEMATICAL_OBJECT_HPP

#include <string> // std::string
#include <ostream> // std::ostream
// ========================================================================== //
namespace math_brain
{
// ========================================================================== //
/**
 * A mathematical object is an instance of a number or an arithmetic operation,
 * etc. Expressions are made of mathematical objects.
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class mathematical_object
{
protected:
  /**
   * The string representation of the mathematical object.
   */
  ::std::string _str;

public:
  /**
   * Types of mathematical_object.
   */
  enum object_type
  {
      TYPE_UNDEFINED
    , TYPE_NUMBER
    , TYPE_BASIC_ARITHMETIC_OPERATION
  };

protected:
  /**
   * @brief Type of object the pointer points to.
   */
  object_type _object_type;

public:

  /**
   * Creates a mathematical object instance using the given parameters.
   * @param str - The string representation of the mathematical object.
   * @param type - The type of object. Must be one of the types enumerated
   * above.
   */
  mathematical_object(::std::string &str, object_type type);

  /**
   * Creates a mathematical object instance using the given string
   * representation.
   * @param c_str - A mathematical object represented as constant char array.
   * A new string will be created from this char[] and it will be assigned to
   * this instance.
   * @param type - The type of object. Must be one of the types enumerated
   * above.
   */
  mathematical_object(const char c_str[], object_type type);

  /**
   * @brief get_object_type Return the object type.
   * @return The object type
   */
  object_type get_object_type();

  /**
   * @return A copy of the string representation of this object.
   */
  ::std::string get_string_representation() const;

  /**
   * @brief Will compare two mathematical objects by comparing their string
   * representation and their type.
   * @param other - The other mathematical object that is compared with the
   * current instance.
   * @return True if and only if the two mathematical objects are equal.
   */
  bool equals(const mathematical_object& other) const;

  /**
   * @brief operator == Will compare two mathematical objects by comparing
   * their string representation.
   * @see equals().
   * @param other - The other mathematical object that is compared with the
   * current instance.
   * @return True if and only if the two mathematical objects are equal.
   */
  bool operator==(const mathematical_object& other) const;

  /**
   * @brief operator != will return the oposite value of ==
   * @see equals().
   * @param other - The other mathematical object that is compared with the
   * current instance.
   * @return True if and only if the two mathematical objects are NOT equal.
   */
  bool operator!=(const mathematical_object& other) const;
};
/**
 * Makes the object printable to an output stream.
 * @param os - The output stream where the object should be printed.
 * @param o - The object that should be printed to that stream.
 * @return The output stream where we wrote the object.
 */
::std::ostream& operator<<(::std::ostream &os, const mathematical_object &o);
} // namespace math_brain
#endif // MATH_BRAIN__MATHEMATICAL_OBJECT_HPP
// ========================================================================== //
