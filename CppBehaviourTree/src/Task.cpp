#include "Task.h"

Task::Task()
{

}

Task::~Task()
{

}

void Task::Start()
{
    tState = TaskState::RUNNING;
}

void Task::Succeed()
{
    tState = TaskState::SUCCESS;
}

void Task::Fail()
{
    tState = TaskState::FAILURE;
}
