#include "processSJFnp.h"

ProcessSJ::ProcessSJ(string pid, int arrival, int burst)
    : processId(pid), arrivalTime(arrival), burstTime(burst),
    completionTime(0), turnAroundTime(0), waitingTime(0), responseTime(0), started(false), orderOfExecution(-1) {}

int ProcessSJ::getArrivalTime() { return arrivalTime; }
int ProcessSJ::getBurstTime() { return burstTime; }
int ProcessSJ::getCompletionTime() { return completionTime; }
int ProcessSJ::getTurnAroundTime() { return turnAroundTime; }
int ProcessSJ::getWaitingTime() { return waitingTime; }
int ProcessSJ::getResponseTime() { return responseTime; }
string ProcessSJ::getProcessId() { return processId; }
int ProcessSJ::getOrderOfExecution() { return orderOfExecution; }

void ProcessSJ::setCompletionTime(int time) { completionTime = time; }
void ProcessSJ::calculateTurnAroundTime() { turnAroundTime = completionTime - arrivalTime; }
void ProcessSJ::calculateWaitingTime() { waitingTime = turnAroundTime - burstTime; }
void ProcessSJ::setResponseTime(int time) {
    if (!started) {
        responseTime = time - arrivalTime;
        started = true;
    }
}
void ProcessSJ::setOrderOfExecution(int order) { orderOfExecution = order; }
