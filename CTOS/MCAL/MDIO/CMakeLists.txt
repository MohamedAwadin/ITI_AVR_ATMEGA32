
add_library(MDIO STATIC src/MDIO.c src/MDIO_LCFG.c)


target_include_directories(MDIO PUBLIC inc ../../COMMON)
