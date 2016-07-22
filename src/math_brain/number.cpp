#include "parser/parser.hpp"
#include "number.hpp"

#include <iostream> // cout
#include <cstddef> // size_t

using namespace std;

namespace math_brain
{

number::number()
{
}

number::number(string &str):
    _str(str)
{
}

void number::set(string &str)
{
    _str = str;
}


void number::print_to_cout()
{
    if ( _str == "" )
    {
        return;
    }
    cout << _str;
    cout.flush();
}

bool number::operator==(const number& other) const
{
    return _str == other._str;
}

//size_t number::parse_number(string &str, size_t index, number &number)
//{
//    size_t str_len = str.size();
//    string s;
//    for (size_t i = index; i < str_len && parser::is_digit(str[i]); i++)
//        s.push_back(str[i]);
//    number.set(s);
//    return s.size();
//}

} // namespace math_brain
