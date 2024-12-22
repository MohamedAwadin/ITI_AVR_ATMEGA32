add_executable(TASK3 src/main.c)

# Link MDIO library
target_link_libraries(TASK3 MDIO)

# Include directories
target_include_directories(TASK3 PUBLIC ../../../../CTOS/COMMON ../../../../CTOS/MCAL/MDIO/inc)
