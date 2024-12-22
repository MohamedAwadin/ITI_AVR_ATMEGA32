add_executable(TASK2 src/main.c)

# Link MDIO library
target_link_libraries(TASK2 MDIO)

# Include directories
target_include_directories(TASK2 PUBLIC ../../../../CTOS/COMMON ../../../../CTOS/MCAL/MDIO/inc)
