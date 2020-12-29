// ========================================================================== //
// Author: Tancredi-Paul Grozav <paul@grozav.info>
// ========================================================================== //
#include "math_brain/arithmetic.hpp"
#include "math_brain/number.hpp"

//#include <cstddef> // size_t
// ========================================================================== //
namespace math_brain
{
// ========================================================================== //
number::number(::std::string &str):
  math_brain::mathematical_object(str, TYPE_NUMBER)
{
}
// ========================================================================== //
number::number(const char c_str[]):
  math_brain::mathematical_object(c_str, TYPE_NUMBER)
{
}
// ========================================================================== //
::std::ostream& operator<<(::std::ostream &os, const number &n)
{
  return os << n.get_string_representation();
}
// ========================================================================== //
bool number::less_than(const number &n) const
{
  ::std::string n2_str = n.get_string_representation();
  size_t n1_str_size = _str.size();
  size_t n2_str_size = n2_str.size();
  if(n1_str_size == n2_str_size)
  {// same number of digits
    for(size_t i=0; i<n1_str_size; i++)
    {
      if(arithmetic::digit_less_than(_str.at(i), n2_str.at(i)))
      {
        return true;
      }
      else if(arithmetic::digit_less_than(n2_str.at(i), _str.at(i)))
      {
        return false;
      }
    }
    return false; // they are equal if not returned from for
  }
  else
  {// different number of digits
    if(n1_str_size > n2_str_size)
    {
      return false; // n1 is greater than, not less than
    }
    else
    {
      return true; // n1 is less than
    }
  }
}
// ========================================================================== //
bool number::operator<(const number& other) const
{
  return this->less_than(other);
}
// ========================================================================== //
bool number::greater_than(const number &n) const
{
  return !equals(n) && n.less_than(*this);
}
// ========================================================================== //
bool number::operator>(const number& other) const
{
  return this->greater_than(other);
}
// ========================================================================== //
} // namespace math_brain
// ========================================================================== //
