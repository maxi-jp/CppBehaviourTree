#include "CheckPower.h"
#include "Bot.h"
#include "World.h"

CheckPower::CheckPower() : Task()
{

}

CheckPower::~CheckPower()
{

}

void CheckPower::Reset()
{
	Start();
}

void CheckPower::Tick(Bot* bot, World* world)
{
	if (bot->GetCurrentEnemy() != 0)
	{
		bot->GetDamage() >= bot->GetCurrentEnemy()->GetDamage() ? Succeed() : Fail();
	}
	else
		Fail();
}
