#ifndef MATH_BRAIN_MATHEMATICAL_OBJECT_HPP
#define MATH_BRAIN_MATHEMATICAL_OBJECT_HPP

#include <string> // std::string
#include <ostream> // std::ostream

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
    std::string _str;

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
     * @param type - The type of object. Must be one of the types
     * enumerated above.
     */
    mathematical_object(std::string &str, object_type type);

    /**
     * Creates a mathematical object instance using the given string
     * representation.
     * @param c_str - A mathematical object represented as constant char array.
     * A new string will be created from this char[] and it will be assigned to
     * this instance.
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
    std::string get_string_representation() const;

    /**
     * Print the object to the given output stream.
     * @param output_stream - The output stream where the object should be
     * printed.
     */
    void print_to_stream(std::ostream& output_stream);

};

} // namespace math_brain

#endif // MATH_BRAIN_MATHEMATICAL_OBJECT_HPP
