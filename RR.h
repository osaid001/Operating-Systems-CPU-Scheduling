#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Processrr {
    string id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
};

class SchedulerRR {
private:
    Processrr* processes;
    int* processOrder;
    int numProcesses;
    int quantum;

public:
    SchedulerRR(int n, int q);
    void addProcess(int index, string pid, int arrival, int burst);
    void schedule();
    void calculateTurnaroundTime();
    void calculateWaitingTime();
    void getCompletionTimes(int* completionTimes);
    void getTurnAroundTimes(int* turnAroundTimes);
    void getWaitingTimes(int* waitingTimes);
    void getResponseTimes(int* responseTimes);
    void getProcessOrder(string* processIds);
    ~SchedulerRR();
};
