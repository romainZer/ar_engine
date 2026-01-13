//
// Created by romai on 12/01/2026.
//

#ifndef AR_ENGINE_DRAWER_H
#define AR_ENGINE_DRAWER_H

class IDrawerResource {
public:
    virtual ~IDrawerResource() = default;
    virtual void drawSquare() = 0;
    virtual void drawTriangle() = 0;

};

#endif //AR_ENGINE_DRAWER_H