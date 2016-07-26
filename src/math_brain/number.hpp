#ifndef MATH_BRAIN_NUMBER_HPP
#define MATH_BRAIN_NUMBER_HPP

#include <string> // std::string
#include <ostream> // std::ostream

/**
 * math_brain namespace holds all the project logic.
 */
namespace math_brain
{

// ========================================================================== //
/**
 * A number is defined by it's string representation.
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class number
{
private:
    /**
     * The string representation of the number.
     */
    std::string _str;

public:
    /**
     * Creates a number instance with an empty string as it's representation.
     */
    number();

    /**
     * Creates a number instance using the given string representation.
     * @param str - A number represented as a string. This value will be copied
     * into this number instance.
     */
    number(std::string &str);

    /**
     * Creates a number instance using the given string representation.
     * @param c_str - A number represented as constant char array. A new string
     * will be created from this char[] and it will be assigned to this
     * instance.
     */
    number(const char c_str[]);

    /**
     * Set a new string representation for the current instance.
     * @param str - A number represented as a string. This value will be copied
     * into this number instance.
     */
    void set(std::string &str);

    /**
     * Set a new string representation for the current instance.
     * @param c_str - A number represented as constant char array. A new string
     * will be created from this char[] and it will be assigned to this
     * instance.
     */
    void set(const char c_str[]);

    /**
     * @return A copy of the string representation of this number.
     */
    std::string get_string_representation() const;

    /**
     * Print number to the given output stream and flush it.
     * @param output_stream - The output stream where the number should be
     * printed.
     */
    void print_to_stream(std::ostream& output_stream);

    /**
     * @brief Will compare two numbers by comparing their string representation.
     * @param other - The other number that is compared with the current
     * instance.
     * @return True if and only if the two numbers are equal.
     */
    bool equals(const number& other) const;

    /**
     * @brief operator == Will compare two numbers by comparing their string
     * representation.
     * @see equals().
     * @param other - The other number that is compared with the current
     * instance.
     * @return True if and only if the two numbers are equal.
     */
    bool operator==(const number& other) const;

//    /**
//     * @note not used
//     * @param str - A string reference that contains the number to be parser
//     * @param index - position in given string, where the number starts.
//     * @param number - A number that will be initialized with the characters
//     * starting at the given pointer.
//     * @return Number of digits in the number.
//     */
//    size_t static parse_number(std::string &str, size_t index, number &number);


};

} // namespace math_brain

#endif // MATH_BRAIN_NUMBER_HPP
