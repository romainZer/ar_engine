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
    glad_glClearColor(1, 0, 0, 1);
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
