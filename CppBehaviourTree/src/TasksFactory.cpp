#include "TasksFactory.h"
#include "Idle.h"
#include "MoveTo.h"
#include "CheckRange.h"
#include "CheckPower.h"
#include "Attack.h"
#include "Wander.h"
#include "RunAway.h"
#include "Repeat.h"
#include "Sequence.h"
#include "Selector.h"

TasksFactory::TasksFactory()
{

}

static TasksFactory wat()
{
    return TasksFactory();
}

std::shared_ptr<Task> TasksFactory::CreateIdle()
{
    return std::make_shared<Idle>();
}

std::shared_ptr<Task> TasksFactory::CreateMoveTo(int x, int y)
{
    return std::make_shared<MoveTo>(x, y);
}

std::shared_ptr<Task> TasksFactory::CreateCheckRange()
{
    return std::make_shared<CheckRange>();
}

std::shared_ptr<Task> TasksFactory::CreateCheckPower()
{
    return std::make_shared<CheckPower>();
}

std::shared_ptr<Task> TasksFactory::CreateAttack()
{
    return std::make_shared<Attack>();
}

std::shared_ptr<Task> TasksFactory::CreateWander(World* world, Bot* bot)
{
    return std::make_shared<Wander>(world, bot);
}

std::shared_ptr<Task> TasksFactory::CreateRunAway(World* world)
{
    return std::make_shared<RunAway>(world);
}

std::shared_ptr<Task> TasksFactory::CreateRepeat(std::shared_ptr<Task> task)
{
    return std::make_shared<Repeat>(task.get());
}

std::shared_ptr<Task> TasksFactory::CreateRepeat(std::shared_ptr<Task> task, int count)
{
    return std::make_shared<Repeat>(task.get(), count);
}

std::shared_ptr<Task> TasksFactory::CreateSequence(std::initializer_list<Task*> tasks)
{
    std::shared_ptr<Sequence> sequence = std::make_shared<Sequence>();

    for (Task* task : tasks)
    {
        sequence->AddTask(task);
    }

    return sequence;
}

std::shared_ptr<Task> TasksFactory::CreateSelector(std::initializer_list<Task*> tasks)
{
    std::shared_ptr<Selector> selector = std::make_shared<Selector>();

    for (Task* task : tasks)
    {
        selector->AddTask(task);
    }

    return selector;
}
