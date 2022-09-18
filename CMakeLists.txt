cmake_minimum_required(VERSION 3.23)
project(dsa C CXX)

# Disable in-source builds to prevent source tree corruption.
if (" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif ()

set(CMAKE_C_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(cmake/logc.cmake)

add_subdirectory(test)
include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(src source_files)

add_library(dsa ${source_files})
target_link_libraries(dsa logc)

#message("${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
