cmake_minimum_required(VERSION 3.23)

project(MDBundleTest)
set(TARGET_NAME "MDBundleTest")
set(CMAKE_CXX_STANDARD 17)

LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/gtestsuit/cmake")



include(FetchContent)
include(CodeCoverage)
include(CMakePrintHelpers)

append_coverage_compiler_flags()

# This statement downloads google test framework. Can be by just the include in case google framework is downloaded manually
FetchContent_Declare(
        googletest
        #URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# enable UNIT_TEST compiler option
add_definitions(-DUNIT_TEST)

add_executable(
    ${TARGET_NAME}
    src/main.cpp 
    src/header.cpp
)

include(GoogleTest)
add_subdirectory(gtestsuit/tests_gtest)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        .
        ./gtestsuit/tests_gtest
        include
)

target_link_libraries(
        ${TARGET_NAME}
        PRIVATE
        gtest_main
        gmock
        
)



# /workdir/jsoncpp/build/src/lib_json/libjsoncpp.so
# /workdir/mosquitto/build/lib/libmosquitto.so

# This statement automatically detects all the tests added to the build.
gtest_discover_tests(${TARGET_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        XML_OUTPUT_DIR ${CMAKE_BINARY_DIR}/test_output
        )


# setup for html report
setup_target_for_coverage_gcovr_html(
        NAME ${TARGET_NAME}_coverage
        EXECUTABLE ${PROJECT_TEST_NAME}
        EXCLUDE "${CMAKE_BINARY_DIR}/*" "gtestsuit/tests_gtest/*"
        BASE_DIRECTORY "./"
)

# setup for xml report (used by Jenkins)
setup_target_for_coverage_gcovr_xml(
        NAME ${TARGET_NAME}_coverage_xml
        EXECUTABLE ${PROJECT_TEST_NAME}
        EXCLUDE "${CMAKE_BINARY_DIR}/*" "gtestsuit/tests_gtest/*"
        BASE_DIRECTORY "./"
)
