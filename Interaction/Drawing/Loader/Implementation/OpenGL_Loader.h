//
// Created by romai on 12/01/2026.
//

#ifndef AR_ENGINE_LOADER_H
#define AR_ENGINE_LOADER_H
#include <memory>
#include <vector>

#include "../IGraphicLoader.h"
#include "../../Models/RawModel.h"
#include "glad/glad.h"

/**
 * Handles loading data
 */
class OpenGL_Loader : public IGraphicLoader {
private:
    std::vector<GLuint> VAOs;
    std::vector<GLuint> VBOs;

    /**
     * Stored the data into the attribute list
     * @param attributeNumber Attribute id
     * @param data List of data we want to store
     */
    void storeDataInAttributeList(int attributeNumber, const std::vector<float> &data);

    void unbindVAO();

    int createVAO();

public:
    OpenGL_Loader() = default;

    ~OpenGL_Loader() override;

    /**
     * Loads positions into a VAO
     * @param positions All the positions to load into the VAO
     * @return A unique pointer to the created RawModel
     */
    std::unique_ptr<RawModel> loadToVAO(const std::vector<float> &positions) override;

    /**
     * Cleans all VAOs and VBOs
     */
    void cleanUp() override;
};

#endif //AR_ENGINE_LOADER_H
