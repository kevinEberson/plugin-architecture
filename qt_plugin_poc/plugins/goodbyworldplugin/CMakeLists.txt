qt_add_plugin(goodbyworldplugin
    CLASS_NAME GoodbyWorldPlugin
    goodbyworldplugin.cpp goodbyworldplugin.h
    goodbyplugininterface.h
    goodbyworld.json
)

set_target_properties(goodbyworldplugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/goodbyworldplugin"
)

target_include_directories(goodbyworldplugin PRIVATE
    ../goodbyworldplugin
)

target_link_libraries(goodbyworldplugin PRIVATE
    Qt6::Core
)

install(TARGETS goodbyworldplugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

