
#ifndef BOT_H
#define BOT_H

#include <string>

#include "Task.h"

class World; // forward declaration of the World class

class Bot
{

private:
    std::string name;
    char skin;
    int x;
    int y;
    int health;
    int damage;
    int range;

    World* world;

    Task* currentTask;

    Bot* currentEnemy;

public:
    Bot(const std::string& name, char skin, int x, int y, int health, int damage, int range);
    virtual ~Bot();

    std::string& GetName() { return name; }
    char GetSkin() { return skin; }
    int GetX() { return x; }
    int GetY() { return y; }

    void SetWorld(World* world) { this->world = world; }

    void Start();
    void Update();

    bool IsAlive() { return health > 0; }
};

#endif
