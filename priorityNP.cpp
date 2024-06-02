// priority.cpp
#include "priorityNP.h"
#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Process class definitions
ProcessPRInp::ProcessPRInp(int id, int arrival, int burst, int priority)
    : id(id), arrivalTime(arrival), burstTime(burst), priority(priority),
    waitingTime(0), responseTime(-1), completionTime(0), turnaroundTime(0),
    started(false) {}

int ProcessPRInp::getArrivalTime() const { return arrivalTime; }
int ProcessPRInp::getBurstTime() const { return burstTime; }
int ProcessPRInp::getPriority() const { return priority; }
int ProcessPRInp::getCompletionTime() const { return completionTime; }
int ProcessPRInp::getTurnaroundTime() const { return turnaroundTime; }
int ProcessPRInp::getWaitingTime() const { return waitingTime; }
int ProcessPRInp::getResponseTime() const { return responseTime; }
int ProcessPRInp::getId() const { return id; }

void ProcessPRInp::setCompletionTime(int time) { completionTime = time; }
void ProcessPRInp::calculateTurnaroundTime() { turnaroundTime = completionTime - arrivalTime; }
void ProcessPRInp::calculateWaitingTime() { waitingTime = turnaroundTime - burstTime; }
void ProcessPRInp::setResponseTime(int time) {
    if (!started) {
        responseTime = time - arrivalTime;
        started = true;
    }
}

// SchedulerPriority class definitions
SchedulerPriorityNP::SchedulerPriorityNP(int n) : numProcesses(n) {
    processes = new ProcessPRInp * [numProcesses];
}

void SchedulerPriorityNP::addProcess(int index, int id, int arrival, int burst, int priority) {
    processes[index] = new ProcessPRInp(id, arrival, burst, priority);
}

void SchedulerPriorityNP::scheduleNonPreemptive() {
    sort(processes, processes + numProcesses, [](ProcessPRInp* a, ProcessPRInp* b) {
        return a->getArrivalTime() < b->getArrivalTime();
        });

    bool* completed = new bool[numProcesses] {false};
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < numProcesses) {
        int highestPriority = INT_MAX;
        int idx = -1;

        for (int i = 0; i < numProcesses; ++i) {
            if (!completed[i] && processes[i]->getArrivalTime() <= currentTime && processes[i]->getPriority() < highestPriority) {
                highestPriority = processes[i]->getPriority();
                idx = i;
            }
        }

        if (idx == -1) {
            currentTime++;
            continue;
        }

        if (processes[idx]->getResponseTime() == -1) {
            processes[idx]->setResponseTime(currentTime);
        }

        currentTime += processes[idx]->getBurstTime();

        completed[idx] = true;
        completedCount++;
        processes[idx]->setCompletionTime(currentTime);
        processes[idx]->calculateTurnaroundTime();
        processes[idx]->calculateWaitingTime();
    }

    delete[] completed;
}

void SchedulerPriorityNP::getCompletionTimes(int completionTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        completionTimes[i] = processes[i]->getCompletionTime();
    }
}

void SchedulerPriorityNP::getTurnaroundTimes(int turnaroundTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        turnaroundTimes[i] = processes[i]->getTurnaroundTime();
    }
}

void SchedulerPriorityNP::getWaitingTimes(int waitingTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        waitingTimes[i] = processes[i]->getWaitingTime();
    }
}

void SchedulerPriorityNP::getResponseTimes(int responseTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        responseTimes[i] = processes[i]->getResponseTime();
    }
}

void SchedulerPriorityNP::getProcessOrder(int processIds[]) const {
    vector<pair<int, int>> completionTimes;

    for (int i = 0; i < numProcesses; ++i) {
        completionTimes.push_back(make_pair(i, processes[i]->getCompletionTime()));
    }

    sort(completionTimes.begin(), completionTimes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });

    for (int i = 0; i < numProcesses; ++i) {
        processIds[i] = completionTimes[i].first + 1;
    }
}


int* SchedulerPriorityNP::getganttChart(int& total_time)
{
    scheduleNonPreemptive();
    int* ari = new int[numProcesses];
    int* comp = new int[numProcesses];
    total_time = 0;

    for (int i = 0; i < numProcesses; ++i)
    {
        comp[i] = processes[i]->getCompletionTime();
        ari[i] = processes[i]->getArrivalTime();
        if (processes[i]->getCompletionTime() > total_time)
        {
            total_time = processes[i]->getCompletionTime();
        }
    }

    int* timeline = new int[total_time]();
    int* orderProc = new int[numProcesses];
    getProcessOrder(orderProc);

    int currentTime = 0;

    for (int i = 0; i < numProcesses; i++)
    {
        int x = orderProc[i];

        if (ari[x - 1] > currentTime)
        {
            currentTime = ari[x - 1];
        }

        int burstTime = processes[x - 1]->getBurstTime();
        for (int j = 0; j < burstTime; j++)
        {
            timeline[currentTime++] = x;
        }
    }

    delete[] orderProc;
    delete[] ari;
    delete[] comp;
    return timeline;
}

SchedulerPriorityNP::~SchedulerPriorityNP() {
    for (int i = 0; i < numProcesses; ++i) {
        delete processes[i];
    }
    delete[] processes;
}
