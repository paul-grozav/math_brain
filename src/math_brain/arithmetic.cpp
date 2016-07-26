#include "arithmetic.hpp"

#include "number.hpp"

namespace math_brain
{
namespace arithmetic
{

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
            bs_size = bs.size();
    }else if(bs_size > as_size){
            as.insert(0, bs_size-as_size, '0');
            as_size = as.size();
    }

    char tempSum[2] = {0, 0};
    // One digit greater than the largest number, we'll remove that digit if
    // needed + 1 digit for '\0'
    char *result = new char[as_size+2];
    result[as_size+1] = '\0'; // Marks the end of the string
    // Needed if the sum is one digit larger than the terms like in 9+8 ...
    // always starts with a 1
    result[0] = '1';
    for(size_t i = as_size-1; i>0; i--){
        // when i=0 "i--" gets executed and i becomes MAX_SIZE which is >0 a
        // solution would be //     if(i==0) break; inside for
        add_digits(as[i], bs[i], tempSum); // add
        result[i+1] = tempSum[0]; // put the last digit in the final result
    }
    add_digits(as[0], bs[0], tempSum);
    result[1] = tempSum[0];
    char* r = static_cast<char*>(result);
    if(tempSum[1] != 1) r++;

    number nr(r);
    delete result;
    return nr;
}
// ========================================================================== //
void add_digits(char a, char b, char* r)
{
    // set the result. We subtract 48 because '1'(49)+'1'(49) = 49+49-48 = 50
    r[0] = a + b + r[1] - 1 * 48;
    if (r[0] > '9'){
        r[0] = r[0] - 10; // get last digit of number( since >9 )
        r[1] = 1; // set the carryOut ( r[1] )
    } else {
        r[1] = 0; // set the carryOut ( r[1] )
    }
}
// ========================================================================== //

} // namespace arithmetic
} // namespace math_brain
