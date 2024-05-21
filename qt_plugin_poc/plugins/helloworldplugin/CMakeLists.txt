qt_add_plugin(helloworldplugin
    CLASS_NAME HelloWorldPlugin
    helloworldplugin.cpp helloworldplugin.h
    helloplugininterface.h
    helloworld.json
)

set_target_properties(helloworldplugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/helloworldplugin"
)

target_include_directories(helloworldplugin PRIVATE
    ../helloworldplugin
)

target_link_libraries(helloworldplugin PRIVATE
    Qt6::Core
)

install(TARGETS helloworldplugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

