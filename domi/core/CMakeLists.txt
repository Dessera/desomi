file(GLOB_RECURSE CORE_SRC src/*.cpp)

add_library(domi_core SHARED ${CORE_SRC})
target_include_directories(domi_core PUBLIC include)
