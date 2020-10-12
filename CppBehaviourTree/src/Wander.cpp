#include "Wander.h"
#include "Bot.h"
#include "World.h"
#include <stdlib.h> // rand

Wander::Wander(World* world, Bot* bot) : Task(),
world(world),
bot(bot)
{
	// select a random position in world coordinates
	moveTo = new MoveTo(std::rand() % world->GetWidth(), std::rand() % world->GetHeight());
}

Wander::~Wander()
{
	delete moveTo;
}

void Wander::Start()
{
	Task::Start();
	moveTo->Start();
}

void Wander::Reset()
{
	delete moveTo;

	// select a new random position in world coordinates
	int randX = 0, randY = 0;
	do
	{
		randX = std::rand() % world->GetWidth();
		randY = std::rand() % world->GetHeight();
	} while ((randX == bot->GetX()) && (randY == bot->GetY()));

	moveTo = new MoveTo(randX, randY);
}

void Wander::Tick(Bot* bot, World* world)
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
