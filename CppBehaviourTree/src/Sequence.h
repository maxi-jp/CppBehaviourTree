#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Task.h"
#include <queue>

class Sequence : public Task
{
private:
    Task* currentTask;
    std::vector<Task*> tasks;
    std::queue <Task*> tasksQueue;

public:
    Sequence();
    virtual ~Sequence();

    void Reset();
    void Tick(Bot* bot, World* world);

    void Start();

    std::string ToString() {
        return std::string("Sequence(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };

    void AddTask(Task* task) {
        tasks.push_back(task);
    }
};

#endif