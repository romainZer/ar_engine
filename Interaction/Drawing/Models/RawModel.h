//
// Created by romai on 12/01/2026.
//

#ifndef AR_ENGINE_RAWMODEL_H
#define AR_ENGINE_RAWMODEL_H

/**
 * Represents a VAO model
 */
class RawModel {
protected:
    int vaoId;
    int vertexCount;

public:
    RawModel(int vaoId, int vertexCount);

    virtual ~RawModel() = default;

    /**
     * Retrieves the VAO Id
     * @return The unique VAO Id
     */
    [[nodiscard]]
    int getVaoId() const;

    /**
     * Retrieves the number of vertexes
     * @return The number of vertexes
     */
    [[nodiscard]]
    int getVertexesCount() const;
};

#endif //AR_ENGINE_RAWMODEL_H
