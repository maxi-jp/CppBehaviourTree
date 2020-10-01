#ifndef IDLE_H
#define IDLE_H

#include "Task.h"

class Idle : public Task
{

public:
    Idle();
    virtual ~Idle();

    void Reset();
    void Tick(Bot* bot, World* world);
};

#endif