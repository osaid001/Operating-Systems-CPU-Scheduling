#pragma once

#include "ProcessSJFnp.h"

class SchedulerSJF {
private:
    ProcessSJ** processes;
    int numProcesses;

public:
    SchedulerSJF(int n);
    void addProcess(int index, string pid, int arrival, int burst);
    void schedule();
    void getCompletionTimes(int* completionTimes);
    void getTurnAroundTimes(int* turnAroundTimes);
    void getWaitingTimes(int* waitingTimes);
    void getResponseTimes(int* responseTimes);
    void getProcessOrder(string* processIds);
    ~SchedulerSJF();
};
