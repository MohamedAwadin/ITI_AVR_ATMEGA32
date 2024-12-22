cmake_minimum_required(VERSION 3.16.3)
project(Task3)


set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_ASM_COMPILER avr-gcc)
set(CMAKE_C_FLAGS "-mmcu=atmega32 -DF_CPU=8000000UL -Os")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega32")



include_directories(
    ../../../CTOS/COMMON        
    ../../../CTOS/MCAL/MDIO/inc 
)


add_subdirectory(../../../CTOS/MCAL/MDIO ${CMAKE_BINARY_DIR}/MDIO)
add_executable(${PROJECT_NAME}.elf src/main.c)
target_link_libraries(${PROJECT_NAME}.elf MDIO)
include(../../../CTOS/Cmake/flash.cmake)
convert_to_hex_and_flash(${PROJECT_NAME}.elf usbasp atmega32)
