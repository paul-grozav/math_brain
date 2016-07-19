#ifndef MATH_BRAIN__MATHEMATICAL_OBJECT_HPP
#define MATH_BRAIN__MATHEMATICAL_OBJECT_HPP

namespace math_brain
{

// ========================================================================== //
/**
 * A Number (instance) only exists as long as the expression exists. While
 * expression "22+112" exists, THAT number "22" exists. When the expression
 * does not exist anymore, THAT number "22" does not exist anymore. It's like
 * "What number? I don't see it, where is it?"
 * A certain number is a pointer to a sequence of characters in an expression.
 * When that expression is gone, that certain number (instance) is gone.
 * The notion of "A number" still exists, just as the class exists after the
 * instance is gone.
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class mathematical_object
{
public:
    /**
     * Types of mathematical_object.
     */
    enum type
    {
          TYPE_UNDEFINED
        , TYPE_NUMBER
        , TYPE_BASIC_ARITHMETIC_OPERATION
    };

private:
    /**
     * @brief void pointer to a mathematical object. like a number or a
     * arithmetic operation.
     */
    void *_pointer;
    /**
     * @brief Type of object the pointer points to.
     */
    type _object_type;

public:
    /**
     * Creates a mathematical_object instance with undefined type and null
     * pointer.
     */
    mathematical_object();

    /**
     * Creates a mathematical_object instance using the given parameters.
     * @param pointer - A pointer to a mathematical object of a type defined
     * above
     * @param object_type - The type of object. Must be one of the types
     * enumerated above.
     */
    mathematical_object(void *pointer, type object_type);

    /**
     * @brief set Sets the pointer and object type of this instance.
     * @param pointer - A pointer to a mathematical object of a type defined
     * above
     * @param object_type - The type of object. Must be one of the types
     */
    void set(void *pointer, type object_type);

    /**
     * @brief get_object Get object void pointer.
     * @return The pointer to the object.
     */
    void *get_object();

    /**
     * @brief get_object_type Return the object type.
     * @return The object type
     */
    type get_object_type();

};

} // namespace math_brain

#endif // MATHBRAIN__MATHEMATICAL_OBJECT_HPP
