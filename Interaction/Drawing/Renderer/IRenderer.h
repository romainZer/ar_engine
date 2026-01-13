//
// Created by romai on 13/01/2026.
//

#ifndef AR_ENGINE_IRENDERER_H
#define AR_ENGINE_IRENDERER_H
#include "../Models/RawModel.h"

/**
 * Interface that represents a main entry class for rendering processes
 */
class IRenderer {
public:
    virtual ~IRenderer() = default;

    /**
     * Clear the color from the last frame
     */
    virtual void prepare() = 0;

    /**
     * Main rendering entry point
     * @param model VAO Model that contains vertexes and vao ID info
     */
    virtual void render(const RawModel &model) = 0;
};

#endif //AR_ENGINE_IRENDERER_H
