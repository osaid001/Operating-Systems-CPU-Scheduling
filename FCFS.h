#pragma once

#include "processFCFS.h"

class scheduler {
private:
    processfcfs* head;
    int num_processes;

public:
    scheduler();
    void addProcess(int pid, int arrival, int burst);
    void calcCompletionTime();
    void calcTurnAroundAndWaitingTime();

    void getCompletionTimes(int* completion_times);
    void getTurnAroundTimes(int* turnaround_times);
    void getWaitingTimes(int* waiting_times);
    void getProcessIdsInCompletionOrder(int* process_ids);

    ~scheduler();
};
