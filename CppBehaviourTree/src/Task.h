
#ifndef TASK_H
#define TASK_H

#include <string>
#include <map>

// forward classes declarations
class Bot;
class World;

enum class TaskState
{
    SUCCESS = 0,
    FAILURE = 1,
    RUNNING = 2
};

struct TaskStateToStr
{
    /*const char * str[] = { "success", "failure", "running" };
    const char* GetStr(TaskState tState) { return str[static_cast<std::underlying_type_t<TaskState>>(tState)]; }*/
};

class Task
{

protected:
    TaskState tState;

    void Succeed();
    void Fail();

public:
    Task();
    virtual ~Task();

    static TaskStateToStr tStateToStr;
    
    TaskState GetState() { return tState; }

    void Start();
    //virtual void Reset();
    //virtual void Tick(Bot* bot, World* world);

    bool IsSuccess() { return tState == TaskState::SUCCESS; }
    bool IsFailure() { return tState == TaskState::FAILURE; }
    bool IsRunning() { return tState == TaskState::RUNNING; }

    const std::string& ToString() { return std::string(""); // TODO
    }
};

#endif
