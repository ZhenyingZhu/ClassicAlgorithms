#include <thread>
#include <iostream>
#include <queue>

using namespace std;

struct Task {
    int id;
    Task(int i): id(i) {}
    run() {
        cout << "Task " << id << " is running" << endl;
    }
};

class DelayScheduler {
public:
    DelayScheduler() {
        // Start a dispatch thread
    }
 
    void schedule(int timestamp, Task &task) {
        // push the task to the queue
    }

private:
    struct TaskEntry {
        int timestamp;
        Task task;
        bool operator<(const TaskEntry &other) const {
            return timestamp < other.timestamp;
        }
    };

    struct Dispatcher {
        // the class run in dispatcher thread
        // 1. can be waken up to
    };

private:
    thread dispatcher_;
    priority_queue<TaskEntry> taskEntryHeap_;
};
