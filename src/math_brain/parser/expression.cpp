#include "expression.hpp"
#include "parser.hpp"
#include "../number.hpp"
#include "../binary_operator.hpp"
#include "../arithmetic.hpp"

#include <string>
#include <iostream>

using namespace std;

namespace math_brain
{
namespace parser
{

// ========================================================================== //
void expression::parse(string &str, expression *expr)
{
    size_t str_len = str.size();
    for ( size_t i = 0; i < str_len; i++ )
    {
        // delete is called in ~mathematical_object, the owner
        if( math_brain::parser::is_digit(str[i]) )
        {
            size_t number_length = 0;
            do
                number_length++;
            while(math_brain::parser::is_digit(str[i+number_length]));
            string s = str.substr(i, number_length);

            expr->_objects.push_back( number(s) );
            i += number_length-1; // skip number characters
        }
        else if ( is_valid_sign(str[i]) )
        {
            expr->_objects.push_back( binary_operator( str[i] ) );
        }
        else
        {
            cout << "Ignoring invalid sign:'" << str[i] << "'" << endl;
        }
    }
}
// ========================================================================== //
expression::expression()
{
}
// ========================================================================== //
expression::~expression()
{
}
// ========================================================================== //
void expression::print_objects_to_stream(ostream &output_stream)
{
    vector<mathematical_object>::iterator it;
    mathematical_object::object_type object_type;
    mathematical_object *object = NULL;
    for (it = _objects.begin(); it != _objects.end(); it++)
    {
        object_type = it->get_object_type();
        object = &(*it);
        if (object_type == mathematical_object::TYPE_UNDEFINED)
        {

            output_stream << "Undefined object type" << endl;
        }
        else if ( object_type == mathematical_object::TYPE_NUMBER )
        {
            number &n = *(static_cast<number*>(object));
            output_stream << "number=";
            n.print_to_stream(output_stream);
            output_stream << endl;
        }
        else if (
            object_type == mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION
        )
        {
            binary_operator &op = *(static_cast<binary_operator*>(object));
            output_stream << "basic_arithmetic_operation=\"";
            op.print_to_stream(output_stream);
            output_stream << "\"" << endl;
        }
    }
}
// ========================================================================== //
vector<mathematical_object> expression::get_objects()
{
    return _objects;
}
// ========================================================================== //
void expression::simplify()
{
    // if only 1 object then there's nothing to simplify. Maybe call simplify on
    // that object ?? like "10/5"
    if(_objects.size() > 1)
    {
        // left number
        mathematical_object *left_operand_object = &(_objects[0]);
        if(left_operand_object->get_object_type() !=
            mathematical_object::TYPE_NUMBER)
        {
            return;
        }
        number &left_number =
            *(static_cast<number*>(left_operand_object));

        // right number
        mathematical_object *right_operand_object = &(_objects[2]);
        if(left_operand_object->get_object_type() !=
            mathematical_object::TYPE_NUMBER)
        {
            return;
        }
        number &right_number =
            *(static_cast<number*>(right_operand_object));

        number result = arithmetic::add(left_number, right_number);
        result.print_to_stream(std::cout);
    }
}
// ========================================================================== //

} // namespace parser
} // namespace math_brain
