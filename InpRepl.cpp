//
// Created by manie on 01/01/2021.
//

#include "InpRepl.h"

void InpRepl::runRepl(std::string fileName) {
    readInput(fileName);
    int totalActs = inpMessQ.size(), executed = 0;
    std::cout<<"Progress: 0%";
    for(auto &n : inpMessQ){
        executeAction(n);
        executed++;
        printf("\rProgress: %i%%  ", executed*100/totalActs);
    }
}

void InpRepl::readInput(std::string fileName) {
    std::ifstream infile(fileName, std::ifstream::in);
    std::string line, action;
    std::vector<long> params;

    if(infile.is_open()){
        int lineId = 0;
        while(std::getline(infile, line)){
            int spPos = line.find(' ');
            params.clear();

            if(spPos != -1) {
                action = line.substr(0, spPos);
                std::string paramSub = line.substr(spPos+1, line.size());

                int paramsPos = paramSub.find(',');
                if(paramsPos != -1){
                    params.push_back(stol(paramSub.substr(0, paramsPos)));
                    params.push_back(stol(paramSub.substr(paramsPos+1, paramSub.size())));
                }else{
                    params.push_back(stol(paramSub));
                }
            }else{
                action = line;
            }

            inpMessQ.push_back(InputMsg(lineId+1,InputMsg::parseStrToType(action), params));

            std::cout<<inpMessQ[lineId]<<std::endl;

            lineId++;
        }


    }else{
        std::cout<<std::endl<<"ERRx01: The file was not found or and error reading the file ocurred";
    }

    infile.close();
}


InpRepl::InpRepl() {

}

void InpRepl::executeAction(InputMsg cmd) {
    switch (cmd.getMessageType()){
        case InputMsg::Type::MOVE:
            if(cmd.getParamsL().size() == 2){
                winIn.moveMouse(cmd.getParamsL()[0], cmd.getParamsL()[1]);
            }else{
                std::cout<<"ERRx02: in line " << cmd.getMsgId() << " action MOVE takes 2 parameters"<<std::endl;
            }
            break;

        case InputMsg::Type::CLICK:
            if(cmd.getParamsL().size() == 0){
                winIn.sendLeftClick();
            }else{
                std::cout<<"ERRx03: in line " << cmd.getMsgId() << " action CLICK does not take parameters"<<std::endl;
            }
            break;

        case InputMsg::Type::COPY:
            if(cmd.getParamsL().size() == 0){
                winIn.sendCopyCmd();
            }else{
                std::cout<<"ERRx04: in line " << cmd.getMsgId() << " action COPY does not take parameters"<<std::endl;
            }
            break;

        case InputMsg::Type::PASTE:
            if(cmd.getParamsL().size() == 0){
                winIn.sendPasteCmd();
            }else{
                std::cout<<"ERRx05: in line " << cmd.getMsgId() << " action PASTE does not take parameters"<<std::endl;
            }
            break;

        case InputMsg::Type::SELECT:
            if(cmd.getParamsL().size() == 1){
                winIn.selectChars(cmd.getParamsL()[0]);
            }else{
                std::cout<<"ERRx06: in line " << cmd.getMsgId() << " action SELECT takes 1 parameter"<<std::endl;
            }
            break;

        case InputMsg::Type::WAIT:
            if(cmd.getParamsL().size() == 1){
                winIn.wait(cmd.getParamsL()[0]);
            }else{
                std::cout<<"ERRx06: in line " << cmd.getMsgId() << " action WAIT takes 1 parameter"<<std::endl;
            }
            break;

        case InputMsg::Type::NULLACT:
            std::cout<<"ERRx07: in line " << cmd.getMsgId() << " action was not identified. Maybe the action have a typo or the line is empty"<<std::endl;
    }
}
