cmake_minimum_required(VERSION 3.10)
project(MAI-OOP-LABS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

FetchContent_MakeAvailable(googletest)

add_library(lab1_lib STATIC src/replace.cpp)
add_executable(lab_1_exe main.cpp)

target_link_libraries(lab_1_exe lab1_lib)

# Добавляем тесты
enable_testing()
add_executable(tests test/test01.cpp)
target_link_libraries(tests lab1_lib gtest_main)

add_test(NAME Lab1-Tests COMMAND tests)