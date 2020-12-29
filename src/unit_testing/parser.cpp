// ========================================================================== //
// Author: Tancredi-Paul Grozav <paul@grozav.info>
// ========================================================================== //
#include "gtest/gtest.h"

#include "math_brain/parser/parser.hpp"
// ========================================================================== //
/**
 * Test the ::math_brain::parser::is_digit function.
 */
TEST(parser, is_digit)
{
  for (char i=-128; i<=127; i++)
  {
    if(47 < i && i < 58)
    {
      ASSERT_TRUE( ::math_brain::parser::is_digit(i) );
    }
    else
    {
      ASSERT_FALSE( ::math_brain::parser::is_digit(i) );
    }

    // exit condition because when i=127 and i++ i becomes -128
    if(i==127)
    {
      break;
    }
  }
}
// ========================================================================== //
/**
 * Test the ::math_brain::parser::is_valid_sign function.
 */
TEST(parser, is_valid_sign)
{
  for (char i=-128; i<=127; i++)
  {
    if ( !( // not valid case
      // two following valid cases
      // i is 43 ('+') or 45 ('-') and is_valid_sign(i) == true
      ((i == 43 || i == 45) &&
        ::math_brain::parser::is_valid_sign(i) == true) ||
      // OR i is not 43 and not 45 and is_valid_sign  == false
      (i != 43 && i != 45 &&
        ::math_brain::parser::is_valid_sign(i) == false)
    ) )
    {
      std::cerr << "testing__is_digit(): i=" << static_cast<int>(i)
        << " fails." << std::endl;
      if(!(47 < i && i < 58 && ::math_brain::parser::is_digit(i) == true))
      {
        std::cout << "C1" << std::endl;
      }
      ASSERT_EQ(1, 2); // not ok ... should not reach this point
    }
    if(i==127) // exit condition because when i=127 and i++ i becomes -128
    {
      break;
    }
  }
}
// ========================================================================== //
