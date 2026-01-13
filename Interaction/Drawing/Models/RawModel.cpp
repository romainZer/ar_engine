//
// Created by romai on 12/01/2026.
//

#include "RawModel.h"

RawModel::RawModel(const int vaoId, const int vertexCount) {
    this->vaoId = vaoId;
    this->vertexCount = vertexCount;
}

int RawModel::getVaoId() const {
    return this->vaoId;
}

int RawModel::getVertexesCount() const {
    return this->vertexCount;
}
