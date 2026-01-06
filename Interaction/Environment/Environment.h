//
// Created by romainz on 06/01/2026.
//

#ifndef AR_ENGINE_ENVREADER_H
#define AR_ENGINE_ENVREADER_H

#include <cstdint>
#include <string>

/**
 * Reads environment variables
 */
class Environment {
public:
    /**
     * Gets the window width
     * @return Window width
     */
    static int16_t getWidth();

    /**
     * Gets the window height
     * @return Window height
     */
    static int16_t getHeight();

    /**
     * Gets the window title
     * @return The window title
     */
    static std::string getWindowTitle();
};

#endif //AR_ENGINE_ENVREADER_H
