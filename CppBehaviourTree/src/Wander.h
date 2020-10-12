#ifndef WANDER_H
#define WANDER_H

#include "Task.h"
#include "MoveTo.h"

// select a random position on the map (different to the current position) and go towards it
class Wander : public Task
{
private:
    World* world;
    Bot* bot;
    MoveTo* moveTo;

public:
    Wander(World* world, Bot* bot);
    virtual ~Wander();

    void Reset();
    void Tick(Bot* bot, World* world);

    void Start();

    std::string ToString() {
        return std::string("Wander(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };
};

#endif