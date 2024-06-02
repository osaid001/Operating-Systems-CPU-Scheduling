#include "SJFp.h"
#include <vector>
#include <algorithm>

ProcessSJpre::ProcessSJpre(string pid, int arrival, int burst)
    : processId(pid), arrivalTime(arrival), burstTime(burst), remainingTime(burst),
    completionTime(0), turnAroundTime(0), waitingTime(0), responseTime(0), started(false) {}

int ProcessSJpre::getArrivalTime() const { return arrivalTime; }
int ProcessSJpre::getBurstTime() const { return burstTime; }
int ProcessSJpre::getRemainingTime() const { return remainingTime; }
int ProcessSJpre::getCompletionTime() const { return completionTime; }
int ProcessSJpre::getTurnAroundTime() const { return turnAroundTime; }
int ProcessSJpre::getWaitingTime() const { return waitingTime; }
int ProcessSJpre::getResponseTime() const { return responseTime; }
string ProcessSJpre::getProcessId() const { return processId; }

void ProcessSJpre::setCompletionTime(int time) { completionTime = time; }
void ProcessSJpre::setRemainingTime(int time) { remainingTime = time; }
void ProcessSJpre::calculateTurnAroundTime() { turnAroundTime = completionTime - arrivalTime; }
void ProcessSJpre::calculateWaitingTime() { waitingTime = turnAroundTime - burstTime; }
void ProcessSJpre::setResponseTime(int time) {
    if (!started) {
        responseTime = time - arrivalTime;
        started = true;
    }
}

SchedulerSJFpre::SchedulerSJFpre(int n) : numProcesses(n) {
    processes = new ProcessSJpre * [numProcesses];
}

void SchedulerSJFpre::addProcess(int index, const string& pid, int arrival, int burst) {
    processes[index] = new ProcessSJpre(pid, arrival, burst);
}

void SchedulerSJFpre::schedule() {
    schedulePreemptive();
}

void SchedulerSJFpre::schedulePreemptive() {
    bool* completed = new bool[numProcesses]();
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < numProcesses) {
        int idx = -1;
        int shortestRemainingTime = INT_MAX;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < numProcesses; ++i) {
            if (!completed[i] && processes[i]->getArrivalTime() <= currentTime && processes[i]->getRemainingTime() < shortestRemainingTime) {
                shortestRemainingTime = processes[i]->getRemainingTime();
                idx = i;
            }
        }

        if (idx != -1) {
            // If the process is starting for the first time, set its response time
            if (processes[idx]->getRemainingTime() == processes[idx]->getBurstTime()) {
                processes[idx]->setResponseTime(currentTime);
            }

            // Execute the process for one unit of time
            processes[idx]->setRemainingTime(processes[idx]->getRemainingTime() - 1);
            currentTime++;

            // If the process finishes, update its completion status
            if (processes[idx]->getRemainingTime() == 0) {
                processes[idx]->setCompletionTime(currentTime);
                processes[idx]->calculateTurnAroundTime();
                processes[idx]->calculateWaitingTime();
                completed[idx] = true;
                completedCount++;
            }
        }
        else {
            // If no process is ready to run, increment the time
            currentTime++;
        }
    }

    delete[] completed;
}


void SchedulerSJFpre::getCompletionTimes(int completionTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        completionTimes[i] = processes[i]->getCompletionTime();
    }
}

void SchedulerSJFpre::getTurnAroundTimes(int turnAroundTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        turnAroundTimes[i] = processes[i]->getTurnAroundTime();
    }
}

void SchedulerSJFpre::getWaitingTimes(int waitingTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        waitingTimes[i] = processes[i]->getWaitingTime();
    }
}

void SchedulerSJFpre::getResponseTimes(int responseTimes[]) const {
    for (int i = 0; i < numProcesses; ++i) {
        responseTimes[i] = processes[i]->getResponseTime();
    }
}

void SchedulerSJFpre::getProcessOrder(string processIds[]) const
{
    std::vector<std::pair<int, string>> completionTimeWithId;

    for (int i = 0; i < numProcesses; ++i) {
        completionTimeWithId.push_back({ processes[i]->getCompletionTime(), processes[i]->getProcessId() });
    }

    std::sort(completionTimeWithId.begin(), completionTimeWithId.end());

    for (int i = 0; i < numProcesses; ++i) {
        processIds[i] = completionTimeWithId[i].second;
    }
}

SchedulerSJFpre::~SchedulerSJFpre() {
    for (int i = 0; i < numProcesses; ++i) {
        delete processes[i];
    }
    delete[] processes;
}

int* SchedulerSJFpre::recordProcessExecution(int& total_time)
{
    // schedule();

    total_time = 0;
    for (int i = 0; i < numProcesses; ++i) {
        if (processes[i]->getCompletionTime() > total_time) {
            total_time = processes[i]->getCompletionTime();
        }
    }

    int* timeline = new int[total_time]();

    int* remainingTimes = new int[numProcesses];
    for (int i = 0; i < numProcesses; ++i) {
        remainingTimes[i] = processes[i]->getBurstTime();
    }

    bool* completed = new bool[numProcesses]();
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < numProcesses) {
        int idx = -1;
        int shortestRemainingTime = INT_MAX;

        for (int i = 0; i < numProcesses; ++i) {
            if (!completed[i] && processes[i]->getArrivalTime() <= currentTime && remainingTimes[i] < shortestRemainingTime) {
                shortestRemainingTime = remainingTimes[i];
                idx = i;
            }
        }

        if (idx != -1) {
            if (remainingTimes[idx] == processes[idx]->getBurstTime()) {
                processes[idx]->setResponseTime(currentTime);
            }

            timeline[currentTime] = stoi(processes[idx]->getProcessId());
            remainingTimes[idx]--;
            currentTime++;

            if (remainingTimes[idx] == 0) {
                processes[idx]->setCompletionTime(currentTime);
                processes[idx]->calculateTurnAroundTime();
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
