cmake_minimum_required(VERSION 4.1)

if (DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "Vcpkg toolchain file")
elseif (EXISTS "C:/Users/romai/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/romai/vcpkg/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "Vcpkg toolchain file")
endif ()

project(ar_engine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Dependencies
# -----------------------------
find_package(OpenGL REQUIRED)

# Sur Windows avec vcpkg, utilise CONFIG, sur Linux utilise MODULE
if (WIN32)
    find_package(glfw3 CONFIG REQUIRED)
else ()
    find_package(glfw3 REQUIRED)
endif ()

# -----------------------------
# Executable
# -----------------------------
add_executable(ar_engine
        main.cpp
        Interaction/Window/IWindowCreatorStrategy.h
        Interaction/Window/WindowCreatorClient.cpp
        Interaction/Window/WindowCreatorClient.h
        Interaction/Window/Enums/PlatformEnum.h
        Interaction/Window/Implementation/GLFW_WindowCreator.cpp
        Interaction/Window/Implementation/GLFW_WindowCreator.h
        Interaction/Environment/Environment.cpp
        Interaction/Environment/Environment.h
        External/glad/src/glad.c
        Interaction/Drawing/Enums/ActionEnum.h
        Interaction/Drawing/Models/RawModel.h
        Interaction/Drawing/Models/RawModel.cpp
        Interaction/Drawing/Loader/Implementation/OpenGL_Loader.cpp
        Interaction/Drawing/Loader/Implementation/OpenGL_Loader.h
        Interaction/Drawing/Renderer/Implementation/OpenGL_Renderer.cpp
        Interaction/Drawing/Renderer/Implementation/OpenGL_Renderer.h
        Interaction/Drawing/Loader/IGraphicLoader.h
        Interaction/Drawing/Renderer/IRenderer.h
)

# -----------------------------
# Includes
# -----------------------------
target_include_directories(ar_engine PRIVATE
        External/glad/include
)

# -----------------------------
# Linking
# -----------------------------
target_link_libraries(ar_engine PRIVATE
        OpenGL::GL
        glfw
)