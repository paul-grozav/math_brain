#ifndef MATH_BRAIN__PARSER__MATHEMATICAL_EXPRESSION_PARSER_HPP
#define MATH_BRAIN__PARSER__MATHEMATICAL_EXPRESSION_PARSER_HPP

#include "../number.hpp"
#include "../mathematical_object.hpp"

#include <vector> // std:vector

namespace math_brain
{
namespace parser
{

class expression
{
private:
    std::vector<mathematical_object> _objects;

public:
    /**
     * Create a new expression object from a C string.
     * @param c - A pointer to a C style string that contains the expression
     * that should be parsed as an expression object.
     */
    static void parse(const char *c, expression *expression);

    expression();

    /**
     * This method will delete every pointer to every object in the _objects
     * list.
     */
    ~expression();

    /**
     * Print objects in expression.
     */
    void print_objects();
};

/**
 * @brief is_digit will return true if and only if the given character is a
 * digit in the following set {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
 * @param c - will check if this character is a digit
 * @return Returns true if and only if the given character is a digit
 */
bool is_digit(const char c);

/**
 * @brief is_valid_sign Checks if the given characted is one of the valid
 * operation signs.
 * @param c - The character to check if it's a valid sign
 * @return True if and only if the given character is a valid operation sign
 */
bool is_valid_sign(const char c);

/**
 * @param string - A pointer to a C string. This pointer must point to the first
 * digit of a number
 * @param number - A number that will be initialized with the characters
 * starting at the given pointer.
 */
void parse_number(const char *&string, number &number);

} // namespace parser
} // namespace math_brain
#endif // MATH_BRAIN__PARSER__MATHEMATICAL_EXPRESSION_PARSER_HPP
