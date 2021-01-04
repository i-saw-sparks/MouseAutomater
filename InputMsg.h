//
// Created by manie on 02/01/2021.
//

#ifndef MOUSEAUTOMATER_INPUTMSG_H
#define MOUSEAUTOMATER_INPUTMSG_H
#include <vector>
#include <unordered_map>
#include <ostream>


class InputMsg {
public:
    enum Type {NULLACT, MOVE, CLICK, SELECT, COPY, PASTE, WAIT, COPYW, PASTEW, WTIME};

    InputMsg(int msgId, Type messageType);
    InputMsg(int msgId, Type messageType, std::vector<double>&);

    void addParam(long);

    int getMsgId() const;
    Type getMessageType() const;
    std::vector<double> getParamsL() const;

    static Type parseStrToType(std::string);

    friend std::ostream &operator<<(std::ostream &os, const InputMsg &msg);

private:
    int msgId;
    Type messageType;
    std::vector<double> params;
    static std::unordered_map <std::string, Type> actionMap;
};



#endif //MOUSEAUTOMATER_INPUTMSG_H
