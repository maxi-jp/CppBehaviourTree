#ifndef RUNAWAY_H
#define RUNAWAY_H

#include "Task.h"
#include "MoveTo.h"

// select a random position on the map and go towards it
class RunAway : public Task
{
private:
    World* world;
    MoveTo* moveTo;

public:
    RunAway(World* world);
    virtual ~RunAway();

    void Reset();
    void Tick(Bot* bot, World* world);

    void Start();

    std::string ToString() {
        return std::string("RunAway(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };
};

#endif