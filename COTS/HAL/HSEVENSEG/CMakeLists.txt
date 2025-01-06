# HSEVENSEG Library
add_library(HSEVENSEG STATIC
    src/HSEVENSEG.c
    src/HSEVENSEG_Config.c
)

# Include directories for HSEVENSEG
target_include_directories(HSEVENSEG PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MDIO/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MCAL/MPORT/inc
)