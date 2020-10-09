#ifndef ATTACK_H
#define ATTACK_H

#include "Task.h"

class Attack : public Task
{

public:
    Attack();
    virtual ~Attack();

    void Reset();
    void Tick(Bot* bot, World* world);

    std::string ToString() {
        return std::string("Attack(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };
};

#endif