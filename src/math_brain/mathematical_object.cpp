#include "mathematical_object.hpp"
#include "number.hpp"

#include <cstddef> // NULL

using namespace std;

namespace math_brain
{

// ========================================================================== //
mathematical_object::mathematical_object(std::string &str, object_type type):
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
void mathematical_object::print_to_stream(ostream& output_stream)
{
    if ( _str.size() == 0 )
    {
        return;
    }
    output_stream << _str;
//    output_stream.flush();
}
// ========================================================================== //
std::string mathematical_object::get_string_representation() const
{
    return _str;
}
// ========================================================================== //

} // namespace math_brain
