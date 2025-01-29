project(core)

add_library(${PROJECT_NAME} algo/algo.cpp)
add_library(sub::core ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/algo
    PUBLIC ${PROJECT_SOURCE_DIR}/decoder
    PUBLIC ${PROJECT_SOURCE_DIR}/encoder
    PUBLIC ${PROJECT_SOURCE_DIR}/salt
)
