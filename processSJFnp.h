#pragma once

#include <string>
using namespace std;

class ProcessSJ {
public:
    ProcessSJ(string pid, int arrival, int burst);
    int getArrivalTime();
    int getBurstTime();
    int getCompletionTime();
    int getTurnAroundTime();
    int getWaitingTime();
    int getResponseTime();
    string getProcessId();
    int getOrderOfExecution();

    void setCompletionTime(int time);
    void calculateTurnAroundTime();
    void calculateWaitingTime();
    void setResponseTime(int time);
    void setOrderOfExecution(int order);

private:
    string processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
    bool started;
    int orderOfExecution;
};
