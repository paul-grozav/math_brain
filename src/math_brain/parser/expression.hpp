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

//    /**
//     * This method will delete every object in the _objects list.
//     */
//    ~expression();

    /**
     * Print objects in expression with details.
     * @param output_stream - The output stream where the objects should be
     * printed.
     */
    void print_objects_to_stream(std::ostream& output_stream);

    /**
     * Print objects in expression.
     * @param output_stream - The output stream where the objects should be
     * printed.
     */
    void print(std::ostream& output_stream);

    /**
     * @brief get_objects Returns a copy of the vector of mathematical objects
     * that are members of this equation.
     * @note You should not delete any pointer from this vector, because the
     * pointers are deleted when the expression is destroyed.
     * @return Returns a copy of the vector of mathematical objects that are
     * member of this equation.
     */
    std::vector<mathematical_object> get_objects();

    /**
     * @brief simplify Simplifies the expression by appliying operations.
     * For example: "2+3" is simplified to "5".
     * @param steps - The steps it took to simplify the expression.
     */
    void simplify(std::vector<expression> *steps);

    /**
     * @brief simplify an expression by one step.
     * @param steps - The steps it took to simplify the expression.
     * @return True if and only if a simpler expression was added to the list of
     * steps.
     * @note Example: simplify_once() on "1+2+3+4" might become "3+3+4" by
     * solving 1+2 and copying +3+4.
     * @note maybe we could make this private, it's called by simplify()
     */
    bool simplify_once(std::vector<expression> *steps);

    /**
     * @brief solve the first addition found and copy the rest of the objects.
     *
     * Takes this instance or the last expression from the vector, and solves
     * the first addition it finds there. The rest of the objects are copied to
     * the new expression.
     * @param steps - The steps it took to simplify the expression.
     * @return True if and only if a simpler expression was added to the list of
     * steps.
     * @note Example: simplify_addition() on "1+2+3+4" might become "3+7" by
     * solving 1+2 and 3+4.
     */
    bool simplify_addition(std::vector<expression> *steps);

    /**
     * Get the index of the first mathematical object that has gt given object
     * type.
     * @param object_type
     * @param start_index
     * @return
     */
    size_t index_of_object_type(mathematical_object::object_type object_type,
        size_t start_index);

    /**
     * @brief Will compare two expressions by comparing their string
     * representation and their type.
     * @param other - The other expression that is compared with the current
     * instance.
     * @return True if and only if the two expressions are equal.
     */
    bool equals(const expression& other) const;

    /**
     * @brief operator == Will compare two expressions by comparing their string
     * representation.
     * @see equals().
     * @param other - The other expression that is compared with the current
     * instance.
     * @return True if and only if the two expressions are equal.
     */
    bool operator==(const expression& other) const;

};

} // namespace parser
} // namespace math_brain
#endif // MATH_BRAIN_PARSER_EXPRESSION_HPP
