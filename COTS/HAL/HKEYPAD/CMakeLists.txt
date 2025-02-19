# Add the HKEYPAD library
add_library(HKEYPAD STATIC 
            src/HKEYPAD.c
            src/HKEYPAD_Config.c
)

# Include directories for the HKEYPAD library
target_include_directories(HKEYPAD PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MDIO/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MPORT/inc
)