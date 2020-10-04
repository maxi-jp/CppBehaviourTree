
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
    const char * str[3] = { "success", "failure", "running" };
    const char* GetStr(TaskState tState) { return str[static_cast<std::underlying_type_t<TaskState>>(tState)]; }
};

class Task
{

protected:
    TaskState tState;

    void Succeed();
    void Fail();

    const char* GetTaskStateStr() { return tStateToStr.GetStr(tState); }

public:
    Task();
    virtual ~Task();

    static TaskStateToStr tStateToStr;
    
    TaskState GetState() { return tState; }

    virtual void Start();

    virtual void Reset() = 0;
    virtual void Tick(Bot* bot, World* world) = 0;

    bool IsSuccess() const { return tState == TaskState::SUCCESS; }
    bool IsFailure() const { return tState == TaskState::FAILURE; }
    bool IsRunning() const { return tState == TaskState::RUNNING; }

    virtual std::string ToString() = 0;

};

#endif
