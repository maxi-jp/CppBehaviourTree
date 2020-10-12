#ifndef TASKSFACTORY_H
#define TASKSFACTORY_H

#include "Task.h"
#include <memory>

class TasksFactory
{
public:
    TasksFactory();

    static std::shared_ptr<Task> CreateIdle();
    static std::shared_ptr<Task> CreateMoveTo(int x, int y);
    static std::shared_ptr<Task> CreateCheckRange();
    static std::shared_ptr<Task> CreateCheckPower();
    static std::shared_ptr<Task> CreateAttack();
    static std::shared_ptr<Task> CreateWander(World* world, Bot* bot);
    static std::shared_ptr<Task> CreateRunAway(World* world);
    static std::shared_ptr<Task> CreateRepeat(std::shared_ptr<Task> task);
    static std::shared_ptr<Task> CreateRepeat(std::shared_ptr<Task> task, int count);
    static std::shared_ptr<Task> CreateSequence(std::initializer_list<Task*> tasks);
    static std::shared_ptr<Task> CreateSelector(std::initializer_list<Task*> tasks);
};

#endif