cmake_minimum_required(VERSION 3.16)
project(qtplugintest LANGUAGES CXX)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build")

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

# Add base directories
add_subdirectory(plugins)
add_subdirectory(mainapp)

# Set the directory where all plugins will be placed
set(PLUGINS_DIR "${CMAKE_SOURCE_DIR}/plugins")

# Get the name of all plugins
SUBDIRLIST(PLUGINS ${PLUGINS_DIR})

FOREACH(plugin ${PLUGINS})
    add_subdirectory("${PLUGINS_DIR}/${plugin}")
ENDFOREACH()
