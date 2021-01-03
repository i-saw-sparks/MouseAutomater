//
// Created by manie on 01/01/2021.
//

#include "InpRepl.h"

void InpRepl::runRepl(std::string fileName) {
    readInput(fileName);
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

                int paramsPos = paramSub.find(", ");
                if(paramsPos != -1){
                    params.push_back(stol(paramSub.substr(0, paramsPos)));
                    params.push_back(stol(paramSub.substr(paramsPos+2, paramSub.size())));
                }else{
                    params.push_back(stol(paramSub));
                }
            }else{
                action = line;
            }

            inpMessQ.push_back(InputMsg(lineId,InputMsg::parseStrToType(action), params));

            std::cout<<inpMessQ[lineId]<<std::endl;

            lineId++;
        }


    }else{
        std::cout<<std::endl<<"ERRx01: The file was not found or and error reading the file ocurred";
    }

    infile.close();
}

std::string InpRepl::getLastInput() {
    return input;
}

InpRepl::InpRepl() {

}
