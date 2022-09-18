include(FetchContent)

set(logc_repo https://github.com/rxi/log.c)
set(logc_tag f9ea34994bd58ed342d2245cd4110bb5c6790153)

FetchContent_Declare(
        logc
        GIT_REPOSITORY ${logc_repo}
        GIT_TAG ${logc_tag}
)

FetchContent_MakeAvailable(logc)

set(logc_source_dir ${CMAKE_BINARY_DIR}/_deps/logc-src/src)
include_directories(${logc_source_dir})
aux_source_directory(${logc_source_dir} logc_sources)
add_library(logc ${logc_sources})