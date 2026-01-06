//
// Created by romainz on 06/01/2026.
//

#ifndef AR_ENGINE_WINDOWSPLATEFORMWINDOWMAKER_H
#define AR_ENGINE_WINDOWSPLATEFORMWINDOWMAKER_H
#include "../WindowCreatorStrategy.h"

class WindowsPlatformWindowMaker : public IWindowCreatorStrategy {
public:
    void createWindow(uint16_t x, uint16_t y) override;
};

#endif //AR_ENGINE_WINDOWSPLATEFORMWINDOWMAKER_H