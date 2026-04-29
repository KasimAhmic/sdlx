cmake_minimum_required(VERSION 4.0)
project(sdlcpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/window.cpp
        src/window.hpp
        src/error.cpp
        src/error.hpp
        src/window_flag.hpp
        src/display_mode.cpp
        src/display_mode.hpp
        src/progress_state.hpp
        src/surface.cpp
        src/surface.hpp
        src/pixel_format.hpp
        src/resource_ref.hpp
        src/entry.hpp
        src/renderer.cpp
        src/renderer.hpp
        src/init.cpp
        src/init.hpp
        src/init_flag.hpp
        src/util.hpp
        src/internal/enum.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
