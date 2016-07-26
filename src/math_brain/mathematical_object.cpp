#include "mathematical_object.hpp"

#include <cstddef> // NULL

namespace math_brain
{

// ========================================================================== //
mathematical_object::mathematical_object():
    _pointer(NULL), _object_type(TYPE_UNDEFINED)
{
}
// ========================================================================== //
mathematical_object::mathematical_object(void *pointer, object_type type):
    _pointer(pointer), _object_type(type)
{
}
// ========================================================================== //
void mathematical_object::set(void *pointer, object_type type)
{
    _pointer = pointer;
    _object_type = type;
}
// ========================================================================== //
void *mathematical_object::get_object()
{
    return _pointer;
}
// ========================================================================== //
mathematical_object::object_type mathematical_object::get_object_type()
{
    return _object_type;
}
// ========================================================================== //

} // namespace math_brain
