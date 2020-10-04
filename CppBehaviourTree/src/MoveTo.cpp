#include "MoveTo.h"
#include "Bot.h"
#include <iostream>

MoveTo::MoveTo(int x, int y) : Task()
{
	this->x = x;
	this->y = y;
}

MoveTo::~MoveTo()
{

}

bool MoveTo::HasReachedDestination(Bot* bot)
{
	return (bot->GetX() == x && bot->GetY() == y);
}

void MoveTo::MoveBot(Bot* bot)
{
	int despX = 0, despY = 0;

	if (bot->GetX() != x)
	{
		if (bot->GetX() < x)
			despX = 1;
		else // bot.getX() > x
			despX = -1;
	}

	if (bot->GetY() != y)
	{
		if (bot->GetY() < y)
			despY = 1;
		else // bot.getY() > y
			despY = -1;
	}

	bot->Move(despX, despY);

	if (HasReachedDestination(bot))
		Succeed();
}

void MoveTo::Reset()
{
	Start();
}

void MoveTo::Tick(Bot* bot, World* world)
{
	if (IsRunning())
	{
		if (!bot->IsAlive())
			Fail();
		else if (!HasReachedDestination(bot))
			MoveBot(bot);
	}
}

std::ostream& operator << (std::ostream& strm, const MoveTo &moveTo)
{
	return strm << "MoveTo(" << "estado" << ")";
}
