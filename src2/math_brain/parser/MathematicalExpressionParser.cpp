#include "MathematicalExpressionParser.hpp"

#include <iostream>
#include <cstring> // strlen
#include <string>

namespace math_brain
{
namespace parser
{

bool is_digit(const char c)
{
    return
           c == '0'
        || c == '1'
        || c == '2'
        || c == '3'
        || c == '4'
        || c == '5'
        || c == '6'
        || c == '7'
        || c == '8'
        || c == '9'
    ;
}

bool is_valid_sign(const char c)
{
    return
           c == '+'
        || c == '-'
    ;
}

void parse_number(const char *&c)
{
    char *number = new char[strlen(c)];
    size_t i = 0;
    number[i++] = *c++;
    while(is_digit(*c))
    {
        number[i++] = *c++;
    }
    number[i] = '\0'; // end of C-style string

    std::cout << "got number=\"" << number << "\"" << std::endl;
    delete number;
}

void parse(const char *c)
{
    while( *c != '\0' )
    {
        if( is_digit(*c) )
        {
            parse_number(c);
        }
        else if ( is_valid_sign(*c) )
        {
            std::cout << "Got valid sign:'" << *c << "'" << std::endl;
            c++;
        }
        else
        {
            std::cout << "Ignoring invalid sign:'" << *c << "'" << std::endl;
            c++; // ignore character and go to next one
        }
    }
}

} // namespace parser
} // namespace math_brain
