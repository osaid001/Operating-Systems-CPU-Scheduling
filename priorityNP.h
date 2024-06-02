#pragma once

class ProcessPRInp
{
private:
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int responseTime;
    int completionTime;
    int turnaroundTime;
    bool started;

public:
    ProcessPRInp(int id, int arrival, int burst, int priority);

    int getArrivalTime() const;
    int getBurstTime() const;
    int getPriority() const;
    int getCompletionTime() const;
    int getTurnaroundTime() const;
    int getWaitingTime() const;
    int getResponseTime() const;
    int getId() const;

    void setCompletionTime(int time);
    void calculateTurnaroundTime();
    void calculateWaitingTime();
    void setResponseTime(int time);
};

class SchedulerPriorityNP {
private:
    ProcessPRInp** processes;
    int numProcesses;

public:
    SchedulerPriorityNP(int n);
    void addProcess(int index, int id, int arrival, int burst, int priority);
    void scheduleNonPreemptive();
    void getCompletionTimes(int completionTimes[]) const;
    void getTurnaroundTimes(int turnaroundTimes[]) const;
    void getWaitingTimes(int waitingTimes[]) const;
    void getResponseTimes(int responseTimes[]) const;
    void getProcessOrder(int processIds[]) const;
    int* getganttChart(int& total_time);
    ~SchedulerPriorityNP();
};
