cmake_minimum_required(VERSION 3.0.0)
project(desomi VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# see the preprocess result and save it to a file
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")

include(CTest)
enable_testing()

# include_directories(${PROJECT_SOURCE_DIR}/desomi)
# aux_source_directory(${PROJECT_SOURCE_DIR}/desomi/core/src CORE_SRC)
# aux_source_directory(${PROJECT_SOURCE_DIR}/desomi/core/renderer/src RENDERER_SRC)
# aux_source_directory(${PROJECT_SOURCE_DIR}/desomi/core/node/src NODE_SRC)

add_subdirectory(${PROJECT_SOURCE_DIR}/desomi)

add_executable(desomi_playground main.cpp)
target_link_libraries(desomi_playground desomi_core)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


