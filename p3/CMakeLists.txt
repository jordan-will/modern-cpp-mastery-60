cmake_minimum_required(VERSION 3.20)

project(demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(demo
    src/TelemetryCollector.cpp
    src/TelemetryReading.cpp
    src/utils.cpp
    src/main.cpp
)

target_include_directories(demo PRIVATE
   "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(demo PRIVATE
      -Wall
      -Wextra
      -Wpedantic
      -Wconversion
      -Wsign-conversion 
    )
endif()
