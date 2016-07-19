#include "parser/mathematical_expression_parser.hpp"

namespace unit_testing
{
namespace math_brain
{

bool testing__()
{
    return
           parser::testing__is_digit()
        && parser::testing__is_valid_sign()
    ;
}

} // namespace math_brain
} // namespace unit_testing
