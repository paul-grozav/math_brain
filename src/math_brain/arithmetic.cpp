#include "arithmetic.hpp"

#include "parser/parser.hpp"
#include "number.hpp"
#include <iostream>
#include <stdexcept>

namespace math_brain
{
namespace arithmetic
{

// ========================================================================== //
//                                 ADDITION
// ========================================================================== //
void add_digits(char a, char b, char *r)
{
    if(!parser::is_digit(a) || !parser::is_digit(b))
    {// exit if a or b not digits
        throw std::runtime_error("::math_brain::arithmetic::add_digits"
            "(char a, char b, char *r) exception : a or b is not a digit");
    }
    // set the result. We subtract 48 because '1'(49)+'1'(49) = 49+49-48 = 50
    r[0] = a + b + r[1] - 1 * 48;
    if (r[0] > '9')
    {
        r[0] = r[0] - 10; // get last digit of number( since >9 )
        r[1] = 1; // set the carryOut ( r[1] )
    } else {
        r[1] = 0; // set the carryOut ( r[1] )
    }
}
// ========================================================================== //
number add(const number &a, const number &b)
{
    // Convert to string
    std::string as = a.get_string_representation();
    std::string bs = b.get_string_representation();
    // Get size
    size_t as_size = as.size();
    size_t bs_size = bs.size();

    // Make them have same size by adding trailing zeroes
    if(as_size > bs_size){
        bs.insert(0, as_size-bs_size, '0');
        bs_size += as_size-bs_size;
    }else if(bs_size > as_size){
        as.insert(0, bs_size-as_size, '0');
        as_size += bs_size-as_size;
    }

    char tempSum[2] = {0, 0};
    // One digit greater than the largest number, we'll remove that digit if
    // needed + 1 digit for '\0'
    char *result = new char[as_size+2];
    result[as_size+1] = '\0'; // Marks the end of the string
    // Needed if the sum is one digit larger than the terms like in 9+8 ...
    // always starts with a 1
    result[0] = '1';
    for(size_t i = as_size-1; ; i--)
    {
        add_digits(as[i], bs[i], tempSum); // add
        result[i+1] = tempSum[0]; // put the last digit in the final result
        if(i==0){
            break;
        }
    }
//    add_digits(as[0], bs[0], tempSum);
//    result[1] = tempSum[0];
    char* r = static_cast<char*>(result);
    // if there was no carry out when adding last digits, then we can ignore
    // the leading one
    if(tempSum[1] != 1)
        r++;

    number nr(r);
    delete result;
    return nr;
}
// ========================================================================== //
//                                COMPARISON
// ========================================================================== //
bool digit_less_than(char a, char b)
{
    // exit if a or b not digits
    if(!(a>=48 && a<=57 && b>=48 && b<=57)) return false;
    return a < b;
}
// ========================================================================== //
//                                SUBTRACTION
// ========================================================================== //
void subtract_digits(char a, char b, char *r)
{
    if(!parser::is_digit(a) || !parser::is_digit(b))
    {// exit if a or b not digits
        throw std::runtime_error("::math_brain::arithmetic::subtract_digits"
            "(char a, char b, char *r) exception : a or b is not a digit");
    }
    r[0] = a - b - r[1] + 48;
    if (r[0] >= '0'){
        r[1] = 0;
    } else {
        r[0] = r[0] + 10;
        r[1] = 1;
    }
}
// ========================================================================== //
number subtract(const number &a, const number &b)
{
    if(a.less_than(b))
    {
        throw std::runtime_error("::math_brain::arithmetic::subtract"
            "(const number &a, const number &b) exception : "
            "Can not subtract b from a, since a is smaller than b. Negative "
            "results(numbers) not implemented yet.");
    }

    // Convert to string
    std::string as = a.get_string_representation();
    std::string bs = b.get_string_representation();
    // Get size
    size_t as_size = as.size();
    size_t bs_size = bs.size();

    // Make them have same size by adding trailing zeroes
    if(as_size > bs_size){
        bs.insert(0, as_size-bs_size, '0');
        bs_size += as_size-bs_size;
    }else if(bs_size > as_size){
        as.insert(0, bs_size-as_size, '0');
        as_size += bs_size-as_size;
    }

    char tempSum[2] = {0, 0};
    // needed + 1 digit for '\0'
    char *result = new char[as_size+1];
    result[as_size] = '\0'; // Marks the end of the string
    // subtract digit by digit and save result at the same index in result var.
    for(size_t i = as_size-1; ; i--)
    {
        subtract_digits(as[i], bs[i], tempSum); // add
        result[i] = tempSum[0]; // put the last digit in the final result
        if(i==0){
            break;
        }
    }

    // Remove leading zeroes:
    // 100-099=001
    char* r = static_cast<char*>(result);
    while(r<(result+as_size) && r[0] == '0') // do not go beyond boundary
    {
        r++;
    }
    if(r==result+as_size)
    {
        // if al 0es were removed and no digit remained, then keep the last 0 as
        // the number
        // Example: 321-321=000. All 0es are removed in while above, and here we
        // add back the last zero.
        r--;
    }

    number nr(r);
    delete result;
    return nr;
}
// ========================================================================== //

} // namespace arithmetic
} // namespace math_brain
