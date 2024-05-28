#include "SJFnp.h"
#include <climits>
#include <cstring>

SchedulerSJF::SchedulerSJF(int n) : numProcesses(n) {
    processes = new ProcessSJ * [numProcesses];
}

void SchedulerSJF::addProcess(int index, string pid, int arrival, int burst) {
    processes[index] = new ProcessSJ(pid, arrival, burst);
}

void SchedulerSJF::schedule() {
    bool* completed = new bool[numProcesses];
    memset(completed, false, sizeof(bool) * numProcesses);
    int* processOrder = new int[numProcesses];
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < numProcesses) {
        int idx = -1;
        int shortestBurst = INT_MAX;

        for (int i = 0; i < numProcesses; ++i) {
            if (!completed[i] && processes[i]->getArrivalTime() <= currentTime && processes[i]->getBurstTime() < shortestBurst) {
                shortestBurst = processes[i]->getBurstTime();
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx]->setResponseTime(currentTime);
            currentTime += processes[idx]->getBurstTime();
            processes[idx]->setCompletionTime(currentTime);
            processes[idx]->calculateTurnAroundTime();
            processes[idx]->calculateWaitingTime();
            completed[idx] = true;
            processOrder[completedCount++] = idx;
        }
        else {
            currentTime++;
        }
    }

    ProcessSJ** orderedProcesses = new ProcessSJ * [numProcesses];
    for (int i = 0; i < numProcesses; ++i) {
        orderedProcesses[i] = processes[processOrder[i]];
    }
    delete[] processes;
    processes = orderedProcesses;

    delete[] processOrder;
    delete[] completed;
}

void SchedulerSJF::getCompletionTimes(int* completionTimes) {
    for (int i = 0; i < numProcesses; ++i) {
        completionTimes[i] = processes[i]->getCompletionTime();
    }
}

void SchedulerSJF::getTurnAroundTimes(int* turnAroundTimes) {
    for (int i = 0; i < numProcesses; ++i) {
        turnAroundTimes[i] = processes[i]->getTurnAroundTime();
    }
}

void SchedulerSJF::getWaitingTimes(int* waitingTimes) {
    for (int i = 0; i < numProcesses; ++i) {
        waitingTimes[i] = processes[i]->getWaitingTime();
    }
}

void SchedulerSJF::getResponseTimes(int* responseTimes) {
    for (int i = 0; i < numProcesses; ++i) {
        responseTimes[i] = processes[i]->getResponseTime();
    }
}

void SchedulerSJF::getProcessOrder(string* processIds) {
    for (int i = 0; i < numProcesses; ++i) {
        processIds[i] = processes[i]->getProcessId();
    }
}

SchedulerSJF::~SchedulerSJF() {
    for (int i = 0; i < numProcesses; ++i)
    {
        delete processes[i];
    }
    delete[] processes;
}
