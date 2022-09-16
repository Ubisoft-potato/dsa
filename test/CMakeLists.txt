project(DataStructure_C_Test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/include)

enable_testing()

add_executable(
        generic_list_test
        generic_list_test.cc)

target_link_libraries(
        generic_list_test
        GTest::gtest_main
        data_struct
)

include(GoogleTest)
gtest_discover_tests(generic_list_test)