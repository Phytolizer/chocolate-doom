cmake_minimum_required(VERSION 3.23)

project(chocolate-doom LANGUAGES CXX VERSION 0.1.0 DESCRIPTION "Doom in C++")

find_package(fmt REQUIRED)

add_executable(
    chocolate-doom
    "src/miscellaneous/argv.cpp"
    "src/system/main.cpp"
)
target_include_directories(chocolate-doom PUBLIC include)
target_link_libraries(chocolate-doom fmt::fmt)
target_compile_features(chocolate-doom PRIVATE cxx_std_20)
set(PROJECT_NAME_PRETTY "Chocolate Doom")

configure_file(cmake/config.hpp.cin include/config.hpp)
