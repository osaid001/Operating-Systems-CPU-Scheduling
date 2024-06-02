#include "FCFS.h"

#include <iostream>
#include <vector>

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

int* scheduler::getProcessRunningTimeline(int& total_time) {
    if (head == nullptr) {
        total_time = 0;
        return nullptr;
    }

    calcCompletionTime();

    processfcfs* current = head;
    int last_completion_time = 0;

    while (current != nullptr) {
        last_completion_time = std::max(last_completion_time, current->get_Completion_Time());
        current = current->getnext();
    }
    total_time = last_completion_time;

    int* timeline = new int[total_time]();

    current = head;
    while (current != nullptr) {
        int start_time = std::max(current->get_Arrival_Time(), current->get_Completion_Time() - current->get_Burst_Time());
        int end_time = current->get_Completion_Time();
        for (int t = start_time; t < end_time; ++t) {
            timeline[t] = current->get_Process_Id();
        }
        current = current->getnext();
    }

    return timeline;
}


int scheduler::get_Arrival_Time(int pid) {
    processfcfs* process = findProcessById(pid);
    return process ? process->get_Arrival_Time() : -1; // Return -1 if process not found
}

int scheduler::get_Burst_Time(int pid) {
    processfcfs* process = findProcessById(pid);
    return process ? process->get_Burst_Time() : -1; // Return -1 if process not found
}

processfcfs* scheduler::findProcessById(int pid) {
    processfcfs* current = head;
    while (current != nullptr) {
        if (current->get_Process_Id() == pid) {
            return current;
        }
        current = current->getnext();
    }
    return nullptr;
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
