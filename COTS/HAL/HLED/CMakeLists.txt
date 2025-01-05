# Add the HLED library
add_library(HLED STATIC 
            src/HLED.c
            src/HLED_Config.c
)

# Include directories for the HLED library
target_include_directories(HLED PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MDIO/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MPORT/inc
)