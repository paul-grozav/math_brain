#include "mathematical_expression_parser.hpp"
#include "../number.hpp"

#include <iostream>
#include <cstring> // strlen
//#include <vector>

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

number parse_number(const char *&c)
{
    const char *number_pointer = c;
    size_t number_length = 0;
    do
    {
        number_length++;
        c++;
    }
    while(is_digit(*c));
    return number(number_pointer, number_length);
}

void parse(const char *c)
{
    while( *c != '\0' )
    {
        if( is_digit(*c) )
        {
            number n = parse_number(c);

            std::cout << "got number=\"";
            n.print_to_cout();
            std::cout << "\"" << std::endl;
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
