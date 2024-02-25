
cmake_minimum_required(VERSION 3.12)

project(SimpleGL)

file(GLOB SOURCES
    include/*.hpp
    include/*.cpp
    main.cpp
)

add_executable(SimpleGL ${SOURCES})

target_include_directories(SimpleGL PRIVATE dep/glm 
                                              dep/glfw/include
                                              dep/glew/include
)

target_link_directories(SimpleGL PRIVATE dep/glfw/lib-vc2022
                                           dep/glew/lib/Release/x64)

target_link_libraries(SimpleGL PRIVATE glfw3.lib glew32.lib opengl32.lib)

add_custom_command(TARGET SimpleGL POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/dep/glew/bin/Release/x64/glew32.dll" "${CMAKE_BINARY_DIR}/glew32.dll"
                   COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/shader" "${CMAKE_BINARY_DIR}/shader"
)