#include "World.h"

#include <iostream>

World::World(int width, int height)
:
    width (width),
    height(height)
{
    
}

World::~World()
{

}

void World::AddBot(Bot* bot)
{
    bots.push_back(bot);
    bot->SetWorld(this);
}

bool World::IsAccessible(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return false;

    /*for (auto it = bots.begin(); it != bots.end(); it++)
    {
        if ((*it)->GetX() == x && (*it)->GetY() == y)
            return false;
    }*/

    for (auto& bot : bots)
    {
        if (bot->GetX() == x && bot->GetY() == y)
            return false;
    }

    return true;
}

void World::Draw()
{
    // top line
    std::cout << std::endl;
    std::cout << '+';
    for (int i = 0; i < width; i++)
        std::cout << "---";
    std::cout << '+' << std::endl;

    bool isBot = false;
    for (int j = 0; j < height; j++)
    {
        std::cout << '|';
        for (int i = 0; i < width; i++)
        {
            // search for bots in this position
            isBot = false;
            char botSkin = 'x';
            for (auto& bot : bots)
            {
                if (bot->GetX() == i && bot->GetY() == j)
                {
                    isBot = true;
                    botSkin = bot->GetSkin();
                    break;
                }
            }

            isBot ? std::cout << '-' << botSkin << '-' : std::cout << "   ";
        }
        std::cout << '|' << std::endl;;
    }

    // down line
    std::cout << '+';
    for (int i = 0; i < width; i++)
        std::cout << "---";
    std::cout << '+' << std::endl;
}
