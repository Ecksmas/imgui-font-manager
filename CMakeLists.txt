cmake_minimum_required(VERSION 3.16)
project(imgui-font-manager)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IMGUI_SRC
    thirdParty/imgui/imgui.cpp
    thirdParty/imgui/imgui_draw.cpp
    thirdParty/imgui/imgui_tables.cpp
    thirdParty/imgui/imgui_widgets.cpp
)

# Add ImGui backend files
set(IMGUI_BACKENDS
    thirdParty/imgui/backends/imgui_impl_glfw.cpp
    thirdParty/imgui/backends/imgui_impl_opengl3.cpp
)

add_executable(${PROJECT_NAME}
    src/fontManager.cpp
    ${IMGUI_SRC}
    ${IMGUI_BACKENDS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

if(WIN32)
    target_link_libraries(${PROJECT_NAME}
        OpenGL:GL
        glfw
    )
endif()