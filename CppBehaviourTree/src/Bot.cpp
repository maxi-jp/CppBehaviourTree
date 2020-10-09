
#include "Bot.h"
#include <iostream>
#include <math.h>

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
    rangeSqr = range * range;
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

double Bot::DistanceBetweenBots(Bot* botA, Bot* botB)
{
    double dist = 0.f;
    int dX = std::abs(botA->GetX() - botB->GetX());
    int dY = std::abs(botA->GetY() - botB->GetY());
    return std::sqrt((dX * dX) + (dY * dY));
}

double Bot::DistanceBetweenBotsSquare(Bot* botA, Bot* botB)
{
    double dist = 0.f;
    int dX = std::abs(botA->GetX() - botB->GetX());
    int dY = std::abs(botA->GetY() - botB->GetY());
    return (dX * dX) + (dY * dY);
}

bool Bot::EnemyInRange(Bot* enemy)
{
    //return DistanceBetweenBots(this, enemy) < range;
    return DistanceBetweenBotsSquare(this, enemy) < rangeSqr;
}

std::ostream& operator<<(std::ostream& strm, const Bot& bot)
{
    return strm << "Bot[" << bot.skin << "]_task[" << bot.currentTask->ToString() << "]";
}
