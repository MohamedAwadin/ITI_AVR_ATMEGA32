# Add the HSwitch library
add_library(HSWITCH STATIC
    src/HSWITCH.c
    src/HSWITCH_Config.c
)

# Include directories for HSwitch
target_include_directories(HSWITCH PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MDIO/inc
)