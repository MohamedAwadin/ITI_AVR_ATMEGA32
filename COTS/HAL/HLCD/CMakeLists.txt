# Add the HLCD library
add_library(HLCD STATIC 
            src/HLCD.c
            src/HLCD_Config.c
)

# Include directories for the HLCD library
target_include_directories(HLCD PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MDIO/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MPORT/inc
)