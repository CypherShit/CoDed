project(core)

add_library(${PROJECT_NAME} algo/algo.cpp)
add_library(sub::core ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}
)
