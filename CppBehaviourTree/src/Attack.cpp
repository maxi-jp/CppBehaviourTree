#include "Attack.h"
#include "Bot.h"
#include "World.h"

Attack::Attack() : Task()
{

}

Attack::~Attack()
{

}

void Attack::Reset()
{
	
}

void Attack::Tick(Bot* bot, World* world)
{
	if (bot->GetCurrentEnemy() != 0)
	{
		if (bot->GetCurrentEnemy()->IsAlive())
		{
			// there is an enemy bot and it is alive
			// make the damage!
			bot->GetCurrentEnemy()->Damage(bot->GetDamage());
			Succeed();
		}
		else
			Fail();
	}
	else
		Fail();
}
