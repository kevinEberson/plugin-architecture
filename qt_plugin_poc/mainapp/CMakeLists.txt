qt_add_executable(mainapp
    main.cpp
)

set_target_properties(mainapp PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(mainapp PRIVATE
    Qt6::Core
)

set(QT6_IS_SHARED_LIBS_BUILD TRUE)

if(QT6_IS_SHARED_LIBS_BUILD)
    # Build the shared plugin too when building this example target.
    FOREACH(plugin ${PLUGINS})
        add_dependencies(mainapp "${PLUGINS_DIR}/${plugin}")
    ENDFOREACH()
else()
    # Link the echoplugin if Qt is built statically.
    FOREACH(plugin ${PLUGINS})
        target_link_libraries(mainapp PRIVATE "${PLUGINS_DIR}/${plugin}")
    ENDFOREACH()
endif()

install(TARGETS mainapp
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
