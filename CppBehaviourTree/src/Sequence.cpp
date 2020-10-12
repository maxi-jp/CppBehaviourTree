#include "Sequence.h"
#include "Bot.h"
#include "World.h"

Sequence::Sequence() : Task()
{
	currentTask = 0;
}

Sequence::~Sequence()
{
	
}

void Sequence::Start()
{
	// start the first task of the sequence
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

void Sequence::Reset()
{
	// reset all the tasks of this sequence
	for (Task* task : tasks)
	{
		task->Reset();
	}
}

void Sequence::Tick(Bot* bot, World* world)
{
	// update the current task
	currentTask->Tick(bot, world);

	// check for the current task state
	if (!currentTask->IsRunning())
	{
		// if the current task has failed, the sequence fails
		if (currentTask->IsFailure())
			Fail();
		else // currentTask.IsSuccess()
		{
			// check if there are more tasks in the queue
			if (tasksQueue.front() == 0)
			{
				// the current task was the last of the sequence
				// it has succeeded so the sequence succeed
				Succeed();
			}
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
