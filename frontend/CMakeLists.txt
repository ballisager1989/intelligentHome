cmake_minimum_required(VERSION 2.8)

project(intelligentHome)


include(../configuration/qtconfig.cmake)

include_directories(
    src/
    )
file(GLOB sources src/* )
file(GLOB main main/* )
file(GLOB res resources/*.qrc )

#qt5_add_resources(RESOURCE_ADDED resources/intelligenthome.qrc)

add_library(
    ${PROJECT_NAME}
    ${sources}
)

add_executable(
    ${PROJECT_NAME}App
    ${main}
    ${res}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    )


target_link_libraries(${PROJECT_NAME}App
    ${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    )
