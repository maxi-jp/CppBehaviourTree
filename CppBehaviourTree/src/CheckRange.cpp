#include "CheckRange.h"
#include "Bot.h"
#include "World.h"

CheckRange::CheckRange() : Task()
{

}

CheckRange::~CheckRange()
{

}

void CheckRange::Reset()
{
	Start();
}

void CheckRange::Tick(Bot* bot, World* world)
{
	for (Bot* enemy : *world->GetBots())
	{
		if (enemy != bot && IsInRange(bot, enemy))
		{
			bot->SetCurrentEnemy(enemy);
			Succeed();
			break;
		}
	}
	Fail();
}
