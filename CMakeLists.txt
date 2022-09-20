cmake_minimum_required(VERSION 3.0.0)
project(kampuslist VERSION 0.1.0)

include(CTest)
enable_testing()

# target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

#   Needed for wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add_executable(myapp myapp.cpp)
# target_link_libraries(myapp ${wxWidgets_LIBRARIES})

add_executable(${PROJECT_NAME} 
    main.cpp 
    Timer.cpp 
    src/ArgumentsHandler.cpp
    src/PrintSongList.cpp
    src/gui/Window.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME}
    ${wxWidgets_LIBRARIES}
    curl
    jsoncpp
)