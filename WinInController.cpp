//
// Created by manie on 01/01/2021.
//

#include "WinInController.h"

WinInController::WinInController() {
    fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
}

void WinInController::moveMouse(int xPixCoord, int yPixCoord) {
    double fx = xPixCoord * (65535.0f / fScreenWidth);
    double fy = yPixCoord * (65535.0f / fScreenHeight);
    INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    Input.mi.dx = fx;
    Input.mi.dy = fy;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void WinInController::sendLeftClick() {
    this->sendLeftClickUp();
    this->sendLeftClickDown();
}

void WinInController::sendRightClick() {
    this->sendRightClickUp();
    this->sendRightClickDown();
}

void WinInController::sendCopyCmd() {
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

void WinInController::sendPasteCmd() {
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

void WinInController::selectChars(int charNum) {
    POINT p;

    if (GetCursorPos(&p)) {
        this->sendLeftClickDown();
        for(long i=p.x; i<p.x+charNum; ++i) {
            this->moveMouse(i, p.y);
        }
        this->sendLeftClickUp();
    }
}

void WinInController::sendLeftClickUp() {
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    ::SendInput(1,&Input,sizeof(INPUT));
}

void WinInController::sendLeftClickDown() {
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1,&Input,sizeof(INPUT));
}

void WinInController::sendRightClickUp() {
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
    ::SendInput(1,&Input,sizeof(INPUT));
}

void WinInController::sendRightClickDown() {
    INPUT    Input={0};
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
    ::SendInput(1,&Input,sizeof(INPUT));
}
