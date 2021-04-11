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

    void moveMouse(int xPixCoord, int yPixCoord) const;
    void sendLeftClick() const;
    void sendRightClick() const;
    void sendCopyCmd() const;
    void sendPasteCmd() const;
    void selectChars(int charNum) const;
    void wait(int sec) const;
    void sendPasteCmdW() const;
    void sendCopyCmdW() const;
    void setWTime(int time);
    void writeStringKb(std::string &) const;

private:
    int waitTime;
    double fScreenWidth;
    double fScreenHeight;
    void sendLeftClickUp() const;
    void sendLeftClickDown() const;
    void sendRightClickUp() const;
    void sendRightClickDown() const;
    void writeASCIIChar(char) const;
    void sendKeyCmd(int) const;
};


#endif //MOUSEAUTOMATER_WININCONTROLLER_H
