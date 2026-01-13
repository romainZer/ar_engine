//
// Created by romai on 13/01/2026.
//


#include "OpenGL_Renderer.h"

#include "../../Models/RawModel.h"
#include "glad/glad.h"

/**
 * Clear the color from the last frame
 */
void OpenGL_Renderer::prepare() {
    constexpr uint8_t red = 1;
    constexpr uint8_t green = 0;
    constexpr uint8_t blue = 0;
    constexpr uint8_t alpha = 1;
    glad_glClearColor(red, green, blue, alpha);
}

/**
 * Main rendering entry point
 * @param model VAO Model that contains vertexes and vao Id info
 */
void OpenGL_Renderer::render(const RawModel &model) {
    glad_glBindVertexArray(static_cast<GLuint>(model.getVaoId()));
    glad_glEnableVertexAttribArray(0); //Enables the 0 list
    glad_glDrawArrays(GL_TRIANGLES, 0, model.getVertexesCount());
    glad_glDisableVertexAttribArray(0);
    glad_glBindVertexArray(0);
}
