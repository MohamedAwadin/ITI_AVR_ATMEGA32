# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.16.3)

# Define the project name
project(TASK_TestTimer2_DRIVER )

# Set the compiler and flags for AVR
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_C_FLAGS "-mmcu=atmega32 -DF_CPU=8000000UL -Os")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega32")

# Include the MDIO driver
add_subdirectory(../../../COTS/MCAL/MDIO ${CMAKE_BINARY_DIR}/MDIO)

# Include the MPORT driver
add_subdirectory(../../../COTS/MCAL/MPORT ${CMAKE_BINARY_DIR}/MPORT)

add_subdirectory(../../../COTS/MCAL/MTIMER ${CMAKE_BINARY_DIR}/MTIMER)

# Include the MEXTINT driver
add_subdirectory(../../../COTS/MCAL/MEXTINT ${CMAKE_BINARY_DIR}/MEXTINT)



# Create the executable
add_executable(${PROJECT_NAME}.elf src/main.c)

# Link the MDIO and HLCD libraries
target_link_libraries(${PROJECT_NAME}.elf PUBLIC MTIMER MEXTINT MDIO MPORT)

# Include the flash script and configure flashing
include(../../../COTS/Cmake/flash.cmake)
convert_to_hex_and_flash(${PROJECT_NAME}.elf usbasp atmega32)