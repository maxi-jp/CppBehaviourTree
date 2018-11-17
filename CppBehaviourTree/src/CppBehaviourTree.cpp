
#include <iostream>
#include <string>

#include "BehaviourTree.h"
#include "World.h"
#include "Bot.h"

int main()
{
    std::cout << "hello world!" << std::endl;

    BehaviourTree bt;
    World world(14, 14);

    Bot bot1(std::string("bot1"), '€', 0, 0, 10, 2, 3);
    world.AddBot(&bot1);

    Bot bot2(std::string("bot2"), '$', 12, 12, 40, 1, 2);
    world.AddBot(&bot2);

    world.Draw();

    getchar();

    return 0;
}
