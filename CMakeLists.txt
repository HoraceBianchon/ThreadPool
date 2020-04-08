cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME_STR "ThreadPool")
project(${PROJECT_NAME_STR})


add_library(${PROJECT_NAME_STR} INTERFACE)

target_include_directories(
    ${PROJECT_NAME_STR}
    INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/>
    $<INSTALL_INTERFACE:${PROJECT_SOURCE_DIR}/>
)
target_sources(
    ${PROJECT_NAME_STR} INTERFACE ${PROJECT_SOURCE_DIR}/ThreadPool.cpp
)

