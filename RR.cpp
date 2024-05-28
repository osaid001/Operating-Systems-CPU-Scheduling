#include "RR.h"

SchedulerRR::SchedulerRR(int n, int q) : numProcesses(n), quantum(q) {
    processes = new Processrr[numProcesses];
    processOrder = new int[numProcesses];
}

void SchedulerRR::addProcess(int index, string pid, int arrival, int burst) {
    processes[index].id = pid;
    processes[index].arrivalTime = arrival;
    processes[index].burstTime = burst;
    processes[index].completionTime = 0;
    processes[index].turnaroundTime = 0;
    processes[index].waitingTime = 0;
    processes[index].responseTime = 0;
}

void SchedulerRR::schedule() {
    int* remainingTime = new int[numProcesses];
    bool* firstResponse = new bool[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        remainingTime[i] = processes[i].burstTime;
        firstResponse[i] = true;
    }

    int currentTime = 0;
    int completedCount = 0;
    bool allDone = false;

    while (!allDone) {
        allDone = true;
        for (int i = 0; i < numProcesses; i++) {
            if (remainingTime[i] > 0) {
                if (processes[i].arrivalTime <= currentTime) {
                    allDone = false;

                    if (firstResponse[i]) {
                        processes[i].responseTime = currentTime - processes[i].arrivalTime;
                        firstResponse[i] = false;
                    }

                    if (remainingTime[i] > quantum) {
                        currentTime += quantum;
                        remainingTime[i] -= quantum;
                    }
                    else {
                        currentTime += remainingTime[i];
                        processes[i].completionTime = currentTime;
                        remainingTime[i] = 0;
                        processOrder[completedCount++] = i;
                    }
                }
            }
        }

        if (allDone) {
            int minArrival = INT_MAX;
            for (int i = 0; i < numProcesses; i++) {
                if (remainingTime[i] > 0 && processes[i].arrivalTime > currentTime) {
                    minArrival = min(minArrival, processes[i].arrivalTime);
                }
            }
            if (minArrival != INT_MAX) {
                currentTime = minArrival;
                allDone = false;
            }
        }
    }

    delete[] remainingTime;
    delete[] firstResponse;

    calculateTurnaroundTime();
    calculateWaitingTime();
}

void SchedulerRR::calculateTurnaroundTime() {
    for (int i = 0; i < numProcesses; i++) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
    }
}

void SchedulerRR::calculateWaitingTime() {
    for (int i = 0; i < numProcesses; i++) {
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

void SchedulerRR::getCompletionTimes(int* completionTimes) {
    for (int i = 0; i < numProcesses; i++) {
        completionTimes[i] = processes[i].completionTime;
    }
}

void SchedulerRR::getTurnAroundTimes(int* turnAroundTimes) {
    for (int i = 0; i < numProcesses; i++) {
        turnAroundTimes[i] = processes[i].turnaroundTime;
    }
}

void SchedulerRR::getWaitingTimes(int* waitingTimes) {
    for (int i = 0; i < numProcesses; i++) {
        waitingTimes[i] = processes[i].waitingTime;
    }
}

void SchedulerRR::getResponseTimes(int* responseTimes) {
    for (int i = 0; i < numProcesses; i++) {
        responseTimes[i] = processes[i].responseTime;
    }
}

void SchedulerRR::getProcessOrder(string* processIds) {
    for (int i = 0; i < numProcesses; i++) {
        processIds[i] = processes[processOrder[i]].id;
    }
}

SchedulerRR::~SchedulerRR() {
    delete[] processes;
    delete[] processOrder;
}
