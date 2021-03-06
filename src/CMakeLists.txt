configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)

set(BIN_SRC 
main.cpp
print_ip.h
)

add_executable(${PROJECT_NAME} ${BIN_SRC})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-std=c++1z"
    #COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
    #COMPILE_OPTIONS "$<IF:$<CXX_COMPILER_ID:MSVC>,/we /Wall /WX, -Wpedantic;-Wall;-Wextra>"
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

if(UNIX)
    set(CPACK_GENERATOR DEB)
    set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
    set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
    set(CPACK_PACKAGE_CONTACT teletajp@yandex.ru)
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
include(CPack)
endif()