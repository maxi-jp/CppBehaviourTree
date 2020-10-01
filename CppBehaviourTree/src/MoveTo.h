#ifndef MOVETO_H
#define MOVETO_H

#include "Task.h"

class MoveTo : public Task
{

private:
    int x, y;

    bool HasReachedDestination(Bot* bot);
    void MoveBot(Bot* bot);

public:
    MoveTo(int x, int y);
    virtual ~MoveTo();

    void Reset();
    void Tick(Bot* bot, World* world);
};

#endif