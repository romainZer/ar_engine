//
// Created by romainz on 06/01/2026.
//

#ifndef AR_ENGINE_LINUXPLATEFORMWINDOWMAKER_H
#define AR_ENGINE_LINUXPLATEFORMWINDOWMAKER_H
#include <GLFW/glfw3.h>

#include "../WindowCreatorStrategy.h"

/**
 * Window maker Linux platform
 */
class LinuxPlatformWindowMaker : public IWindowCreatorStrategy {
public:

    LinuxPlatformWindowMaker() = default;

    /**
     * Creates a window
     * @param x Window width
     * @param y Window height
     */
    void createWindow(uint16_t x, uint16_t y) override;

protected:
    /**
     * Initializes the window configuration
     */
    static void initConfig();

    /**
     * Creates a window and defines its context
     * @param width Window width
     * @param height Window height
     * @param title Window title
     * @return The pointer to the window instance
     */
    static GLFWwindow *createWindowAndDefineContext(uint16_t width, uint16_t height,
                                                    const char *title);

    /**
     * Clears the window
     * @param window
     */
    static void clearWindow(GLFWwindow *window);
};

#endif //AR_ENGINE_LINUXPLATEFORMWINDOWMAKER_H
