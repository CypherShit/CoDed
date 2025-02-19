find_package(GTest REQUIRED) 
find_package(benchmark REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB PERF_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(PerformanceTests ${PERF_TEST_SOURCES})
target_link_libraries(PerformanceTests ${GTEST_LIBRARIES} pthread benchmark::benchmark)

target_link_libraries(PerformanceTests core)
target_link_libraries(PerformanceTests impl)

enable_testing()
add_test(NAME PerformanceTests COMMAND PerformanceTests)
