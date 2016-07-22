#include "expression.hpp"
#include "parser.hpp"
#include "../number.hpp"

#include <string>
#include <iostream>

using namespace std;

namespace math_brain
{
namespace parser
{

void expression::parse(string &str, expression *expr)
{
    size_t str_len = str.size();
    for ( size_t i = 0; i < str_len; i++ )
    {
        if( math_brain::parser::is_digit(str[i]) )
        {
            size_t number_length = 0;
            do
                number_length++;
            while(math_brain::parser::is_digit(str[i+number_length]));
            string s = str.substr(i, number_length);

            expr->_objects.push_back( mathematical_object(
                new number(s), mathematical_object::TYPE_NUMBER
            ) );
            i += number_length-1; // skip number characters
        }
        else if ( is_valid_sign(str[i]) )
        {
            void *object_pointer = static_cast<void*>(new char(str[i]));
            expr->_objects.push_back( mathematical_object(
                object_pointer,
                mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION
            ) );
        }
        else
        {
            cout << "Ignoring invalid sign:'" << str[i] << "'" << endl;
        }
    }
}

expression::expression()
{
}

expression::~expression()
{
    vector<mathematical_object>::iterator it;
    mathematical_object::object_type object_type;
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
            delete static_cast<char*>(object_pointer);
        }
    }
}

void expression::print_objects()
{
    vector<mathematical_object>::iterator it;
    mathematical_object::object_type object_type;
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

vector<mathematical_object> expression::get_objects()
{
    return _objects;
}

} // namespace parser
} // namespace math_brain
