cmake_minimum_required(VERSION 3.21)

project(AutoDecorator VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/AutoDecorator.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        src
)
