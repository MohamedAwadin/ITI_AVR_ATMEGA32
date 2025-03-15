# TIMER Library
add_library(MTIMER STATIC
    src/MTIMER.c
)

# Include directories for TIMER
target_include_directories(MTIMER PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/../MEXTINT/inc
    
)