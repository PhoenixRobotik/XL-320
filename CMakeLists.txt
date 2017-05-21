####################################################################
#   Project configuration
####################################################################
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project (Phoenix_XL-320)
set     (Phoenix_XL-320_VERSION_MAJOR 0)
set     (Phoenix_XL-320_VERSION_MINOR 1)

include(${GenericCmakeLists})

####################################################################
#   Source
####################################################################
## Déclaration de la librairie aux projets qui utilisent celui-ci
# Déclaration des sources de la librairie
add_library(${PROJECT_NAME}Lib STATIC
    xl_320.c
)
# Includes publics
target_include_directories(${PROJECT_NAME}Lib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(${PROJECT_NAME}Lib INTERFACE
    m
)

# Librairie à linker
export(TARGETS ${PROJECT_NAME}Lib FILE Librairie.cmake)

add_executable(${PROJECT_NAME}Tests
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
add_executable(main_binary ALIAS ${PROJECT_NAME}Tests)
target_link_libraries(${PROJECT_NAME}Tests
    ${PROJECT_NAME}Lib
    ${Toolchain_LFlags}
)
