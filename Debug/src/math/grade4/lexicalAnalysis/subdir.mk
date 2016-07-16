################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/math/grade4/lexicalAnalysis/Expression.cpp 

OBJS += \
./src/math/grade4/lexicalAnalysis/Expression.o 

CPP_DEPS += \
./src/math/grade4/lexicalAnalysis/Expression.d 


# Each subdirectory must supply rules for building sources it contributes
src/math/grade4/lexicalAnalysis/%.o: ../src/math/grade4/lexicalAnalysis/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


