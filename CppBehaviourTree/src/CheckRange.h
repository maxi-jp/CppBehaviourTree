#ifndef CHECKRANGE_H
#define CHECKRANGE_H

#include "Task.h"
#include "Bot.h"

class CheckRange : public Task
{

public:
    CheckRange();
    virtual ~CheckRange();

    void Reset();
    void Tick(Bot* bot, World* world);

    bool IsInRange(Bot* me, Bot* enemy) { return me->EnemyInRange(enemy); };

    std::string ToString() {
        return std::string("CheckRange(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };
};

#endif