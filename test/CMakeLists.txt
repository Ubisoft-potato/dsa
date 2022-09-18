project(DataStructure_C_Test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
include(FetchContent)

set(gtest_repo https://github.com/google/googletest.git)
set(gtest_tag release-1.12.1)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY ${gtest_repo}
        GIT_TAG ${gtest_tag}
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
        dsa
)

include(GoogleTest)
gtest_discover_tests(generic_list_test)