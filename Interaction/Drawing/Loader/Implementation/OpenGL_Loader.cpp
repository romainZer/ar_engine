//
// Created by romai on 12/01/2026.
//

#include "OpenGL_Loader.h"

#include "glad/glad.h"

void OpenGL_Loader::storeDataInAttributeList(const int attributeNumber, const std::vector<float> &data) {
    GLuint vboId;
    glad_glGenBuffers(1, &vboId);
    this->VBOs.push_back(vboId);
    glad_glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glad_glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(data.size() * sizeof(float)), data.data(),
                      GL_STATIC_DRAW);
    glad_glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glad_glEnableVertexAttribArray(attributeNumber);
    glad_glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGL_Loader::unbindVAO() {
    glad_glBindVertexArray(0);
}

int OpenGL_Loader::createVAO() {
    GLuint vaoId;
    glad_glGenVertexArrays(1, &vaoId);
    // Add into VAO List
    this->VAOs.push_back(vaoId);
    glad_glBindVertexArray(vaoId);
    return static_cast<int>(vaoId);
}

std::unique_ptr<RawModel> OpenGL_Loader::loadToVAO(const std::vector<float> &positions) {
    int vaoId = createVAO();
    storeDataInAttributeList(0, positions);
    unbindVAO();

    auto vertexCount = static_cast<int>(positions.size() / 3);
    return std::make_unique<RawModel>(vaoId, vertexCount);
}

OpenGL_Loader::~OpenGL_Loader() {
    OpenGL_Loader::cleanUp();
}

void OpenGL_Loader::cleanUp() {
    if (!VAOs.empty()) {
        glad_glDeleteVertexArrays(static_cast<GLsizei>(VAOs.size()), VAOs.data());
        VAOs.clear();
    }

    if (!VBOs.empty()) {
        glad_glDeleteBuffers(static_cast<GLsizei>(VBOs.size()), VBOs.data());
        VBOs.clear();
    }
}
