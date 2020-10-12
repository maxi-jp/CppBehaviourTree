
#include <iostream>
#include <string>

#include "BehaviourTree.h"
#include "World.h"
#include "Bot.h"
#include "MoveTo.h"
#include "Idle.h"
#include "TasksFactory.h"

int main()
{
    //std::cout << "hello world!" << std::endl;

    BehaviourTree bt;
    World world(14, 14);

    Bot bot1(std::string("bot1"), '€', 0, 0, 10, 2, 3);
    world.AddBot(&bot1);

    Bot bot2(std::string("bot2"), '$', 12, 12, 40, 1, 2);
    world.AddBot(&bot2);

    std::shared_ptr<Task> moveTo = TasksFactory::CreateMoveTo(13, 13);
    bot1.SetCurrentEnemy(&bot2);
    bot1.SetCurrentTask(moveTo.get());

    bot1.Start();

    std::shared_ptr<Task> idle = TasksFactory::CreateIdle();
    std::shared_ptr<Task> repeat = TasksFactory::CreateRepeat
    (
        TasksFactory::CreateRunAway(&world)
    );
    bot2.SetCurrentEnemy(&bot1);
    bot2.SetCurrentTask(repeat.get());

    bot2.Start();

    do 
    {
        // clean the screen
        system("CLS");

        bot1.Update();
        bot2.Update();

        world.Draw();

        std::cout << bot1 << std::endl;
        std::cout << bot2 << std::endl;
    } while (getchar());

    //getchar();

    return 0;
}
