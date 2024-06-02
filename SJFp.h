#pragma once

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class ProcessSJpre {
private:
    string processId;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
    bool started;

public:
    ProcessSJpre(string pid, int arrival, int burst);

    int getArrivalTime() const;
    int getBurstTime() const;
    int getRemainingTime() const;
    int getCompletionTime() const;
    int getTurnAroundTime() const;
    int getWaitingTime() const;
    int getResponseTime() const;
    string getProcessId() const;

    void setCompletionTime(int time);
    void setRemainingTime(int time);
    void calculateTurnAroundTime();
    void calculateWaitingTime();
    void setResponseTime(int time);
};

class SchedulerSJFpre {
private:
    ProcessSJpre** processes;
    int numProcesses;

public:
    SchedulerSJFpre(int n);
    void addProcess(int index, const string& pid, int arrival, int burst);
    void schedule();
    void schedulePreemptive();
    void getCompletionTimes(int completionTimes[]) const;
    void getTurnAroundTimes(int turnAroundTimes[]) const;
    void getWaitingTimes(int waitingTimes[]) const;
    void getResponseTimes(int responseTimes[]) const;
    void getProcessOrder(string processIds[]) const;
    int* recordProcessExecution(int& total_time);

    ~SchedulerSJFpre();
};
