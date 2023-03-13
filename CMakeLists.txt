cmake_minimum_required(VERSION 3.1)
project(Reflective VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES 
    "src/*.cpp", "test/*.cpp"
)

add_library(${PROJECT_NAME} ${SOURCES} 
            "src/"
            )


target_include_directories(${PROJECT_NAME} 
            PUBLIC
            "${PROJECT_SOURCE_DIR}/src"
            "${PROJECT_SOURCE_DIR}/src/include/"
            "${PROJECT_SOURCE_DIR}/test/"
            )

add_executable(main ${SOURCES})

