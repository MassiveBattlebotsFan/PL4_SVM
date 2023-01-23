cmake_minimum_required(VERSION 3.20)

project(PL4_SVM VERSION 0.0.3)
set(PROJECT_VERSION_TWEAK \"proto\") #used as build branch

option(DEBUG "Build with debug messages" off)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(PROJECT_SOURCE_DIR "src/")
set(PROJECT_HEADER_DIR "${PROJECT_SOURCE_DIR}headers/")

configure_file(${PROJECT_HEADER_DIR}PL4_SVM_Config.hpp.in PL4_SVM_Config.hpp)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}*.cpp")

if(${DEBUG})
message("Debug build")
endif()

add_executable(pl4_svm_cpp ${SOURCES})

target_include_directories(pl4_svm_cpp PUBLIC "${PROJECT_BINARY_DIR}")