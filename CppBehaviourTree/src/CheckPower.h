#ifndef CHECKPOWER_H
#define CHECKPOWER_H

#include "Task.h"

class CheckPower : public Task
{

public:
    CheckPower();
    virtual ~CheckPower();

    void Reset();
    void Tick(Bot* bot, World* world);

    std::string ToString() {
        return std::string("CheckPower(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };
};

#endif