#include "RunAway.h"
#include "Bot.h"
#include "World.h"
#include <stdlib.h> // rand

RunAway::RunAway(World* world) : Task(),
	world(world)
{
	// select a random position in world coordinates
	moveTo = new MoveTo(std::rand() % world->GetWidth(), std::rand() % world->GetHeight());
}

RunAway::~RunAway()
{
	delete moveTo;
}

void RunAway::Start()
{
	Task::Start();
	moveTo->Start();
}

void RunAway::Reset()
{
	delete moveTo;
	// select a random position in world coordinates
	moveTo = new MoveTo(std::rand() % world->GetWidth(), std::rand() % world->GetHeight());
}

void RunAway::Tick(Bot* bot, World* world)
{
	if (moveTo->IsRunning())
	{
		moveTo->Tick(bot, world);

		// check if the moveTo has reached its destination or has failed
		if (moveTo->IsSuccess())
			Succeed();
		else if (moveTo->IsFailure())
			Fail();
	}
}
