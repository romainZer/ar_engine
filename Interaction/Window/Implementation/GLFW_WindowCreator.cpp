//
// Created by romainz on 06/01/2026.
//

#include "GLFW_WindowCreator.h"
#include <iostream>
#include <GLFW/glfw3.h>

#include "../../Environment/Environment.h"

GLFW_WindowCreator::GLFW_WindowCreator(IGraphicLoader &loader, IRenderer &renderer) : IWindowCreatorStrategy(
    loader, renderer) {
    this->loader = std::make_unique<IGraphicLoader>(loader);
}

void GLFW_WindowCreator::createWindow(uint16_t x, uint16_t y) {
    if (!glfwInit()) {
        std::cerr << "Erreur lors de l'initialisation de GLFW" << std::endl;
        return;
    }

    initConfig();

    GLFWwindow *window = createWindowAndDefineContext(
        Environment::getWidth(),
        Environment::getHeight(),
        Environment::getWindowTitle().c_str()
    );

    if (!window) {
        glfwTerminate();
        return;
    }

    drawer = std::make_unique<DrawerClient>();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        loader->loadToVAO();

        glfwSwapBuffers(window);
    }

    clearWindow(window);
}


GLFWwindow *GLFW_WindowCreator::createWindowAndDefineContext(const uint16_t width, const uint16_t height,
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

void GLFW_WindowCreator::clearWindow(GLFWwindow *window) {
    //Window cleaning
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void GLFW_WindowCreator::initConfig() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
}
