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
    /**
     * Clear the color from the last frame
     */
    void prepare();

    /**
     * Main rendering entry point
     * @param model VAO Model that contains vertexes and vao ID info
     */
    void render(const RawModel &model);
};

#endif //AR_ENGINE_IRENDERER_H