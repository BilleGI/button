cmake_minimum_required(VERSION 3.22)

qt_add_executable(button main.cpp ${MY_INCLUDE_DIR}/button.h button.cpp ${CMAKE_SOURCE_DIR}/resources.qrc)

target_include_directories(button PRIVATE ${MY_INCLUDE_DIR})
