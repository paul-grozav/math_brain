#include "gtest/gtest.h"
#include "../math_brain/number.hpp"
#include "../math_brain/arithmetic.hpp"

using namespace math_brain;
using namespace math_brain::arithmetic;

// ========================================================================== //
TEST(number, equality_properties)
{
    number a("1");
    number b("1");
    number c("1");

    // test equality operation
    ASSERT_EQ(number("1"), a);
    ASSERT_EQ(number("1"), b);

    // equality is reflexive ( a == a )
    ASSERT_TRUE( a.equals(a) );
    ASSERT_TRUE( b.equals(b) );

    // equality is symmetric ( a == b <=> b == a )
    ASSERT_TRUE( a.equals(b) );
    ASSERT_TRUE( b.equals(a) );

    // equality is transitive ( ( a == b && b == c ) => a == c )
    ASSERT_TRUE( a.equals(b) );
    ASSERT_TRUE( b.equals(c) );
    ASSERT_TRUE( a.equals(c) );
}
// ========================================================================== //
TEST(number, add_digits)
{
    char r[2];

    // no carry in and no carry out
    r[0] = 0; r[1] = 0;
    add_digits('1', '8', r);
    ASSERT_EQ('9', r[0]);
    ASSERT_EQ(0, r[1]);

    // no carry in and carry out
    r[0] = 0; r[1] = 0;
    add_digits('1', '9', r);
    ASSERT_EQ('0', r[0]);
    ASSERT_EQ(1, r[1]);

    // carry in and no carry out
    r[0] = 0; r[1] = 1;
    add_digits('1', '7', r);
    ASSERT_EQ('9', r[0]);
    ASSERT_EQ(0, r[1]);

    // carry in and carry out
    r[0] = 0; r[1] = 1;
    add_digits('1', '9', r);
    ASSERT_EQ('1', r[0]);
    ASSERT_EQ(1, r[1]);

    ASSERT_THROW(add_digits('*', '*', r), std::runtime_error);
    ASSERT_THROW(add_digits('*', '2', r), std::runtime_error);
    ASSERT_THROW(add_digits('2', '*', r), std::runtime_error);
    ASSERT_NO_THROW(add_digits('2', '2', r));
}
// ========================================================================== //
TEST(number, addition_properties)
{
    number zero("0");
    number a("1");
    number b("2");
    number c("3");

    // addition is commutative ( a+b == b+a )
    ASSERT_EQ( add(a,b), add(b,a) );

    // addition is associative ( b+(c+d) == (b+c)+d )
    ASSERT_EQ( add(a, add(b,c)), add(add(a,b), c) );

    // identity element ( a+0 == 0+a == a )
    ASSERT_EQ( add(a, zero), a );
    ASSERT_EQ( add(zero, a), a );
    ASSERT_EQ( add(zero, a), add(a, zero) );
}
// ========================================================================== //
TEST(number, addition_large_number)
{
    number a("99999999999999999999999999999999999999999999999999999999999999999"
        "9999999999999999999999999999999999999999999999999999999999999999999");
    number b("1");
    number r("10000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000");
    ASSERT_EQ(r, add(a, b));
}
// ========================================================================== //
TEST(number, comparison_less_than)
{
    // 0 is not smaller than 0
    {
        number a("0");
        number b("0");
        ASSERT_FALSE(a.less_than(b));
    }
    // 0 is smaller than 1
    {
        number a("0");
        number b("1");
        ASSERT_TRUE(a.less_than(b));
    }
    // 1 is not smaller than 0
    {
        number a("1");
        number b("0");
        ASSERT_FALSE(a.less_than(b));
    }
    // 812 is not smaller than 62
    {
        number a("812");
        number b("62");
        ASSERT_FALSE(a.less_than(b));
    }
    // 0 is smaller than 100
    {
        number a("0");
        number b("100");
        ASSERT_TRUE(a.less_than(b));
    }
    // 9999999999999999999999999999999999999999999999999999999999
    // is smaller than
    // 10000000000000000000000000000000000000000000000000000000000
    {
        number a( "9999999999999999999999999999999999999999999999999999999999");
        number b("10000000000000000000000000000000000000000000000000000000000");
        ASSERT_TRUE(a.less_than(b));
    }
}
// ========================================================================== //
TEST(number, comparison_less_than_properties)
{
    number a("1"), b("2"), c("3");

    // < is transitive ( ( a < b && b < c ) => a < c )
    ASSERT_TRUE( a.less_than(b) );
    ASSERT_TRUE( b.less_than(c) );
    ASSERT_TRUE( a.less_than(c) );
}
// ========================================================================== //
TEST(number, comparison_greater_than)
{
    // 0 is not greater than 0
    {
        number a("0");
        number b("0");
        ASSERT_FALSE(a.greater_than(b));
    }
    // 0 is greater than 1
    {
        number a("0");
        number b("1");
        ASSERT_FALSE(a.greater_than(b));
    }
    // 1 is not greater than 0
    {
        number a("1");
        number b("0");
        ASSERT_TRUE(a.greater_than(b));
    }
    // 812 is not greater than 62
    {
        number a("812");
        number b("62");
        ASSERT_TRUE(a.greater_than(b));
    }
    // 0 is greater than 100
    {
        number a("0");
        number b("100");
        ASSERT_FALSE(a.greater_than(b));
    }
    // 9999999999999999999999999999999999999999999999999999999999
    // is greater than
    // 10000000000000000000000000000000000000000000000000000000000
    {
        number a( "9999999999999999999999999999999999999999999999999999999999");
        number b("10000000000000000000000000000000000000000000000000000000000");
        ASSERT_FALSE(a.greater_than(b));
    }
}
// ========================================================================== //
TEST(number, comparison_greater_than_properties)
{
    number a("3"), b("2"), c("1");

    // > is transitive ( ( a > b && b > c ) => a > c )
    ASSERT_TRUE( a.greater_than(b) );
    ASSERT_TRUE( b.greater_than(c) );
    ASSERT_TRUE( a.greater_than(c) );
}
// ========================================================================== //
TEST(number, subtract_digits)
{
    char r[2];

    // no carry in and no carry out
    r[0] = 0; r[1] = 0;
    subtract_digits('8', '1', r);
    ASSERT_EQ('7', r[0]);
    ASSERT_EQ(0, r[1]);

    // no carry in and carry out
    r[0] = 0; r[1] = 0;
    subtract_digits('1', '9', r);
    ASSERT_EQ('2', r[0]);//11-9=2 borrowed a ten
    ASSERT_EQ(1, r[1]);

    // carry in and no carry out
    r[0] = 0; r[1] = 1;
    subtract_digits('7', '1', r);
    ASSERT_EQ('5', r[0]);
    ASSERT_EQ(0, r[1]);

    // carry in and carry out
    r[0] = 0; r[1] = 1;
    subtract_digits('1', '9', r);
    ASSERT_EQ('1', r[0]);
    ASSERT_EQ(1, r[1]);

    ASSERT_THROW(add_digits('@', '@', r), std::runtime_error);
    ASSERT_THROW(add_digits('@', '2', r), std::runtime_error);
    ASSERT_THROW(add_digits('0', '@', r), std::runtime_error);
    ASSERT_NO_THROW(add_digits('0', '0', r));
}
// ========================================================================== //
TEST(number, subtraction_test)
{
    // subtracting a greater number from a smaller one. Exception, not
    // implemented yet.
    {
        number a("100");
        number b("999");
        ASSERT_THROW(subtract(a, b), std::runtime_error);
    }
    // subtract random numbers
    {
        number a("99912");
        number b("999");
        number r("98913");
        ASSERT_EQ(r, subtract(a, b));
    }
    // subtract large number from another large number
    {
        number a("93295283891203829807903470121036541837465918740129865017432");
        number b("975301765378926041692758273849020176405198279283");
        number r("93295283890228528042524544079343783563616898563724666738149");
        ASSERT_EQ(r, subtract(a, b));
    }
}
// ========================================================================== //
