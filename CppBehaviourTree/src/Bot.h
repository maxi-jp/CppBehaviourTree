
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
    int rangeSqr;

    World* world;

    Task* currentTask;

    Bot* currentEnemy;

    friend std::ostream& operator << (std::ostream& strm, const Bot& bot);

public:
    Bot(const std::string& name, char skin, int x, int y, int health, int damage, int range);
    virtual ~Bot();

    std::string& GetName() { return name; }
    char GetSkin() const { return skin; }
    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetHealth() const { return health; }
    int GetDamage() const { return damage; }
    int GetRange()  const { return range;  }

    Bot* GetCurrentEnemy() const { return currentEnemy; }

    void SetWorld(World* world) { this->world = world; }
    void SetCurrentTask(Task* currentTask)  { this->currentTask = currentTask; }
    void SetCurrentEnemy(Bot* currentEnemy) { this->currentEnemy = currentEnemy; }

    void Start();
    void Update();

    bool IsAlive() const { return health > 0; }

    void Move(int despX, int despY);
    void Damage(int damage);

    static double DistanceBetweenBots(Bot* botA, Bot* botB);
    static double DistanceBetweenBotsSquare(Bot* botA, Bot* botB);
    bool EnemyInRange(Bot* enemy);
};

#endif
