//
// Created by romainz on 06/01/2026.
//

#ifndef AR_ENGINE_WINDOWCREATORCLIENT_H
#define AR_ENGINE_WINDOWCREATORCLIENT_H

#include <memory>

#include "IWindowCreatorStrategy.h"
#include "../Drawing/Loader/IGraphicLoader.h"
#include "../Drawing/Renderer/IRenderer.h"
#include "Enums/PlatformEnum.h"

/**
 * Client that instanciate the window depending on the platform (OS)
 */
class WindowCreatorClient {
protected:
    std::unique_ptr<IWindowCreatorStrategy> strategy;
    std::unique_ptr<IGraphicLoader> loader;
    std::unique_ptr<IRenderer> renderer;
public:
    WindowCreatorClient() = default;
    ~WindowCreatorClient() = default;

    /**
     * Creates a window depending on the provided platform
     * @param platform Current used OS
     */
    void create(PlatformEnum platform);
};

#endif //AR_ENGINE_WINDOWCREATORCLIENT_H
