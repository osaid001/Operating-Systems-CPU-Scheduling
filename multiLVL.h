#pragma once

#include <iostream>
#include <list>
#include <algorithm>

struct process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int remainingTime;
    int nextArrivalTime;

    process();
};

int findMIN(std::list<process*>& q);
void qrun(std::list<process*>& q, int quantum, int& currentTime, std::list<process*>& nextQueue);
void executeFCFS(std::list<process*>& q, int& currentTime);
void getCompletionTimes(process* processes, int n, int* completionTimes);
void getTurnaroundTimes(process* processes, int n, int* turnaroundTimes);
void getWaitingTimes(process* processes, int n, int* waitingTimes);
void getResponseTimes(process* processes, int n, int* responseTimes);
void calculateTimes(process* processes, int n);
void printTable(process* processes, int n);
void addProcess(process* processes, std::list<process*>& q1, int id, int arrivalTime, int burstTime);
void getProcessOrder(process* processes, int n, int* process_id);
int* recordProcessExecutionQueue(int currentTime, int quantum, int& total_time, std::list<process*>& q, std::list<process*>& q2);
int* recordProcessExecutionQueue3(int currentTime, int& total_time, std::list<process*>& q);
int getTotalTime(process* processes, int n);
