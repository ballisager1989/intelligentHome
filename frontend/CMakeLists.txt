cmake_minimum_required(VERSION 2.8)

project(intelligentHome)


include(../configuration/qtconfig.cmake)

include_directories(
    src/
    )
file(GLOB sources src/* )
file(GLOB main main/* )

add_executable(
    ${PROJECT_NAME}App
    ${main}
    ${sources}

)

target_link_libraries(${PROJECT_NAME}App
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    )
