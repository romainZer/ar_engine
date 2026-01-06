#include "WindowCreatorClient.h"

#include <iostream>
#include <ostream>

#include "../Environment/Environment.h"
#include "Implementation/LinuxPlatformWindowMaker.h"
#include "Implementation/WindowsPlatformWindowMaker.h"

void WindowCreatorClient::create(const PlatformEnum platform) {
    switch (platform) {
        case PlatformEnum::WINDOWS:
            strategy = std::make_unique<WindowsPlatformWindowMaker>();
            break;
        case PlatformEnum::LINUX:
            strategy = std::make_unique<LinuxPlatformWindowMaker>();
            break;
        default:
            std::cout << "Unknown Platform!" << std::endl;
            strategy.reset();
    }

    const int16_t WINDOW_WIDTH = Environment::getWidth();
    const int16_t WINDOW_HEIGHT = Environment::getHeight();

    if (strategy && WINDOW_HEIGHT && WINDOW_WIDTH) {
        strategy->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    }
};
