cmake_minimum_required(VERSION 3.31)
project(Blackjack)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_library(dealer src/dealer.cpp include/dealer.hpp)

add_executable(Blackjack src/main.cpp)

target_link_libraries(Blackjack dealer)