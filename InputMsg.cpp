//
// Created by manie on 02/01/2021.
//

#include "InputMsg.h"

std::unordered_map <std::string, InputMsg::Type> InputMsg::actionMap ={
        {"MOVE", InputMsg::Type::MOVE},
        {"CLICK", InputMsg::Type::CLICK},
        {"SELECT", InputMsg::Type::SELECT},
        {"COPY", InputMsg::Type::COPY},
        {"PASTE", InputMsg::Type::PASTE},
        {"WAIT", InputMsg::Type::WAIT},
        {"COPYW", InputMsg::Type::COPYW},
        {"PASTEW", InputMsg::Type::PASTEW},
        {"WTIME", InputMsg::Type::WTIME},
        {"WRITE", InputMsg::Type::WRITE},
        {"WRITE_NEWLINE", InputMsg::Type::WRITE_NEWLINE}
};


InputMsg::InputMsg(int msgId, InputMsg::Type messageType):msgId(msgId), messageType(messageType) {}

InputMsg::InputMsg(int msgId, InputMsg::Type messageType, std::vector<std::string> &params):msgId(msgId), messageType(messageType), params(params){}

void InputMsg::addParam(std::string &newParam) {
    params.push_back(newParam);
}

InputMsg::Type InputMsg::getMessageType() const {
    return messageType;
}

int InputMsg::getMsgId() const{
    return msgId;
}

std::vector<std::string> InputMsg::getParamsL() const {
    return params;
}

InputMsg::Type InputMsg::parseStrToType(std::string str) {
    return actionMap[str];
}

std::ostream &operator<<(std::ostream &os, const InputMsg &msg) {
    os << "msgId: " << msg.msgId << " messageType: " << msg.messageType << " params: ";

    for(const std::string& n : msg.params){
        os << n << " ";
    }

    return os;
}



