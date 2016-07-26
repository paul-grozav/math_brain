#ifndef MATH_BRAIN_MATHEMATICAL_OBJECT_HPP
#define MATH_BRAIN_MATHEMATICAL_OBJECT_HPP

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

private:
    /**
     * @brief void pointer to a mathematical object like a number or an
     * arithmetic operation.
     */
    void *_pointer;
    /**
     * @brief Type of object the pointer points to.
     */
    object_type _object_type;

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
     * @param type - The type of object. Must be one of the types
     * enumerated above.
     */
    mathematical_object(void *pointer, object_type type);

    /**
     * @brief set Sets the pointer and object type of this instance.
     * @param pointer - A pointer to a mathematical object of a type defined
     * above
     * @param type - The type of object. Must be one of the types
     */
    void set(void *pointer, object_type type);

    /**
     * @brief get_object Get object void pointer.
     * @return The pointer to the object.
     */
    void *get_object();

    /**
     * @brief get_object_type Return the object type.
     * @return The object type
     */
    object_type get_object_type();

};

} // namespace math_brain

#endif // MATH_BRAIN_MATHEMATICAL_OBJECT_HPP
