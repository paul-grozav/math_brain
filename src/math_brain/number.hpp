#ifndef MATH_BRAIN__NUMBER_HPP
#define MATH_BRAIN__NUMBER_HPP

#include <string> // std::string

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
    std::string _str;

public:
    /**
     * Creates a number instance pointing to no acctual number.
     */
    number();

    /**
     * Creates a number instance using the parameters
     * @param pointer - A pointer to a constant character sequence. This
     * pointer points to the first character of a number.
     */
    number(std::string &str);

    /**
     * @param pointer - A pointer to a constant character sequence. This
     * pointer points to the first character of a number.
     * @param length - The number of characters that define the number.
     */
    void set(std::string &str);

    /**
     * Print number to std::cout.
     */
    void print_to_cout();

    /**
     * @brief operator == Will compare two numbers by comparing their string
     * representation.
     * @param other - The other number that is compared with the current
     * instance
     * @return True if and only if the two numbers are equal.
     */
    bool operator==(const number& other) const;

//    /**
//     * @note not used
//     * @param str - A string reference that contains the number to be parser
//     * @param index - position in given string, where the number starts.
//     * @param number - A number that will be initialized with the characters
//     * starting at the given pointer.
//     * @return Number of digits in the number.
//     */
//    size_t static parse_number(std::string &str, size_t index, number &number);


};

} // namespace math_brain

#endif // MATHBRAIN__NUMBER_HPP
