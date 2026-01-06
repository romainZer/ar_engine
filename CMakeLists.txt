cmake_minimum_required(VERSION 4.1)
project(ar_engine)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

find_package(glfw3 REQUIRED)

add_executable(ar_engine main.cpp
        Interaction/Window/WindowCreatorStrategy.h
        Interaction/Window/Implementation/WindowsPlatformWindowMaker.cpp
        Interaction/Window/Implementation/WindowsPlatformWindowMaker.h
        Interaction/Window/Implementation/LinuxPlatformWindowMaker.cpp
        Interaction/Window/Implementation/LinuxPlatformWindowMaker.h
        Interaction/Window/WindowCreatorClient.cpp
        Interaction/Window/WindowCreatorClient.h
        Interaction/Window/Enums/PlatformEnum.h
        Interaction/Environment/Environment.cpp
        Interaction/Environment/Environment.h
        Interaction/Drawing/DrawerClient.cpp
        Interaction/Drawing/DrawerClient.h
        External/glad/src/glad.c)

target_include_directories(ar_engine PRIVATE
        ${OPENGL_INCLUDE_DIR}
        External/glad/include
)

target_link_libraries(ar_engine
        OpenGL::GL
        glfw
)