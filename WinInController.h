//
// Created by manie on 01/01/2021.
//

#ifndef MOUSEAUTOMATER_WININCONTROLLER_H
#define MOUSEAUTOMATER_WININCONTROLLER_H
#include <windows.h>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

class WinInController {
public:
    WinInController();

    void moveMouse(int xPixCoord, int yPixCoord);
    void sendLeftClick();
    void sendRightClick();
    void sendCopyCmd();
    void sendPasteCmd();
    void selectChars(int charNum);

private:
    double fScreenWidth;
    double fScreenHeight;
    void sendLeftClickUp();
    void sendLeftClickDown();
    void sendRightClickUp();
    void sendRightClickDown();
};


#endif //MOUSEAUTOMATER_WININCONTROLLER_H
