
#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Bot.h"

class World
{

private:
    int width;
    int height;

    std::vector<Bot*> bots;

public:
    World(int width, int height);
    virtual ~World();

    int GetWidth () const { return width;  }
    int GetHeight() const { return height; }
    std::vector<Bot*>* GetBots() { return &(bots); }

    void AddBot(Bot* bot);
    bool IsAccessible(int x, int y);

    void Draw();

};

#endif
