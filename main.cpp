#include <iostream>

#include "Interaction/Window/WindowCreatorClient.h"

int main() {
    const auto client = std::make_unique<WindowCreatorClient>();
#if defined(_WIN32)
    client->create(PlatformEnum::WINDOWS);
#elif defined(__linux__)
    client->create(PlatformEnum::LINUX);
#else
    std::cout << "Unknown platform!" << std::endl;
#endif

    return 0;
}
