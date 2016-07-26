#include "math_brain/parser/expression.hpp"

#include <iostream>
#include <string>

int main(/*int argc, char **argv*/)
{
    std::cout << "Enter a mathematical expression: ";
    std::string input;
    std::cin >> input;
    std::cout << "Your input: " << input << std::endl;
    math_brain::parser::expression exp;
    math_brain::parser::expression::parse( input, &exp );
    exp.print_objects_to_stream(std::cout);
    return 0;
}
