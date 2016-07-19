#ifndef MATH_BRAIN__PARSER__EXPRESSION_HPP
#define MATH_BRAIN__PARSER__EXPRESSION_HPP

#include "../number.hpp"
#include "../mathematical_object.hpp"

#include <vector> // std:vector

namespace math_brain
{
namespace parser
{

class expression
{
private:
    std::vector<mathematical_object> _objects;

public:
    /**
     * Create a new expression object from a C string.
     * @param c - A pointer to a C style string that contains the expression
     * that should be parsed as an expression object.
     */
    static void parse(const char *c, expression *expression);

    expression();

    /**
     * This method will delete every pointer to every object in the _objects
     * list.
     */
    ~expression();

    /**
     * Print objects in expression.
     */
    void print_objects();
};

} // namespace parser
} // namespace math_brain
#endif // MATH_BRAIN__PARSER__EXPRESSION_HPP
