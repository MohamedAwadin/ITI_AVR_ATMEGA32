cmake_minimum_required(VERSION 3.16.3)
project(ATmega32Drivers)

# Enable languages
enable_language(C CXX ASM)
include_directories(CTOS/COMMON)
# Add subdirectories for drivers and tasks
add_subdirectory(CTOS/MCAL/MDIO)
add_subdirectory(APPS/LABS/TASK1)
add_subdirectory(APPS/LABS/TASK2)
add_subdirectory(APPS/LABS/TASK3)
