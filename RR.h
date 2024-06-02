#pragma once

#include <iostream>
#include <string>

using namespace std;

class Processrr {
public:
    string id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;

    Processrr() : id(""), arrivalTime(0), burstTime(0), completionTime(0), turnaroundTime(0), waitingTime(0), responseTime(0) {}

    void calculateTurnaroundTime() {
        turnaroundTime = completionTime - arrivalTime;
    }

    void calculateWaitingTime() {
        waitingTime = turnaroundTime - burstTime;
    }
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
    int* recordProcessExecution(int& total_time);

    ~SchedulerRR();
};
