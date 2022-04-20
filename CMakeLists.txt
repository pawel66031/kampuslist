cmake_minimum_required(VERSION 3.0.0)
project(kampuslist VERSION 0.1.0)

include(CTest)
enable_testing()

# target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(${PROJECT_NAME} main.cpp Timer.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME}
    curl
    jsoncpp
)