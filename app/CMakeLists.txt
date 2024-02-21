# Especifico dónde están los fuentes.
#
set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cc")

# Ubicación del ejecutable
add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})

# Link del ejecutable con las librerías
target_link_libraries( ${EXECUTABLE_NAME}
    PRIVATE
    ${LIBRARY_NAME}
    Boost::regex
    fmt::fmt
    spdlog::spdlog)


if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${EXECUTABLE_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        ${EXECUTABLE_NAME}
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${EXECUTABLE_NAME})
endif()
