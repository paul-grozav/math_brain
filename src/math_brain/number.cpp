#include "number.hpp"

#include <iostream> // std::cout

namespace math_brain
{

number::number(const char *pointer, size_t length):
    _pointer(pointer), _length(length)
{
}

void number::print_to_cout()
{
    for(size_t i=0; i<_length; i++)
    {
        std::cout.write(_pointer+i, 1);
    }
    std::cout.flush();
}

} // namespace math_brain
