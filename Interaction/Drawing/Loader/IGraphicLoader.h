//
// Created by romai on 13/01/2026.
//

#ifndef AR_ENGINE_ILOADER_H
#define AR_ENGINE_ILOADER_H
#include <memory>
#include <vector>

#include "../Models/RawModel.h"

/**
 * Represents a generic graphic Loader
 */
class IGraphicLoader {
public:
    IGraphicLoader() = default;
    virtual ~IGraphicLoader() = default;

    /**
     * Loads positions into a VAO
     * @param positions All the positions to load into the VAO
     * @return A unique pointer to the created RawModel
     */
    virtual std::unique_ptr<RawModel> loadToVAO(const std::vector<float> &positions) = 0;

    /**
     * Cleans all VAOs and VBOs
     */
    virtual void cleanUp() = 0;
};

#endif //AR_ENGINE_ILOADER_H
