// ========================================================================== //
// Author: Tancredi-Paul Grozav <paul@grozav.info>
// ========================================================================== //
#include <iostream>
#include <string>

#include "math_brain/parser/expression.hpp"
// ========================================================================== //
using namespace ::std;
// ========================================================================== //
int main(/*int argc, char **argv*/)
{
  cout << "Enter a mathematical expression:" << endl;
  string input;
  cin >> input;
  cout << "Your input: " << input << endl;
  ::math_brain::parser::expression exp;
  ::math_brain::parser::expression::parse( input, &exp );
//  cout << endl << "Expression is made of:" << endl;
//  exp.print_objects_to_stream(cout);
  cout << endl << "Solving expression:" << endl;
  vector< pair<const string, ::math_brain::parser::expression> > steps;
  exp.simplify(&steps);
  cout << exp << endl;
  for(size_t i=0; i<steps.size(); i++)
  {
    cout << steps[i].first << endl
      << "=" << steps[i].second << endl;
  }
  cout << endl;
  return 0;
}
// ========================================================================== //
