################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Actor.cpp \
../Controller.cpp \
../OnOff.cpp \
../Phenomenon.cpp \
../Proportional.cpp \
../Pulsed.cpp \
../Random.cpp \
../Runner.cpp \
../Server.cpp \
../Sinusoidal.cpp \
../State.cpp \
../Threshold.cpp \
../XMLParseable.cpp \
../main.cpp \
../tinyxml2.cpp 

OBJS += \
./Actor.o \
./Controller.o \
./OnOff.o \
./Phenomenon.o \
./Proportional.o \
./Pulsed.o \
./Random.o \
./Runner.o \
./Server.o \
./Sinusoidal.o \
./State.o \
./Threshold.o \
./XMLParseable.o \
./main.o \
./tinyxml2.o 

CPP_DEPS += \
./Actor.d \
./Controller.d \
./OnOff.d \
./Phenomenon.d \
./Proportional.d \
./Pulsed.d \
./Random.d \
./Runner.d \
./Server.d \
./Sinusoidal.d \
./State.d \
./Threshold.d \
./XMLParseable.d \
./main.d \
./tinyxml2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


