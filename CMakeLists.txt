cmake_minimum_required(VERSION 3.0.0)
project(wrapper-for-sdl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

include_directories(./Core)
include_directories(./Characters)

aux_source_directory(./Core/Character CHARACTER)
aux_source_directory(./Core/Events EVENTS)
aux_source_directory(./Core/Resource RESOURCE)
aux_source_directory(./Core/Widget WIDGET)
aux_source_directory(./Init INIT)

aux_source_directory(./Characters/ CHARS)

link_libraries(SDL2 SDL2_image)

add_executable(wrapper-for-sdl main.cpp ${CHARACTER} ${EVENTS} ${RESOURCE} ${WIDGET} ${CHARS} ${INIT})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


