#ifndef MATH_BRAIN__PARSER__EXPRESSION_HPP
#define MATH_BRAIN__PARSER__EXPRESSION_HPP

#include "../number.hpp"
#include "../mathematical_object.hpp"

#include <vector> // std:vector

namespace math_brain
{
namespace parser
{

/**
 * @brief An expression parser.
 */
class expression
{
private:
    /**
     * @brief Objects involved in the expression.
     */
    std::vector<mathematical_object> _objects;

public:
    /**
     * Create a new expression object from a C string.
     * @param c - A pointer to a C style string that contains the expression.
     * @param expr - An expression that should be created based on the string.
     * that should be parsed as an expression object.
     */
    static void parse(const char *c, expression *expr);

    /**
     * @brief Default expression constructor
     */
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
