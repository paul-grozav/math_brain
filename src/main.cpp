#include "math_brain/parser/expression.hpp"
#include "unit_testing/math_brain/unit_testing.hpp"

#include <iostream>
#include <string>

int main(/*int argc, char **argv*/)
{
    if ( !unit_testing::math_brain::testing__() )
    {
        std::cerr << "Something's not right. Unit tests failed" << std::endl;
        return 1;
    }
    std::cout << "Enter a mathematical expression: ";
    std::string input_str;
    std::cin >> input_str;
    const char *input = input_str.c_str();
    std::cout << "Your input: " << input << std::endl;
    math_brain::parser::expression exp;
    math_brain::parser::expression::parse( input, &exp );
    exp.print_objects();
    return 0;
}
