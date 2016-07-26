#ifndef MATH_BRAIN_PARSER_EXPRESSION_HPP
#define MATH_BRAIN_PARSER_EXPRESSION_HPP

#include "../number.hpp"
#include "../mathematical_object.hpp"

#include <ostream> // std::ostream
#include <string> // std::string
#include <vector> // std:vector

namespace math_brain
{
namespace parser
{

/**
 * @brief An expression object is a vector with multiple mathematical objects.
 * Example: "123+456" is an expression and it's elements are number 123,
 * operator + and number 456.
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
     * Create a new expression object from a string.
     * @param str - A string that contains the expression.
     * @param expr - An expression that should be created based on the string.
     */
    static void parse(std::string &str, expression *expr);

    /**
     * @brief Default expression constructor.
     *
     * It will add no objects to the expression instance.
     */
    expression();

    /**
     * This method will delete every pointer to every object in the _objects
     * list.
     */
    ~expression();

    /**
     * Print objects in expression.
     * @param output_stream - The output stream where the objects should be
     * printed.
     */
    void print_objects_to_stream(std::ostream& output_stream);

    /**
     * @brief get_objects Returns a copy of the vector of mathematical objects
     * that are members of this equation.
     * @note You should not delete any pointer from this vector, because the
     * pointers are deleted when the expression is destroyed.
     * @return Returns a copy of the vector of mathematical objects that are
     * member of this equation.
     */
    std::vector<mathematical_object> get_objects();

};

} // namespace parser
} // namespace math_brain
#endif // MATH_BRAIN_PARSER_EXPRESSION_HPP
