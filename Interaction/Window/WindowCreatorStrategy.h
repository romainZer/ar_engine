#ifndef AR_ENGINE_WINDOWMAKERDAO_H
#define AR_ENGINE_WINDOWMAKERDAO_H
#include <cstdint>

/**
 * Window maker strategy that creates a base window depending on the user platform (ex : Window, Linux..)
 */
class IWindowCreatorStrategy {
public:
    IWindowCreatorStrategy() = default;
    virtual ~IWindowCreatorStrategy() = default;

    /**
     * Creates a window using default dimensions
     * @param x X dimension
     * @param y Y dimension
     */
    virtual void createWindow(uint16_t x, uint16_t y) = 0;
};

#endif //AR_ENGINE_WINDOWMAKERDAO_H
