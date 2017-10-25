cmake_minimum_required(VERSION 2.8)

project(core)


file(GLOB sources src/* )

add_library(
${PROJECT_NAME}
${sources}
)
