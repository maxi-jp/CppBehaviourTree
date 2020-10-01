#include "Idle.h"
#include "Bot.h"

Idle::Idle() : Task()
{

}

Idle::~Idle()
{

}

void Idle::Reset()
{
	Start();
}

void Idle::Tick(Bot* bot, World* world)
{
	
}
