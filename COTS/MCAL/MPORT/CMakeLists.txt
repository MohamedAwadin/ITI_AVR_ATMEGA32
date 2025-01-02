

add_library(MPORT STATIC
    src/MPORT.c
    src/MPORT_LCFG.c
)


target_include_directories(MPORT PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../COMMON
)




