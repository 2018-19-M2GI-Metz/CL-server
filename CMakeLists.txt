cmake_minimum_required(VERSION 3.0.0)
project(server VERSION 0.1.0)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

SET(SOURCES
    src/native/CppToJaveConverter.cpp
    src/native/testjni.cpp)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/native/*.cpp")

add_subdirectory(core/)
add_library(server SHARED ${SOURCES})

find_package(JNI)

if (JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
    target_link_libraries (server ${JNI_LIBRARIES})
endif()

target_link_libraries(server core)