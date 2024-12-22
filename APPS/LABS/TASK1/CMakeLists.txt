add_executable(TASK1 src/main.c)

# Link MDIO library
target_link_libraries(TASK1 MDIO)

# Include directories
target_include_directories(TASK1 PUBLIC ../../../../CTOS/COMMON ../../../../CTOS/MCAL/MDIO/inc)
