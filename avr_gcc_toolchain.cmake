set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)

# Set target MCU and frequency
set(MCU atmega32)
set(F_CPU 8000000UL)

# Flags for avr-gcc
set(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os")
set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

# Output file format (Intel HEX)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_OBJCOPY_FLAGS "-O ihex")

# AVRDUDE upload tool
set(AVRDUDE avrdude)
set(AVRDUDE_PROGRAMMER usbasp)
set(AVRDUDE_PORT usb) # Replace if using different programmer
set(AVRDUDE_FLAGS "-c ${AVRDUDE_PROGRAMMER} -p ${MCU} -P ${AVRDUDE_PORT}")
