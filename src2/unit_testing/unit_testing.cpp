#include "parser/MathematicalExpressionParser.hpp"

namespace unit_testing
{

bool testing__()
{
    return
           parser::testing__is_digit()
        && parser::testing__is_valid_sign()
    ;
}

} // namespace unit_testing
