#include "WindowCreatorClient.h"

#include <iostream>
#include <ostream>

#include "../Drawing/Loader/Implementation/OpenGL_Loader.h"
#include "../Drawing/Renderer/Implementation/OpenGL_Renderer.h"
#include "../Environment/Environment.h"
#include "Implementation/GLFW_WindowCreator.h"

void WindowCreatorClient::create(const PlatformEnum platform) {
    switch (platform) {
#ifdef _WIN32
        case PlatformEnum::WINDOWS:
            loader = std::make_unique<OpenGL_Loader>();
            renderer = std::make_unique<OpenGL_Renderer>();
            strategy = std::make_unique<GLFW_WindowCreator>(*loader, *renderer);
            break;
#endif
#ifdef __linux__
        case PlatformEnum::WINDOWS:
            loader = std::make_unique<OpenGL_Loader>();
            renderer = std::make_unique<OpenGL_Renderer>();
            strategy = std::make_unique<GLFW_WindowCreator>(*loader, *renderer);
            break;
#endif
        default:
            std::cout << "Unknown Platform!" << std::endl;
            strategy.reset();
    }

    const int16_t WINDOW_WIDTH = Environment::getWidth();
    const int16_t WINDOW_HEIGHT = Environment::getHeight();

    if (strategy && WINDOW_HEIGHT && WINDOW_WIDTH) {
        strategy->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    }
}
