################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/math/grade4/Addition.cpp \
../src/math/grade4/Exception.cpp \
../src/math/grade4/Multiplication.cpp \
../src/math/grade4/NaturalNumber.cpp \
../src/math/grade4/Subtraction.cpp 

OBJS += \
./src/math/grade4/Addition.o \
./src/math/grade4/Exception.o \
./src/math/grade4/Multiplication.o \
./src/math/grade4/NaturalNumber.o \
./src/math/grade4/Subtraction.o 

CPP_DEPS += \
./src/math/grade4/Addition.d \
./src/math/grade4/Exception.d \
./src/math/grade4/Multiplication.d \
./src/math/grade4/NaturalNumber.d \
./src/math/grade4/Subtraction.d 


# Each subdirectory must supply rules for building sources it contributes
src/math/grade4/%.o: ../src/math/grade4/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


