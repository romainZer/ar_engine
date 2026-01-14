#ifndef AR_ENGINE_WINDOWMAKERDAO_H
#define AR_ENGINE_WINDOWMAKERDAO_H
#include <cstdint>

#include "../Drawing/Loader/IGraphicLoader.h"
#include "../Drawing/Renderer/IRenderer.h"

/**
 * Window maker strategy that creates a base window depending on the user platform (ex: Window, Linux, etc.)
 */
class IWindowCreatorStrategy {
protected:
    IGraphicLoader& loader;
    IRenderer& renderer;
public:
    explicit IWindowCreatorStrategy(IGraphicLoader& loader, IRenderer& renderer)
            : loader(loader), renderer(renderer) {}
    virtual ~IWindowCreatorStrategy() = default;

    /**
     * Creates a window using default dimensions
     * @param x X dimension
     * @param y Y dimension
     */
    virtual void createWindow(uint16_t x, uint16_t y) = 0;
};

#endif //AR_ENGINE_WINDOWMAKERDAO_H
