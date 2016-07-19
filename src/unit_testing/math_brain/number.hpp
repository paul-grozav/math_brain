#ifndef UNIT_TESTING__MATH_BRAIN__NUMBER_HPP
#define UNIT_TESTING__MATH_BRAIN__NUMBER_HPP

#include <cstddef> // size_t

namespace unit_testing
{
namespace math_brain
{

// ========================================================================== //
/**
 * Unit testing a number
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
     * Creates a number instance using the parameters
     * @param pointer - A pointer to a constant character sequence. This
     * pointer points to the first character of a number.
     * @param length - The number of characters that define the number.
     */
    number(const char *pointer, size_t length);

    /**
     * Print number to std::cout.
     */
    void print_to_cout();
};

} // namespace math_brain
} // namespace unit_testing

#endif // UNIT_TESTING__MATHBRAIN__NUMBER_HPP
