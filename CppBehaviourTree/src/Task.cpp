#include "Task.h"
#include <iostream>

TaskStateToStr Task::tStateToStr;

Task::Task() : tState (TaskState::SUCCESS)
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
