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
  _str(str)
  , _object_type(type)
{
}
// ========================================================================== //
mathematical_object::mathematical_object(const char c_str[], object_type type):
  _str(string(c_str))
  , _object_type(type)
{
}
// ========================================================================== //
mathematical_object::object_type mathematical_object::get_object_type()
{
  return _object_type;
}
// ========================================================================== //
::std::string mathematical_object::get_string_representation() const
{
  return _str;
}
// ========================================================================== //
bool mathematical_object::equals(const mathematical_object& other) const
{
  return _str == other._str && _object_type == other._object_type;
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
