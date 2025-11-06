cmake_minimum_required(VERSION 3.14)
project(calc LANGUAGES CXX)

add_library(calc STATIC
    Calculator.cpp
    LimitedCalculator.cpp
)

target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(calc PUBLIC cxx_std_17)

option(CALC_ENABLE_TESTS "Build calc unit tests" ON)

if(CALC_ENABLE_TESTS)
    enable_testing()
    include(FetchContent)

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)

    add_executable(calc_tests
        tests/CalculatorTests.cpp
    )

    target_link_libraries(calc_tests PRIVATE calc GTest::gtest_main)

    if(MSVC)
        target_compile_options(calc PRIVATE /W4 /WX-)
        target_compile_options(calc_tests PRIVATE /W4 /WX-)
    else()
        target_compile_options(calc PRIVATE -Wall -Wextra -Wpedantic)
        target_compile_options(calc_tests PRIVATE -Wall -Wextra -Wpedantic)
    endif()

    include(GoogleTest)
    gtest_discover_tests(calc_tests)
endif()

