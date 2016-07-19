cmake_minimum_required (VERSION 2.6)
project (math_brain)
add_executable(math_brain
src/math_brain/parser/mathematical_expression_parser.cpp
src/math_brain/number.cpp
src/math_brain/mathematical_object.cpp
src/main.cpp

src/unit_testing/math_brain/parser/mathematical_expression_parser.cpp
src/unit_testing/math_brain/number.cpp
src/unit_testing/math_brain/unit_testing.cpp
)
