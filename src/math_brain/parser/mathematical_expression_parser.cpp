#include "mathematical_expression_parser.hpp"
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
        if( is_digit(*c) )
        {
            number *n = new number();
            parse_number(c, *n);

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



bool is_digit(const char c)
{
    return
           c == '0'
        || c == '1'
        || c == '2'
        || c == '3'
        || c == '4'
        || c == '5'
        || c == '6'
        || c == '7'
        || c == '8'
        || c == '9'
    ;
}

bool is_valid_sign(const char c)
{
    return
           c == '+'
        || c == '-'
    ;
}

void parse_number(const char *&string, number &number)
{
    const char *number_pointer = string;
    size_t number_length = 0;
    do
    {
        number_length++;
        string++;
    }
    while(is_digit(*string));
    number.set(number_pointer, number_length);
}

} // namespace parser
} // namespace math_brain
