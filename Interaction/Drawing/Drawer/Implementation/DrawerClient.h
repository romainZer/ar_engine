//
// Created by romainz on 06/01/2026.
//

#ifndef AR_ENGINE_DRAWERCLIENT_H
#define AR_ENGINE_DRAWERCLIENT_H
#include "../IDrawerResource.h"


/**
 * Drawer that
 */
class DrawerClient : IDrawerResource{
public:
    DrawerClient() = default;
    ~DrawerClient() override = default;

    /**
     * Draws a simple triangle
     */
    void drawTriangle() override;

    /**
     * Draws a square
     */
    void drawSquare() override;
};


#endif //AR_ENGINE_DRAWERCLIENT_H