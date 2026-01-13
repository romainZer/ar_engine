// ... existing code ...
#include <glad/glad.h>
#include "GLFW_WindowCreator.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>

#include "../../Environment/Environment.h"

GLFW_WindowCreator::GLFW_WindowCreator(IGraphicLoader &loader, IRenderer &renderer)
    : IWindowCreatorStrategy(loader, renderer) {
    this->loader = &loader;
    this->renderer = &renderer;
}

void GLFW_WindowCreator::createWindow(uint16_t x, uint16_t y) {
    bool success = true;

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        success = false;
    }

    if (success) {
        initConfig();

        GLFWwindow *window = createWindowAndDefineContext(
            Environment::getWidth(),
            Environment::getHeight(),
            Environment::getWindowTitle().c_str()
        );

        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        } else {
            if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
                std::cerr << "Failed to initialize GLAD" << std::endl;
                clearWindow(window);
                success = false;
            }

            if (success) {
                runMainLoop(window);
                clearWindow(window);
            }
        }
    }
}

void GLFW_WindowCreator::runMainLoop(GLFWwindow* window) const {
    const std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };

    const auto model = loader->loadToVAO(vertices);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        renderer->prepare();
        glClear(GL_COLOR_BUFFER_BIT);

        renderer->render(*model);

        glfwSwapBuffers(window);
    }
}

GLFWwindow *GLFW_WindowCreator::createWindowAndDefineContext(const uint16_t width, const uint16_t height,
                                                             const char *title) {
    GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (window) {
        glfwMakeContextCurrent(window);
    }

    return window;
}

void GLFW_WindowCreator::clearWindow(GLFWwindow *window) {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void GLFW_WindowCreator::initConfig() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}