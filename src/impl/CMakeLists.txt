project(impl)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} caesar/caesar_algo.cpp playfair/playfair_algo.cpp)
add_library(sub::impl ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}
)
