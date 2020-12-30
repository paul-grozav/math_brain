// ========================================================================== //
// Author: Tancredi-Paul Grozav <paul@grozav.info>
// ========================================================================== //
#include <cstddef> // NULL

#include "math_brain/mathematical_object.hpp"
#include "math_brain/number.hpp"
// ========================================================================== //
using namespace ::std;
// ========================================================================== //
namespace math_brain
{
// ========================================================================== //
mathematical_object::mathematical_object(::std::string &str, object_type type):
  str(str), type(type)
{
}
// ========================================================================== //
mathematical_object::mathematical_object(const char c_str[], object_type type):
  str(string(c_str)), type(type)
{
}
// ========================================================================== //
mathematical_object::object_type mathematical_object::get_object_type()
{
  return type;
}
// ========================================================================== //
::std::string mathematical_object::get_string_representation() const
{
  return str;
}
// ========================================================================== //
bool mathematical_object::equals(const mathematical_object& other) const
{
  return str == other.str && type == other.type;
}
// ========================================================================== //
bool mathematical_object::operator==(const mathematical_object& other) const
{
  return equals(other);
}
// ========================================================================== //
bool mathematical_object::operator!=(const mathematical_object& other) const
{
  return !equals(other);
}
// ========================================================================== //
::std::ostream& operator<<(::std::ostream &os, const mathematical_object &o)
{
  return os << o.get_string_representation();
}
// ========================================================================== //
} // namespace math_brain
// ========================================================================== //
