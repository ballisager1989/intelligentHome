cmake_minimum_required(VERSION 2.8)

project(networkdiscovery)

set(ROOT ../..)
set(CONFIG ${ROOT}/configuration)

include(${CONFIG}/qtconfig.cmake)

include_directories(
    src/
    inc/
     ${ROOT}/core/
    )

file(GLOB sources src/*.cpp src/*.hpp)
file(GLOB includes inc/*.hpp inc/*.h )


add_library(
    ${PROJECT_NAME}
    ${sources}
    ${includes}
)

target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Core
    pthread
    )

add_executable(
    ${PROJECT_NAME}_tool
    example/networkdiscovery_tool.cpp
)

add_executable(
    ${PROJECT_NAME}_example
    example/networkdiscovery_example.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_tool
    ${PROJECT_NAME}
    Qt5::Core
    )

target_link_libraries(
    ${PROJECT_NAME}_example
    ${PROJECT_NAME}
    Qt5::Core
    )
