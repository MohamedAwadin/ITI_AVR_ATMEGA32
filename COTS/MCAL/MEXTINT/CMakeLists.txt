# MEXTINT Library
add_library(MEXTINT STATIC
    src/MEXTINT.c
)

# Include directories for MEXTINT
target_include_directories(MEXTINT PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
)