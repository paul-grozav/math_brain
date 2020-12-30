// ========================================================================== //
// Author: Tancredi-Paul Grozav <paul@grozav.info>
// ========================================================================== //
#include <string>
#include <iostream>

#include "math_brain/parser/expression.hpp"
#include "math_brain/parser/parser.hpp"
#include "math_brain/number.hpp"
#include "math_brain/binary_operator.hpp"
#include "math_brain/arithmetic.hpp"
// ========================================================================== //
using namespace ::std;
// ========================================================================== //
namespace math_brain
{
namespace parser
{
// ========================================================================== //
void expression::parse(::std::string &str, expression *expr)
{
  size_t str_len = str.size();
  for ( size_t i = 0; i < str_len; i++ )
  {
    if( math_brain::parser::is_digit(str[i]) )
    {
      size_t number_length = 0;
      do
      {
        number_length++;
      }
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
void expression::print_objects_to_stream(::std::ostream &output_stream)
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
      output_stream << "number=" << n << endl;
    }
    else if (
      object_type == mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION
    )
    {
      binary_operator &op = *(static_cast<binary_operator*>(object));
      output_stream << "basic_arithmetic_operation=\"" << op << endl;
    }
  }
}
// ========================================================================== //
::std::string expression::get_string_representation() const
{
  string ret = "";
  vector<mathematical_object>::const_iterator it;
  for (it = _objects.begin(); it != _objects.end(); it++)
  {
    ret += it->get_string_representation();
  }
  return ret;
}
// ========================================================================== //
::std::vector<mathematical_object> expression::get_objects()
{
  return _objects;
}
// ========================================================================== //
bool expression::simplify_addition_and_subtraction(
  ::std::vector< ::std::pair<const ::std::string, expression> > *steps)
{
  string step_description = "";
  expression new_expr;
  expression *expr = this;
  if(steps->size() > 0)
  {
    expr = &(steps->at( steps->size()-1 ).second);
  }
//  cout << "simplify_addition("; expr->print(cout); cout << ")" << endl;
  size_t size = expr->_objects.size();
  for(size_t i=0; i<size; i++)
  {
    mathematical_object &object = expr->_objects.at(i);
    if(object.get_object_type() ==
      mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION &&
      object.get_string_representation() == "+"
    )
    {
      step_description = "Evaluating expression: "
        + expr->_objects.at(i-1).get_string_representation() + "+"
        + expr->_objects.at(i+1).get_string_representation()
	+ " and replacing in the original expresion.";
      number new_object = arithmetic::add(
        *(static_cast<number*>(&(expr->_objects.at(i-1)))),
        *(static_cast<number*>(&(expr->_objects.at(i+1))))
      );
      new_expr._objects.pop_back(); // remove left operand
      new_expr._objects.push_back(new_object);
      i++; // remove right operand

      for(size_t j=i+1; j<size; j++)
      {
        // copy object to new expression
        new_expr._objects.push_back(expr->_objects.at(j));
      }

//      cout << "new expression " << new_expr._objects.size() << ":";
//      new_expr.print(cout);
//      cout << endl;

      steps->push_back(make_pair(step_description, new_expr));
      return true;
    }
    else if(
      object.get_object_type() ==
      mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION &&
      object.get_string_representation() == "-"
    )
    {
      step_description = "Evaluating expression: "
        + expr->_objects.at(i-1).get_string_representation() + "-"
        + expr->_objects.at(i+1).get_string_representation()
	+ " and replacing in the original expression.";
      number new_object = arithmetic::subtract(
        *(static_cast<number*>(&(expr->_objects.at(i-1)))),
        *(static_cast<number*>(&(expr->_objects.at(i+1))))
      );
      new_expr._objects.pop_back(); // remove left operand
      new_expr._objects.push_back(new_object);
      i++; // remove right operand

      for(size_t j=i+1; j<size; j++)
      {
        // copy object to new expression
        new_expr._objects.push_back(expr->_objects.at(j));
      }

//      cout << "new expression " << new_expr._objects.size() << ":";
//      new_expr.print(cout);
//      cout << endl;

      steps->push_back(make_pair(step_description, new_expr));
      return true;
    }
    else
    {
      new_expr._objects.push_back(object);// copy object to new expression
    }
  }
  return false;
}
// ========================================================================== //
bool expression::simplify_once(
  ::std::vector< ::std::pair<const ::std::string, expression> > *steps)
{
  return false
    || simplify_addition_and_subtraction(steps);
}
// ========================================================================== //
void expression::simplify(
  ::std::vector< ::std::pair<const ::std::string, expression> > *steps)
{
  while( simplify_once(steps) )
  {
  }
}
// ========================================================================== //
bool expression::equals(const expression& other) const
{
  bool ret = true;
  ret = ret && ( _objects.size() == other._objects.size() );
  for (size_t i=0; i<_objects.size(); ++i)
  {
    ret = ret && _objects[i] == other._objects[i];
  }
  return ret;
}
// ========================================================================== //
bool expression::operator==(const expression& other) const
{
  return equals(other);
}
// ========================================================================== //
::std::ostream& operator<<(::std::ostream &os, const expression &ex)
{
  return os << ex.get_string_representation();
}
// ========================================================================== //
} // namespace parser
} // namespace math_brain
// ========================================================================== //
