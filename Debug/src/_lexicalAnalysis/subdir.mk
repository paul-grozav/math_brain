################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/_lexicalAnalysis/Expression.cpp 

OBJS += \
./src/_lexicalAnalysis/Expression.o 

CPP_DEPS += \
./src/_lexicalAnalysis/Expression.d 


# Each subdirectory must supply rules for building sources it contributes
src/_lexicalAnalysis/%.o: ../src/_lexicalAnalysis/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


