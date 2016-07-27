#include "binary_operator.hpp"

using namespace std;

namespace math_brain
{

// ========================================================================== //
binary_operator::binary_operator(string &str):
    math_brain::mathematical_object(str, TYPE_BASIC_ARITHMETIC_OPERATION)
{
}
// ========================================================================== //
binary_operator::binary_operator(const char c_str[]):
    math_brain::mathematical_object(c_str, TYPE_BASIC_ARITHMETIC_OPERATION)
{
}
// ========================================================================== //
bool binary_operator::equals(const binary_operator& other) const
{
    return _str == other._str;
}
// ========================================================================== //
bool binary_operator::operator==(const binary_operator& other) const
{
    return equals(other);
}
// ========================================================================== //
binary_operator::binary_operator(const char c):
    math_brain::mathematical_object(string("").append(1, c),
        TYPE_BASIC_ARITHMETIC_OPERATION)
{
}
// ========================================================================== //

} // namespace math_brain
