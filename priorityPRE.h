#pragma once

#include <iostream>

class ProcessPRIpre {
private:
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int responseTime;
    int completionTime;
    int turnaroundTime;
    int remainingTime;
    bool started;

public:
    ProcessPRIpre(int id, int arrival, int burst, int priority);

    int getArrivalTime() const;
    int getBurstTime() const;
    int getPriority() const;
    int getRemainingTime() const;
    int getCompletionTime() const;
    int getTurnaroundTime() const;
    int getWaitingTime() const;
    int getResponseTime() const;
    int getId() const;

    void setCompletionTime(int time);
    void setRemainingTime(int time);
    void calculateTurnaroundTime();
    void calculateWaitingTime();
    void setResponseTime(int time);
};

class SchedulerPriority {
private:
    ProcessPRIpre** processes;
    int numProcesses;

public:
    SchedulerPriority(int n);
    void addProcess(int index, int id, int arrival, int burst, int priority);
    void schedulePreemptive();
    void getCompletionTimes(int completionTimes[]) const;
    void getTurnaroundTimes(int turnaroundTimes[]) const;
    void getWaitingTimes(int waitingTimes[]) const;
    void getResponseTimes(int responseTimes[]) const;
    void getProcessOrder(int processIds[]) const;
    int* recordProcessExecution(int& total_time);

    ~SchedulerPriority();
};
