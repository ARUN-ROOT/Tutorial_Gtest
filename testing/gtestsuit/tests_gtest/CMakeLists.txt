cmake_minimum_required(VERSION 3.14)

project(test_gtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

target_sources(${TARGET_NAME}
    PRIVATE
    #headertest.cpp
)

target_include_directories(
    ${TARGET_NAME}
    PUBLIC
    .
)

