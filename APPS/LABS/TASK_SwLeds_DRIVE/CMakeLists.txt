# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.16.3)

# Define the project name
project(TASK_SwLeds_DRIVE)

# Set the compiler and flags for AVR
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_C_FLAGS "-mmcu=atmega32 -DF_CPU=8000000UL -Os")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega32")

# Include the MDIO driver
add_subdirectory(../../../COTS/MCAL/MDIO ${CMAKE_BINARY_DIR}/MDIO)

# Include the HLED driver
add_subdirectory(../../../COTS/HAL/HLED ${CMAKE_BINARY_DIR}/HLED)

# Include the HSWITCH driver
add_subdirectory(../../../COTS/HAL/HSWITCH ${CMAKE_BINARY_DIR}/HSWITCH)

# Create the executable
add_executable(${PROJECT_NAME}.elf src/main.c)

# Link the MDIO and HLED libraries
target_link_libraries(${PROJECT_NAME}.elf PUBLIC  HSWITCH HLED MDIO)

# Include the flash script and configure flashing
include(../../../COTS/Cmake/flash.cmake)
convert_to_hex_and_flash(${PROJECT_NAME}.elf usbasp atmega32)