#include "parser/parser.hpp"
#include "number.hpp"

#include <iostream> // std::cout

namespace math_brain
{

number::number():
    _pointer(NULL), _length(0)
{
}

number::number(const char *pointer, size_t length):
    _pointer(pointer), _length(length)
{
}

void number::set(const char *pointer, size_t length)
{
    _pointer = pointer;
    _length = length;
}

void number::print_to_cout()
{
    if ( _pointer == NULL || _length == 0 )
    {
        return;
    }
    for (size_t i=0; i<_length; i++)
    {
        std::cout.write(_pointer+i, 1);
    }
    std::cout.flush();
}

void number::parse_number(const char *&string, number &number)
{
    const char *number_pointer = string;
    size_t number_length = 0;
    do
    {
        number_length++;
        string++;
    }
    while(parser::is_digit(*string));
    number.set(number_pointer, number_length);
}

} // namespace math_brain
