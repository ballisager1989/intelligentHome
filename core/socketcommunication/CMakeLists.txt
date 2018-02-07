cmake_minimum_required(VERSION 2.8)

project(socketcommunication)

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
    Qt5::Network
    )
