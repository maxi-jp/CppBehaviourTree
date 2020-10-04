#ifndef MOVETO_H
#define MOVETO_H

#include "Task.h"

class MoveTo : public Task
{

private:
    int x, y;

    bool HasReachedDestination(Bot* bot);
    void MoveBot(Bot* bot);

    friend std::ostream& operator << (std::ostream &strm, const MoveTo &moveTo);

public:
    MoveTo(int x, int y);
    virtual ~MoveTo();

    void Reset();
    void Tick(Bot* bot, World* world);

    std::string ToString() {
        return std::string("MoveTo(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };
};

#endif