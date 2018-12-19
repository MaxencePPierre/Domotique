################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Actor.cpp \
../src/Controller.cpp \
../src/OnOff.cpp \
../src/Phenomenon.cpp \
../src/Proportional.cpp \
../src/Pulsed.cpp \
../src/Random.cpp \
../src/Runner.cpp \
../src/Server.cpp \
../src/Sinusoidal.cpp \
../src/State.cpp \
../src/Threshold.cpp \
../src/XMLParseable.cpp \
../src/main.cpp \
../src/tinyxml2.cpp 

OBJS += \
./src/Actor.o \
./src/Controller.o \
./src/OnOff.o \
./src/Phenomenon.o \
./src/Proportional.o \
./src/Pulsed.o \
./src/Random.o \
./src/Runner.o \
./src/Server.o \
./src/Sinusoidal.o \
./src/State.o \
./src/Threshold.o \
./src/XMLParseable.o \
./src/main.o \
./src/tinyxml2.o 

CPP_DEPS += \
./src/Actor.d \
./src/Controller.d \
./src/OnOff.d \
./src/Phenomenon.d \
./src/Proportional.d \
./src/Pulsed.d \
./src/Random.d \
./src/Runner.d \
./src/Server.d \
./src/Sinusoidal.d \
./src/State.d \
./src/Threshold.d \
./src/XMLParseable.d \
./src/main.d \
./src/tinyxml2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


