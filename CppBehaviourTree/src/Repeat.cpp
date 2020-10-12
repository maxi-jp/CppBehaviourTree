#include "Repeat.h"
#include "Bot.h"
#include "World.h"

Repeat::Repeat(Task* task) : Task(),
	task(task)
{
	count = auxCount = -1;
}

Repeat::Repeat(Task* task, int count) : Task(),
	task(task)
{
	this->count = auxCount = count;
}

Repeat::~Repeat()
{
	
}

void Repeat::Start()
{
	Task::Start();
	task->Start();
}

void Repeat::Reset()
{
	auxCount = count;
}

void Repeat::Tick(Bot* bot, World* world)
{
	if (task->IsFailure())
		Fail();
	else if (task->IsSuccess())
	{
		if (auxCount == 0)
			Succeed();
		else
		{
			auxCount--;
			task->Reset();
			task->Start();
		}
	}
	else if (task->IsRunning())
		task->Tick(bot, world);
}
