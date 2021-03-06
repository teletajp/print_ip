set(TARGET_NAME "print_ip_test")
set(TARGET_SRC
print_ip_test.cpp
../src/print_ip.h
)
add_executable(${TARGET_NAME} ${TARGET_SRC})
set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-std=c++1z"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

if(WIN32)
    target_compile_options(${TARGET_NAME} PUBLIC "/MT$<$<CONFIG:Debug>:d>")
endif(WIN32)

target_link_libraries(${TARGET_NAME} PRIVATE GTest::GTest GTest::Main Threads::Threads)
target_include_directories(${TARGET_NAME} PRIVATE ../src)
add_test(${TARGET_NAME} ${TARGET_NAME})
set_tests_properties( ${TARGET_NAME} PROPERTIES WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
#add_custom_target(run_tests COMMAND "${CMAKE_CTEST_COMMAND} --build-and-test --test-command ../bin/${TARGET_NAME}")