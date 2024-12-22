# MDIO driver library
add_library(MDIO STATIC src/MDIO.c)

# Include directories
target_include_directories(MDIO PUBLIC inc ../COMMON)
