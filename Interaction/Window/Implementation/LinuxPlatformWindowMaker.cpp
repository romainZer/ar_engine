//
// Created by romainz on 06/01/2026.
//

#include "LinuxPlatformWindowMaker.h"
#include <GLFW/glfw3.h>
#include <iostream>

#include "../../Environment/Environment.h"

void LinuxPlatformWindowMaker::createWindow(const uint16_t x, const uint16_t y) {
    if (!glfwInit()) {
        std::cerr << "Erreur lors de l'initialisation de GLFW" << std::endl;
        return;
    }

    initConfig();

    // Window creation
    GLFWwindow *window = createWindowAndDefineContext(
        Environment::getWidth(),
        Environment::getHeight(),
        Environment::getWindowTitle().c_str()
    );

    if (!window) {
        glfwTerminate();
        return;
    }

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); //Events manager
        glfwSwapBuffers(window); //Swap buffers
        glClear(GL_COLOR_BUFFER_BIT); //Clear screen
    }

    clearWindow(window);
}

GLFWwindow *LinuxPlatformWindowMaker::createWindowAndDefineContext(const uint16_t width, const uint16_t height,
                                                                   const char *title) {
    GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "Error while creating the window." << std::endl;
        return nullptr;
    }

    // Defines the current OpenGL context
    glfwMakeContextCurrent(window);

    // Defines the background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    return window;
}

void LinuxPlatformWindowMaker::clearWindow(GLFWwindow *window) {
    //Window cleaning
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void LinuxPlatformWindowMaker::initConfig() {
    // Configuration de GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
