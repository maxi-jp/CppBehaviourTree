
#include "Bot.h"

Bot::Bot(const std::string& name, char skin, int x, int y, int health, int damage, int range)
:
    name(name),
    skin(skin),
    x(x),
    y(y),
    health(health),
    damage(damage),
    range (range ),
    currentTask (0),
    currentEnemy(0)
{
    
}

Bot::~Bot()
{

}

void Bot::Start()
{
    // start the current task
}

void Bot::Update()
{
    // update the current task
}
