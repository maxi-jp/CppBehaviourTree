#ifndef REPEAT_H
#define REPEAT_H

#include "Task.h"

class Repeat : public Task
{
private:
    Task* task;
    int count;
    int auxCount;

public:
    Repeat(Task* task);
    Repeat(Task* task, int count);
    virtual ~Repeat();

    void Reset();
    void Tick(Bot* bot, World* world);

    void Start();

    std::string ToString() {
        return std::string("Repeat(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };
};

#endif