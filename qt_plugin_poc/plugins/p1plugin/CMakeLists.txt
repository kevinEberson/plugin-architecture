qt_add_plugin(p1plugin
    CLASS_NAME P1Plugin
    p1plugin.cpp p1plugin.h
    plugininterface.h
    plugininterface.json
)

set_target_properties(p1plugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/plugins"
)

target_include_directories(p1plugin PRIVATE
    ../p1plugin
)

target_link_libraries(p1plugin PRIVATE
    Qt6::Core
)

install(TARGETS p1plugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

