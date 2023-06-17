cmake_minimum_required(VERSION 3.0.0)
project(desomi VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# see the preprocess result and save it to a file
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")

# add_subdirectory(${PROJECT_SOURCE_DIR}/desomi)
add_subdirectory(${PROJECT_SOURCE_DIR}/domi)

add_executable(desomi_playground main.cpp)
# target_link_libraries(desomi_playground desomi_core)



