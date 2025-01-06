# MDIO Library
add_library(MDIO STATIC
    src/MDIO.c
    src/MDIO_LCFG.c
)

# Include directories for MDIO
target_include_directories(MDIO PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
)