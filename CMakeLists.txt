include(ExternalProject) # Enable ExternalProject CMake module

cmake_minimum_required (VERSION 2.6)

# Define project and it's name
project (math_brain)

# ============================- CREATE LIBRARY -============================== #
# Create a library named math_brain and build it using the following CPP files
ADD_LIBRARY(math_brain
    src/math_brain/parser/parser.cpp
    src/math_brain/parser/expression.cpp
    src/math_brain/number.cpp
    src/math_brain/arithmetic.cpp
    src/math_brain/mathematical_object.cpp
    src/math_brain/binary_operator.cpp
)

# ==============================- CREATE APP -================================ #
# Create an executable named math_brain_app and build it using the main.cpp file
add_executable(math_brain_app
    src/app.cpp
)
# Link the math_braing_app executable with the math_brain library
target_link_libraries(math_brain_app
    math_brain
)

# =========================- CREATE UNIT TESTS APP -========================== #
# Create an executable named math_brain_app and build it using the main.cpp file
add_executable(math_brain_unit_testing
    src/unit_testing/main.cpp
    src/unit_testing/number.cpp
    src/unit_testing/parser.cpp
    src/unit_testing/expression.cpp
)

# Add GoogleTest as an external dependency
ExternalProject_Add(gtest
    GIT_REPOSITORY    https://github.com/google/googletest.git
    GIT_TAG           master
    SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
    BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
    INSTALL_COMMAND   "" # Do not run install command
)
# Get external project source and binary directories
ExternalProject_Get_Property(gtest source_dir binary_dir)
# Add google test to include paths
include_directories("${source_dir}/googletest/include")

# Link the math_brain_unit_testing executable with the math_brain library
target_link_libraries(math_brain_unit_testing
    pthread # Needed by google test
    ${binary_dir}/googlemock/gtest/libgtest.a # Google test
    math_brain
)
