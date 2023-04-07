cmake_minimum_required(VERSION 3.0.0)
project(desomi VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/desomi)

aux_source_directory(${PROJECT_SOURCE_DIR}/desomi/core/src CORE_SRC)

link_libraries(SDL2 SDL2_image)

add_executable(desomi_playground main.cpp ${CORE_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


