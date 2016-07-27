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
    std::cout << std::endl << "Expression is made of:" << std::endl;
    exp.print_objects_to_stream(std::cout);
    std::cout << std::endl << "Simplified expression:";
    exp.simplify();
    std::cout << std::endl;
    return 0;
}
