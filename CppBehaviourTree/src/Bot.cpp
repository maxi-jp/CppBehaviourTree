
#include "Bot.h"
#include <iostream>

Bot::Bot(const std::string& name, char skin, int x, int y, int health, int damage, int range)
:
    name(name),
    skin(skin),
    x(x),
    y(y),
    health(health),
    damage(damage),
    range (range ),
    world (0),
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
    currentTask->Start();

}

void Bot::Update()
{
    // update the current task
    currentTask->Tick(this, world);
}

void Bot::Move(int despX, int despY)
{
    x += despX;
    y += despY;
}

void Bot::Damage(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        std::cout << "bot " << name << " is dead";
    }
}
