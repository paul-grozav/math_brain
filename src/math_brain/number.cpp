//#include "parser/parser.hpp"
#include "number.hpp"

//#include <cstddef> // size_t

namespace math_brain
{

// ========================================================================== //
number::number(std::string &str):
    math_brain::mathematical_object(str, TYPE_NUMBER)
{
}
// ========================================================================== //
number::number(const char c_str[]):
    math_brain::mathematical_object(c_str, TYPE_NUMBER)
{
}
// ========================================================================== //

} // namespace math_brain
