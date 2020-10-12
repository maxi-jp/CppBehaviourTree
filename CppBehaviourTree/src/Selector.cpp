#include "Selector.h"
#include "Bot.h"
#include "World.h"

Selector::Selector() : Task()
{
	currentTask = 0;
}

Selector::~Selector()
{
	
}

void Selector::Start()
{
	// start the first task of the selector
	// reset the queue (swap with an empty version https://stackoverflow.com/questions/709146/how-do-i-clear-the-stdqueue-efficiently)
	std::queue<Task*> empty;
	std::swap(tasksQueue, empty);
	// refill the queue with the tasks
	for (Task* task : tasks)
		tasksQueue.push(task);
	// set the current task with the first element of the queue
	currentTask = tasksQueue.front();
	// remove the first element of the queue
	tasksQueue.pop();
	// start the first task
	currentTask->Start();
}

void Selector::Reset()
{
	// reset all the tasks of this selector
	for (Task* task : tasks)
	{
		task->Reset();
	}
}

void Selector::Tick(Bot* bot, World* world)
{
	// update the current task
	currentTask->Tick(bot, world);

	// check for the current task state
	if (!currentTask->IsRunning())
	{
		if (currentTask->IsSuccess())
			Succeed();
		else // currentTask.IsFailure()
		{
			// check if there are more tasks in the selector
			if (tasksQueue.front() == 0)
				Fail(); // at this point it is sure not a success
			else
			{
				// there are more tasks in the queue, continue its execution
				// set the current task with the first (older) element of the queue
				currentTask = tasksQueue.front();
				// remove the first element of the queue
				tasksQueue.pop();
				// start this task
				currentTask->Start();
			}
		}
	}
	// else the current task is still running
}
