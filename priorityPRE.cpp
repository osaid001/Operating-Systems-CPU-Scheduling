#include "priorityPRE.h"
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

ProcessPRIpre::ProcessPRIpre(int id, int arrival, int burst, int priority)
    : id(id), arrivalTime(arrival), burstTime(burst), priority(priority),
    waitingTime(0), responseTime(-1), completionTime(0), turnaroundTime(0),
    remainingTime(burst), started(false) {}

int ProcessPRIpre::getArrivalTime() const { return arrivalTime; }
int ProcessPRIpre::getBurstTime() const { return burstTime; }
int ProcessPRIpre::getPriority() const { return priority; }
int ProcessPRIpre::getRemainingTime() const { return remainingTime; }
int ProcessPRIpre::getCompletionTime() const { return completionTime; }
int ProcessPRIpre::getTurnaroundTime() const { return turnaroundTime; }
int ProcessPRIpre::getWaitingTime() const { return waitingTime; }
int ProcessPRIpre::getResponseTime() const { return responseTime; }
int ProcessPRIpre::getId() const { return id; }

void ProcessPRIpre::setCompletionTime(int time) { completionTime = time; }
void ProcessPRIpre::setRemainingTime(int time) { remainingTime = time; }
void ProcessPRIpre::calculateTurnaroundTime() { turnaroundTime = completionTime - arrivalTime; }
void ProcessPRIpre::calculateWaitingTime() { waitingTime = turnaroundTime - burstTime; }
void ProcessPRIpre::setResponseTime(int time) {
    if (!started) {
        responseTime = time - arrivalTime;
        started = true;
    }
}

// SchedulerPriority class definitions
SchedulerPriority::SchedulerPriority(int n) : numProcesses(n) {
    processes = new ProcessPRIpre * [numProcesses];
}

void SchedulerPriority::addProcess(int index, int id, int arrival, int burst, int priority) {
    processes[index] = new ProcessPRIpre(id, arrival, burst, priority);
}

void SchedulerPriority::schedulePreemptive() {
    sort(processes, processes + numProcesses, [](ProcessPRIpre* a, ProcessPRIpre* b) {
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

        processes[idx]->setRemainingTime(processes[idx]->getRemainingTime() - 1);
        currentTime++;

        if (processes[idx]->getRemainingTime() == 0) {
            completed[idx] = true;
            completedCount++;
            processes[idx]->setCompletionTime(currentTime);
            processes[idx]->calculateTurnaroundTime();
            processes[idx]->calculateWaitingTime();
        }
    }

    delete[] completed;
}

void SchedulerPriority::getCompletionTimes(int completionTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        completionTimes[i] = processes[i]->getCompletionTime();
    }
}

void SchedulerPriority::getTurnaroundTimes(int turnaroundTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        turnaroundTimes[i] = processes[i]->getTurnaroundTime();
    }
}

void SchedulerPriority::getWaitingTimes(int waitingTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        waitingTimes[i] = processes[i]->getWaitingTime();
    }
}

void SchedulerPriority::getResponseTimes(int responseTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        responseTimes[i] = processes[i]->getResponseTime();
    }
}

void SchedulerPriority::getProcessOrder(int processIds[]) const {
    vector<pair<int, int>> completionOrder;

    for (int i = 0; i < numProcesses; ++i) {
        completionOrder.push_back(make_pair(processes[i]->getCompletionTime(), processes[i]->getId()));
    }

    sort(completionOrder.begin(), completionOrder.end());

    for (int i = 0; i < numProcesses; ++i) {
        processIds[i] = completionOrder[i].second;
    }
}


SchedulerPriority::~SchedulerPriority() {
    for (int i = 0; i < numProcesses; ++i) {
        delete processes[i];
    }
    delete[] processes;
}

int* SchedulerPriority::recordProcessExecution(int& total_time)
{
    // Run the preemptive priority scheduling to calculate the completion times
    //schedulePreemptive();

    // Determine the total time from the maximum completion time of the processes
    total_time = 0;
    for (int i = 0; i < numProcesses; ++i) {
        if (processes[i]->getCompletionTime() > total_time) {
            total_time = processes[i]->getCompletionTime();
        }
    }

    // Allocate the timeline array
    int* timeline = new int[total_time]();

    // Initialize remaining times for each process
    int* remainingTimes = new int[numProcesses];
    for (int i = 0; i < numProcesses; ++i) {
        remainingTimes[i] = processes[i]->getBurstTime();
    }

    // Track completion status of each process
    bool* completed = new bool[numProcesses]();
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < numProcesses) {
        int idx = -1;
        int highestPriority = INT_MAX;

        // Select the process with the highest priority (lowest priority value) that is ready to execute
        for (int i = 0; i < numProcesses; ++i) {
            if (!completed[i] && processes[i]->getArrivalTime() <= currentTime && processes[i]->getPriority() < highestPriority) {
                highestPriority = processes[i]->getPriority();
                idx = i;
            }
        }

        if (idx != -1) {
            if (remainingTimes[idx] == processes[idx]->getBurstTime()) {
                processes[idx]->setResponseTime(currentTime);
            }

            // Record the process ID in the timeline for the current time unit
            timeline[currentTime] = processes[idx]->getId();
            remainingTimes[idx]--;
            currentTime++;

            if (remainingTimes[idx] == 0) {
                processes[idx]->setCompletionTime(currentTime);
                processes[idx]->calculateTurnaroundTime();
                processes[idx]->calculateWaitingTime();
                completed[idx] = true;
                completedCount++;
            }
        }
        else {
            currentTime++;
        }
    }

    delete[] remainingTimes;
    delete[] completed;

    return timeline;
}
