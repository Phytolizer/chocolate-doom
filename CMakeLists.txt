cmake_minimum_required(VERSION 3.23)

project(chocolate-doom LANGUAGES CXX VERSION 0.1.0 DESCRIPTION "Doom in C++")

find_package(fmt REQUIRED)
find_package(SDL2 REQUIRED)

add_executable(
    chocolate-doom
    "src/miscellaneous/argv.cpp"
    "src/system/main.cpp"
    "src/main.cpp"
    "src/system.cpp"
    "src/stat.cpp"
    "src/system/video.cpp"
    "src/dehacked/strings.cpp"
    "src/miscellaneous/config.cpp"
)
target_include_directories(chocolate-doom PUBLIC include "${PROJECT_BINARY_DIR}/include")
target_link_libraries(chocolate-doom fmt::fmt SDL2::SDL2main SDL2::SDL2-static)
target_compile_features(chocolate-doom PRIVATE cxx_std_20)
set(PROJECT_NAME_PRETTY "Chocolate Doom")
set(PROJECT_NAME_SIMPLE "chocolate-doom")

configure_file(cmake/config.hpp.cin include/config.hpp)
