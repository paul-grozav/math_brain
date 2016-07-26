#include "parser/parser.hpp"
#include "number.hpp"

#include <cstddef> // size_t

using namespace std;

namespace math_brain
{

// ========================================================================== //
number::number():
    _str("")
{
}
// ========================================================================== //
number::number(string &str):
    _str(str)
{
}
// ========================================================================== //
number::number(const char c_str[]):
    _str(string(c_str))
{
}
// ========================================================================== //
void number::set(string &str)
{
    _str = str;
}
// ========================================================================== //
void number::set(const char c_str[])
{
    _str = string(c_str);
}
// ========================================================================== //
std::string number::get_string_representation() const
{
    return _str;
}
// ========================================================================== //
void number::print_to_stream(ostream& output_stream)
{
    if ( _str.size() == 0 )
    {
        return;
    }
    output_stream << _str;
    output_stream.flush();
}
// ========================================================================== //
bool number::equals(const number& other) const
{
    return _str == other._str;
}
// ========================================================================== //
bool number::operator==(const number& other) const
{
    return equals(other);
}
// ========================================================================== //
//size_t number::parse_number(string &str, size_t index, number &number)
//{
//    size_t str_len = str.size();
//    string s;
//    for (size_t i = index; i < str_len && parser::is_digit(str[i]); i++)
//        s.push_back(str[i]);
//    number.set(s);
//    return s.size();
//}
// ========================================================================== //

} // namespace math_brain
