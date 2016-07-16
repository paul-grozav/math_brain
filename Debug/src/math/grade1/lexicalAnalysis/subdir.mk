################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/math/grade1/lexicalAnalysis/Expression.cpp \
../src/math/grade1/lexicalAnalysis/Token.cpp 

OBJS += \
./src/math/grade1/lexicalAnalysis/Expression.o \
./src/math/grade1/lexicalAnalysis/Token.o 

CPP_DEPS += \
./src/math/grade1/lexicalAnalysis/Expression.d \
./src/math/grade1/lexicalAnalysis/Token.d 


# Each subdirectory must supply rules for building sources it contributes
src/math/grade1/lexicalAnalysis/%.o: ../src/math/grade1/lexicalAnalysis/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


