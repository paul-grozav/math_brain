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
//    std::cout << std::endl << "Expression is made of:" << std::endl;
//    std::cout << exp;
    std::cout << std::endl << "Solving expression:" << std::endl;
    std::vector<math_brain::parser::expression> steps;
    exp.simplify(&steps);
    std::cout << exp << std::endl;
    for(size_t i=0; i<steps.size(); i++)
    {
        std::cout << "=" << steps[i] << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
