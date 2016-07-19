#include "parser.hpp"
#include "../../../math_brain/parser/parser.hpp"

#include <iostream>

using namespace math_brain::parser;

namespace unit_testing
{
namespace math_brain
{
namespace parser
{

bool testing__is_digit()
{
    for (char i=-128; i<=127; i++)
    {
        if ( !( // not valid case
            // two following valid cases
            // i is in digit interval and is_digit is true
            (47 < i && i < 58 && is_digit(i) == true) ||
            // OR i is outside the digit interval and is_digit is false
            ((i <= 47 || 58 <= i) && is_digit(i) == false)
        ) )
        {
            std::cerr << "testing__is_digit(): i=" << static_cast<int>(i)
                << " fails." << std::endl;
            if(!(47 < i && i < 58 && is_digit(i) == true))
            {
                std::cout << "C1" << std::endl;
            }
            return false; // not ok ... should not reach this point
        }
        if(i==127) // exit condition because when i=127 and i++ i becomes -128
        {
            break;
        }
    }
    return true;
}

bool testing__is_valid_sign()
{
    for (char i=-128; i<=127; i++)
    {
        if ( !( // not valid case
            // two following valid cases
            // i is 43 ('+') or 45 ('-') and is_valid_sign(i) == true
            ((i == 43 || i == 45) && is_valid_sign(i) == true) ||
            // OR i is not 43 and not 45 and is_valid_sign  == false
            (i != 43 && i != 45 && is_valid_sign(i) == false)
        ) )
        {
            std::cerr << "testing__is_digit(): i=" << static_cast<int>(i)
                << " fails." << std::endl;
            if(!(47 < i && i < 58 && is_digit(i) == true))
            {
                std::cout << "C1" << std::endl;
            }
            return false; // not ok ... should not reach this point
        }
        if(i==127) // exit condition because when i=127 and i++ i becomes -128
        {
            break;
        }
    }
    return true;
}

bool testing__()
{
    return
           testing__is_digit()
        && testing__is_valid_sign()
    ;
}

} // namespace parser
} // namespace math_brain
} // namespace unit_testing
