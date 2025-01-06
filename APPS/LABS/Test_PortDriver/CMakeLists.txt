cmake_minimum_required(VERSION 3.16.3)
project(Test_PortDriver)


set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_ASM_COMPILER avr-gcc)
set(CMAKE_C_FLAGS "-mmcu=atmega32 -DF_CPU=8000000UL -Os")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega32")



include_directories(
    ../../../COTS/COMMON        
    ../../../COTS/MCAL/MDIO/inc 
    ../../../COTS/MCAL/MPORT/inc 
)


add_subdirectory(../../../COTS/MCAL/MDIO ${CMAKE_BINARY_DIR}/MDIO)
add_subdirectory(../../../COTS/MCAL/MPORT ${CMAKE_BINARY_DIR}/MPORT)
add_executable(${PROJECT_NAME}.elf src/main.c)
target_link_libraries(${PROJECT_NAME}.elf MDIO MPORT)
include(../../../COTS/Cmake/flash.cmake)
convert_to_hex_and_flash(${PROJECT_NAME}.elf usbasp atmega32)
