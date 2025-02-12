find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB UNIT_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(UnitTests ${UNIT_TEST_SOURCES})
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)

target_link_libraries(UnitTests core)
target_link_libraries(UnitTests impl)

enable_testing()
add_test(NAME UnitTests COMMAND UnitTests)
