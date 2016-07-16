#ifndef MATH_BRAIN__PARSER__MATHEMATICAL_EXPRESSION_PARSER_HPP
#define MATH_BRAIN__PARSER__MATHEMATICAL_EXPRESSION_PARSER_HPP
namespace math_brain
{
namespace parser
{
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

void parse_number(const char *&c);

void parse(const char *c);

} // namespace parser
} // namespace math_brain
#endif // MATH_BRAIN__PARSER__MATHEMATICAL_EXPRESSION_PARSER_HPP
