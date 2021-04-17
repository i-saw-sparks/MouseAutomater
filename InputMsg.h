//
// Created by manie on 02/01/2021.
//

#ifndef MOUSEAUTOMATER_INPUTMSG_H
#define MOUSEAUTOMATER_INPUTMSG_H
#include <vector>
#include <unordered_map>
#include <ostream>
#include <string>


class InputMsg {
public:
    enum Type {NULLACT, MOVE, CLICK, SELECT, COPY, PASTE, WAIT, COPYW, PASTEW, WTIME, WRITE, WRITE_NEWLINE};

    InputMsg(int msgId, Type messageType);
    InputMsg(int msgId, Type messageType, std::vector<std::string>&);

    void addParam(std::string &);

    int getMsgId() const;
    Type getMessageType() const;
    std::vector<std::string> getParamsL() const;

    static Type parseStrToType(std::string);

    friend std::ostream &operator<<(std::ostream &os, const InputMsg &msg);

private:
    int msgId;
    Type messageType;
    std::vector<std::string> params;
    static std::unordered_map <std::string, Type> actionMap;
};



#endif //MOUSEAUTOMATER_INPUTMSG_H
