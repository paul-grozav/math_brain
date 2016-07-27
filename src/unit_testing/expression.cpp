#include "gtest/gtest.h"
#include "../math_brain/parser/expression.hpp"
#include "../math_brain/number.hpp"
#include "../math_brain/binary_operator.hpp"
#include <string> // string
#include <vector> // vector
#include <iostream>

using namespace std;

TEST(parser, expression_test1)
{
    string exp_str("123+456");
    string exp_str_number1("123");
    string exp_str_number2("456");
    ::math_brain::parser::expression exp;
    ::math_brain::parser::expression::parse( exp_str, &exp );
    vector< ::math_brain::mathematical_object > objects = exp.get_objects();

    // Check first member of equation, that it's a number and it's value
    ASSERT_EQ(::math_brain::mathematical_object::TYPE_NUMBER,
        objects[0].get_object_type());
    ASSERT_EQ(::math_brain::number(exp_str_number1),
        *(static_cast< ::math_brain::number* >(&(objects[0]))));

    // Check 2nd member of equation, that it's an arithmetic operation and
    // it's value
    ASSERT_EQ(::math_brain::mathematical_object::TYPE_BASIC_ARITHMETIC_OPERATION
        , objects[1].get_object_type());
    ASSERT_EQ( ::math_brain::binary_operator('+'),
        *(static_cast< ::math_brain::binary_operator* >(&(objects[1]))));

    // Check 3rd member of equation, that it's a number and it's value
    ASSERT_EQ(::math_brain::mathematical_object::TYPE_NUMBER,
        objects[2].get_object_type());
    ASSERT_EQ(::math_brain::number(exp_str_number2),
        *(static_cast< ::math_brain::number* >(&(objects[2]))));
}
