
#include <iostream>
#include <string>

#include "BehaviourTree.h"
#include "World.h"
#include "Bot.h"
#include "MoveTo.h"
#include "Idle.h"

int main()
{
    //std::cout << "hello world!" << std::endl;

    BehaviourTree bt;
    World world(14, 14);

    Bot bot1(std::string("bot1"), '€', 0, 0, 10, 2, 3);
    world.AddBot(&bot1);

    Bot bot2(std::string("bot2"), '$', 12, 12, 40, 1, 2);
    world.AddBot(&bot2);

    Task* moveTo = new MoveTo(13, 13);
    bot1.SetCurrentEnemy(&bot2);
    bot1.SetCurrentTask(moveTo);

    bot1.Start();

    Task* idle = new Idle();
    bot2.SetCurrentEnemy(&bot1);
    bot2.SetCurrentTask(idle);

    do 
    {
        // clean the screen
        system("CLS");

        bot1.Update();
        bot2.Update();

        world.Draw();
    } while (getchar());

    //getchar();

    delete moveTo;
    delete idle;

    return 0;
}
