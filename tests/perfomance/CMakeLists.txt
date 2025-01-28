find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB PERF_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(PerformanceTests ${PERF_TEST_SOURCES})
target_link_libraries(PerformanceTests ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME PerformanceTests COMMAND PerformanceTests)