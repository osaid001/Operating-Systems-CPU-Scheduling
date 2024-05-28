#include "FCFS.h"
#include "processFCFS.h"
#include <iostream>

using namespace std;

scheduler::scheduler() : head(nullptr), num_processes(0) {}

void scheduler::addProcess(int pid, int arrival, int burst) {
    processfcfs* new_process = new processfcfs(pid, arrival, burst);
    if (head == nullptr) {
        head = new_process;
    }
    else {
        processfcfs* current = head;
        while (current->getnext() != nullptr) {
            current = current->getnext();
        }
        current->setnext(new_process);
    }
    num_processes++;
}

void scheduler::calcCompletionTime() {
    processfcfs* current = head;
    int current_time = 0;
    while (current != nullptr) {
        if (current_time < current->get_Arrival_Time()) {
            current_time = current->get_Arrival_Time();
        }
        current->set_Completion_Time(current_time + current->get_Burst_Time());
        current_time = current->get_Completion_Time();
        current = current->getnext();
    }
}

void scheduler::calcTurnAroundAndWaitingTime() {
    processfcfs* current = head;
    while (current != nullptr) {
        current->calculateTurnAroundTime();
        current->calculateWaitingTime();
        current = current->getnext();
    }
}

void scheduler::getCompletionTimes(int* completion_times) {
    processfcfs* current = head;
    int i = 0;
    while (current != nullptr) {
        completion_times[i++] = current->get_Completion_Time();
        current = current->getnext();
    }
}

void scheduler::getTurnAroundTimes(int* turnaround_times) {
    processfcfs* current = head;
    int i = 0;
    while (current != nullptr) {
        turnaround_times[i++] = current->get_Turn_Around_Time();
        current = current->getnext();
    }
}

void scheduler::getWaitingTimes(int* waiting_times) {
    processfcfs* current = head;
    int i = 0;
    while (current != nullptr) {
        waiting_times[i++] = current->get_Waiting_Time();
        current = current->getnext();
    }
}

void scheduler::getProcessIdsInCompletionOrder(int* process_ids) {
    processfcfs* current = head;
    int i = 0;
    while (current != nullptr) {
        process_ids[i++] = current->get_Process_Id();
        current = current->getnext();
    }
}

scheduler::~scheduler() {
    processfcfs* current = head;
    while (current != nullptr) {
        processfcfs* temp = current;
        current = current->getnext();
        delete temp;
    }
}



processfcfs::processfcfs(int pid, int arrival, int burst)
    : Process_Id(pid), Arrival_Time(arrival), Burst_Time(burst), next(nullptr) {}

void processfcfs::setnext(processfcfs* nxt) {
    next = nxt;
}

processfcfs* processfcfs::getnext() {
    return next;
}

void processfcfs::set_Completion_Time(int time) {
    Completion_Time = time;
}

int processfcfs::get_Completion_Time() {
    return Completion_Time;
}

int processfcfs::get_Burst_Time() {
    return Burst_Time;
}

int processfcfs::get_Process_Id() {
    return Process_Id;
}

void processfcfs::calculateTurnAroundTime() {
    Turn_Around_Time = Completion_Time - Arrival_Time;
}

void processfcfs::calculateWaitingTime() {
    Waiting_Time = Turn_Around_Time - Burst_Time;
}

int processfcfs::get_Turn_Around_Time() {
    return Turn_Around_Time;
}

int processfcfs::get_Waiting_Time() {
    return Waiting_Time;
}

int processfcfs::get_Arrival_Time() {
    return Arrival_Time;
}
