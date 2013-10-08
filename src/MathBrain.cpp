/*
 * MathBrain.cpp
 *
 * Created on: 2013-09-20
 * Begun by: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#include <iostream>

#include "math/grade1/NaturalNumber.h" // NaturalNumber
#include "math/grade1/Addition.h" // Addition::add()

using namespace std;
using namespace math::grade1;

int main(int argc, char* argv[])
{
	NaturalNumber x = NaturalNumber("00193");
	NaturalNumber y = NaturalNumber("0807");
	cout << (x+y).toString() << endl;
	return 0;
}
