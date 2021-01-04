//
// Created by manie on 01/01/2021.
//

#include "WinInController.h"

WinInController::WinInController() {
    fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
    waitTime = 500;
}

void WinInController::setWTime(int time) {
    waitTime = time;
}

void WinInController::moveMouse(int xPixCoord, int yPixCoord) const{
    double fx = xPixCoord * (65535.0f / fScreenWidth);
    double fy = yPixCoord * (65535.0f / fScreenHeight);
    INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    Input.mi.dx = fx;
    Input.mi.dy = fy;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void WinInController::sendLeftClick() const{
    this->sendLeftClickDown();
    this->sendLeftClickUp();
}

void WinInController::sendRightClick()const {
    this->sendRightClickDown();
    this->sendRightClickUp();
}

void WinInController::sendCopyCmd() const{
    INPUT inputs[4];
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_CONTROL;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 0x43;

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 0x43;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_CONTROL;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void WinInController::sendPasteCmd() const{
    INPUT inputs[4];
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_CONTROL;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 0x56;

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 0x56;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_CONTROL;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void WinInController::selectChars(int charNum) const{
    POINT p;

    if (GetCursorPos(&p)) {
        this->sendLeftClickDown();
        for(long i=p.x; i<p.x+charNum; ++i) {
            this->moveMouse(i, p.y);
        }
        this->sendLeftClickUp();
    }
}

void WinInController::sendLeftClickUp() const{
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    ::SendInput(1,&Input,sizeof(INPUT));
}

void WinInController::sendLeftClickDown()const {
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1,&Input,sizeof(INPUT));
}

void WinInController::sendRightClickUp()const {
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
    ::SendInput(1,&Input,sizeof(INPUT));
}

void WinInController::sendRightClickDown() const{
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
    ::SendInput(1,&Input,sizeof(INPUT));
}

void WinInController::wait(int sec) const{
    std::chrono::milliseconds dura(sec);
    std::this_thread::sleep_for( dura );
}

void WinInController::sendPasteCmdW() const{
    wait(waitTime);
    sendPasteCmd();
}

void WinInController::sendCopyCmdW() const{
    wait(waitTime);
    sendCopyCmd();
}
