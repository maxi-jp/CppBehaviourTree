#include "Idle.h"
#include "Bot.h"

Idle::Idle() : Task()
{

}

Idle::~Idle()
{

}

void Idle::Start()
{
	Task::Start();
	tState = TaskState::SUCCESS;
}

void Idle::Reset()
{
	Start();
}

void Idle::Tick(Bot* bot, World* world)
{
	
}
