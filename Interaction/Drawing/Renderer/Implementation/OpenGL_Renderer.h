//
// Created by romai on 13/01/2026.
//

#ifndef AR_ENGINE_RENDERER_H
#define AR_ENGINE_RENDERER_H
#include "../IRenderer.h"
#include "../../Models/RawModel.h"

class OpenGL_Renderer : public IRenderer {
public:
    /**
     * Clear the color from the last frame
     */
    void prepare() override;

    /**
     * Main rendering entry point
     * @param model VAO Model that contains vertexes and vao Id info
     */
    void render(const RawModel &model) override;
};


#endif //AR_ENGINE_RENDERER_H
