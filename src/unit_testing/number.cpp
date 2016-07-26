#include "gtest/gtest.h"
#include "../math_brain/number.hpp"
#include "../math_brain/arithmetic.hpp"

using namespace math_brain;
using namespace math_brain::arithmetic;

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

    // equality transitive ( ( a == b && b == c ) => a == c )
    ASSERT_TRUE( a.equals(b) );
    ASSERT_TRUE( b.equals(c) );
    ASSERT_TRUE( c.equals(a) );
}

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
}

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

TEST(number, addition_large_number)
{
    number a("99999999999999999999999999999999999999999999999999999999999999999"
        "9999999999999999999999999999999999999999999999999999999999999999999");
    number b("1");
    number r("10000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000");
    ASSERT_EQ(r, add(a, b));
}
