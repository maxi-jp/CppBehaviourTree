#ifndef SELECTOR_H
#define SELECTOR_H

#include "Task.h"
#include <queue>

class Selector : public Task
{
private:
    Task* currentTask;
    std::vector<Task*> tasks;
    std::queue <Task*> tasksQueue;

public:
    Selector();
    virtual ~Selector();

    void Reset();
    void Tick(Bot* bot, World* world);

    void Start();

    std::string ToString() {
        return std::string("Selector(" + std::string(tStateToStr.GetStr(tState)) + ")");
    };

    void AddTask(Task* task) {
        tasks.push_back(task);
    }
};

#endif