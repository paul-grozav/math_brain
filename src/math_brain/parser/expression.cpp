#include "expression.hpp"
#include "parser.hpp"
#include "../number.hpp"

#include <iostream>

using namespace std;

namespace math_brain
{
namespace parser
{

void expression::parse(const char *c, expression *expression)
{
    while( *c != '\0' )
    {
        if( math_brain::parser::is_digit(*c) )
        {
            number *n = new number();
            number::parse_number(c, *n);

            expression->_objects.push_back( mathematical_object(
                n, mathematical_object::TYPE_NUMBER
            ) );
        }
        else if ( is_valid_sign(*c) )
        {
            expression->_objects.push_back( mathematical_object(
                static_cast<void*>(const_cast<char*>(c)),
                mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION
            ) );
            c++;
        }
        else
        {
            cout << "Ignoring invalid sign:'" << *c << "'" << endl;
            c++; // ignore character and go to next one
        }
    }
}

expression::expression()
{
}

expression::~expression()
{
    vector<mathematical_object>::iterator it;
    mathematical_object::type object_type;
    void *object_pointer = 0;
    for (it = _objects.begin(); it != _objects.end(); it++)
    {
        object_type = it->get_object_type();
        object_pointer = it->get_object();
        if ( object_type == mathematical_object::TYPE_NUMBER )
        {
            delete static_cast<number*>(object_pointer);
        }
        else if (
            object_type == mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION
        )
        {
            // this points to the acctual string, no need to delete it
//            delete static_cast<char*>(object_pointer);
        }
    }
}

void expression::print_objects()
{
    vector<mathematical_object>::iterator it;
    mathematical_object::type object_type;
    void *object_pointer = 0;
    for (it = _objects.begin(); it != _objects.end(); it++)
    {
        object_type = it->get_object_type();
        object_pointer = it->get_object();
        if (object_type == mathematical_object::TYPE_UNDEFINED)
        {
            cout << "Undefined object type at " << object_pointer << endl;
        }
        else if (
            object_type == mathematical_object::TYPE_NUMBER
        )
        {
            number &n = *(static_cast<number*>(object_pointer));
            cout << "number=";
            n.print_to_cout();
            cout << endl;
        }
        else if (
            object_type == mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION
        )
        {
            char &c = *(static_cast<char*>(const_cast<void*>(object_pointer)));
            cout << "basic_arithmetic_operation=\'" << c << "\'" << endl;
        }
    }
}

} // namespace parser
} // namespace math_brain
