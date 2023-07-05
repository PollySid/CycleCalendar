# Standard routine
cmake_minimum_required(VERSION 3.16)
project(CycleCalendar)

# Use AUI.Boot
file(
        DOWNLOAD
        https://raw.githubusercontent.com/aui-framework/aui/develop/aui.boot.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/aui.boot.cmake)
include(${CMAKE_CURRENT_BINARY_DIR}/aui.boot.cmake)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)


# import AUI
auib_import(aui https://github.com/aui-framework/aui
        COMPONENTS core views
        VERSION develop)

add_executable(MyTestik ${SRCS_TESTS} src/Cycle.cpp)

# Create the executable. This function automatically links all sources from the src/ folder, creates CMake target and
# places the resulting executable to bin/ folder.
aui_executable(CycleCalendar)

# Link required libs
aui_link(CycleCalendar PRIVATE aui::core aui::views)


target_link_libraries(CycleCalendar PRIVATE nlohmann_json::nlohmann_json aui::views)
target_link_libraries(MyTestik PRIVATE gtest gtest_main)
target_include_directories(MyTestik PRIVATE src)

