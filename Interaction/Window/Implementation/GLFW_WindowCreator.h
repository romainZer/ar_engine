//
// Created by romainz on 06/01/2026.
//

#ifndef AR_ENGINE_LINUXPLATFORMWINDOWMAKER_H
#define AR_ENGINE_LINUXPLATFORMWINDOWMAKER_H

#include <memory>
#include <GLFW/glfw3.h>

#include "../IWindowCreatorStrategy.h"
#include "../../Drawing/Drawer/Implementation/DrawerClient.h"
#include "../../Drawing/Renderer/IRenderer.h"

/**
 * Window maker Linux platform
 */
class GLFW_WindowCreator : public IWindowCreatorStrategy {
private:
    std::unique_ptr<IGraphicLoader> loader;
    std::unique_ptr<DrawerClient> drawer;

    /**
     * Initializes the window configuration
     */
    void initConfig();

    /**
     * Creates a window and defines its context
     * @param width Window width
     * @param height Window height
     * @param title Window title
     * @return The pointer to the window instance
     */
    GLFWwindow *createWindowAndDefineContext(uint16_t width, uint16_t height, const char *title);

    /**
     * Clears the window
     * @param window
     */
    void clearWindow(GLFWwindow *window);

public:
    explicit GLFW_WindowCreator(IGraphicLoader &loader, IRenderer &renderer);

    ~GLFW_WindowCreator() override = default;

    /**
     * Creates a window
     * @param x Window width
     * @param y Window height
     */
    void createWindow(uint16_t x, uint16_t y) override;
};

#endif //AR_ENGINE_LINUXPLATFORMWINDOWMAKER_H
