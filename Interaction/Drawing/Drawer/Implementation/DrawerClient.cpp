//
// Created by romainz on 06/01/2026.
//

#include "DrawerClient.h"

#include <GL/gl.h>

void DrawerClient::drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}


void DrawerClient::drawSquare() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

}