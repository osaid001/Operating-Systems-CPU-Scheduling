#include "SJFnp.h"
#include <climits>
#include <cstring>
#include <algorithm>

SchedulerSJF::SchedulerSJF(int n) : numProcesses(n)
{
    processes = new ProcessSJ * [numProcesses];
}

void SchedulerSJF::addProcess(int index, string pid, int arrival, int burst) {
    processes[index] = new ProcessSJ(pid, arrival, burst);
}

void SchedulerSJF::schedule() {
    bool* completed = new bool[numProcesses];
    memset(completed, false, sizeof(bool) * numProcesses);
    int currentTime = 0;
    int completedCount = 0;
    int* processOrder = new int[numProcesses];

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

    for (int i = 0; i < numProcesses; ++i) {
        processes[i]->setOrderOfExecution(processOrder[i]);
    }

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
    int* order = new int[numProcesses];
    for (int i = 0; i < numProcesses; ++i) {
        order[i] = processes[i]->getOrderOfExecution();
    }
    for (int i = 0; i < numProcesses; ++i) {
        processIds[i] = processes[order[i]]->getProcessId();
    }
    delete[] order;
}

int* SchedulerSJF::recordProcessExecution(int& total_time)
{
    schedule();
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
    string* order = new string[numProcesses];
    getProcessOrder(order);

    int* orderProc = new int[numProcesses];
    for (int i = 0; i < numProcesses; ++i)
    {
        orderProc[i] = stoi(order[i]);
    }
    delete[] order;

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

SchedulerSJF::~SchedulerSJF() {
    for (int i = 0; i < numProcesses; ++i)
    {
        delete processes[i];
    }
    delete[] processes;
}
