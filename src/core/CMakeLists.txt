project(core)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} algo/algo.cpp)
add_library(sub::core ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}
)
