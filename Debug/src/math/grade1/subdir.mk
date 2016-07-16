################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/math/grade1/Addition.cpp \
../src/math/grade1/Multiplication.cpp \
../src/math/grade1/NaturalNumber.cpp \
../src/math/grade1/Subtraction.cpp 

OBJS += \
./src/math/grade1/Addition.o \
./src/math/grade1/Multiplication.o \
./src/math/grade1/NaturalNumber.o \
./src/math/grade1/Subtraction.o 

CPP_DEPS += \
./src/math/grade1/Addition.d \
./src/math/grade1/Multiplication.d \
./src/math/grade1/NaturalNumber.d \
./src/math/grade1/Subtraction.d 


# Each subdirectory must supply rules for building sources it contributes
src/math/grade1/%.o: ../src/math/grade1/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


