#ifndef MATH_BRAIN__NUMBER_HPP
#define MATH_BRAIN__NUMBER_HPP

#include <cstddef> // size_t

/**
 * math_brain namespace holds all the project logic.
 */
namespace math_brain
{

// ========================================================================== //
/**
 * A number (instance) only exists as long as the expression exists. While
 * expression "22+112" exists, THAT number "22" exists. When the expression
 * does not exist anymore, THAT number "22" does not exist anymore. It's like
 * "What number? I don't see it, where is it?"
 * A certain number is a pointer to a sequence of characters in an expression.
 * When that expression is gone, that certain number (instance) is gone.
 * The notion of "A number" still exists, just as the class exists after the
 * instance is gone.
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class number
{
private:
    /**
     * A pointer to the first character of a number.
     * if this pointer is NULL then this number is not set(initialized).
     */
    const char *_pointer;
    /**
     * The number of characters that define the number.
     * If this value is 0 then the number must not be set(initialized) and
     * the _pointer should be NULL.
     */
    size_t _length;

public:
    /**
     * Creates a number instance pointing to no acctual number.
     */
    number();

    /**
     * Creates a number instance using the parameters
     * @param pointer - A pointer to a constant character sequence. This
     * pointer points to the first character of a number.
     * @param length - The number of characters that define the number.
     */
    number(const char *pointer, size_t length);

    /**
     * @param pointer - A pointer to a constant character sequence. This
     * pointer points to the first character of a number.
     * @param length - The number of characters that define the number.
     */
    void set(const char *pointer, size_t length);

    /**
     * Print number to std::cout.
     */
    void print_to_cout();

    /**
     * @param string - A pointer to a C string. This pointer must point to the first
     * digit of a number
     * @param number - A number that will be initialized with the characters
     * starting at the given pointer.
     */
    void static parse_number(const char *&string, number &number);

};

} // namespace math_brain

#endif // MATHBRAIN__NUMBER_HPP
