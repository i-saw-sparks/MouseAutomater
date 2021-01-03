//
// Created by manie on 01/01/2021.
//

#ifndef MOUSEAUTOMATER_INPREPL_H
#define MOUSEAUTOMATER_INPREPL_H
#include <iostream>
#include <string>
#include <queue>
#include "WinInController.h"
#include "InputMsg.h"
#include <fstream>

class InpRepl {
public:
    InpRepl();

    void runRepl(std::string fileName);
    void readInput(std::string);
    void executeAction(InputMsg);

private:
    std::string input;
    std::vector<InputMsg> inpMessQ;
    WinInController winIn;
};


#endif //MOUSEAUTOMATER_INPREPL_H
