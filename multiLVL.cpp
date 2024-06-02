#include "multiLVL.h"

process::process()
    : id(0), arrivalTime(0), burstTime(0), completionTime(0), turnaroundTime(0), waitingTime(0), remainingTime(0), nextArrivalTime(0)
{
}

int findMIN(std::list<process*>& q) {
    int min = INT_MAX;
    for (std::list<process*>::iterator it1 = q.begin(); it1 != q.end(); it1++) {
        if (min > (*it1)->nextArrivalTime) {
            min = (*it1)->nextArrivalTime;
        }
    }
    return min;
}

void qrun(std::list<process*>& q, int quantum, int& currentTime, std::list<process*>& nextQueue) {
    while (!q.empty())
    {
        std::list<process*>::iterator it1;
        for (it1 = q.begin(); it1 != q.end(); it1++) {
            if ((*it1)->nextArrivalTime == findMIN(q)) {
                break;
            }
        }

        process* p = *it1;
        q.erase(it1);

        if (currentTime < p->nextArrivalTime) {
            currentTime = p->nextArrivalTime;
        }

        if (p->remainingTime > quantum) {
            currentTime += quantum;
            p->remainingTime -= quantum;
            p->nextArrivalTime = currentTime;
            nextQueue.push_back(p);
        }
        else {
            currentTime += p->remainingTime;
            p->completionTime = currentTime;
            p->remainingTime = 0;
        }
    }
}

void executeFCFS(std::list<process*>& q, int& currentTime) {
    while (!q.empty()) {
        std::list<process*>::iterator it1;
        for (it1 = q.begin(); it1 != q.end(); it1++) {
            if ((*it1)->nextArrivalTime == findMIN(q)) {
                break;
            }
        }

        process* p = *it1;
        q.erase(it1);

        if (currentTime < p->nextArrivalTime) {
            currentTime = p->nextArrivalTime;
        }

        currentTime += p->remainingTime;
        p->completionTime = currentTime;
        p->remainingTime = 0;
    }
}

void getCompletionTimes(process* processes, int n, int* completionTimes) {
    for (int i = 0; i < n; ++i) {
        completionTimes[i] = processes[i].completionTime;
    }
}

void getTurnaroundTimes(process* processes, int n, int* turnaroundTimes) {
    for (int i = 0; i < n; ++i) {
        turnaroundTimes[i] = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = turnaroundTimes[i];
    }
}

void getWaitingTimes(process* processes, int n, int* waitingTimes) {
    for (int i = 0; i < n; ++i) {
        waitingTimes[i] = processes[i].turnaroundTime - processes[i].burstTime;
        processes[i].waitingTime = waitingTimes[i];
    }
}

void getResponseTimes(process* processes, int n, int* responseTimes) {
    for (int i = 0; i < n; ++i) {
        responseTimes[i] = processes[i].waitingTime;
    }
}

void calculateTimes(process* processes, int n) {
    for (int i = 0; i < n; ++i) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

void printTable(process* processes, int n) {
    std::cout << "------------------------------------------------------------------------------------------\n";
    std::cout << "| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n";
    std::cout << "------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "|     " << processes[i].id << "     |     " << processes[i].arrivalTime << "     |     "
            << processes[i].burstTime << "     |     " << processes[i].completionTime << "     |     "
            << processes[i].turnaroundTime << "     |     " << processes[i].waitingTime << "     |\n";
    }
    std::cout << "------------------------------------------------------------------------------------------\n";
}

void addProcess(process* processes, std::list<process*>& q1, int id, int arrivalTime, int burstTime) {
    processes[id - 1].id = id;
    processes[id - 1].arrivalTime = arrivalTime;
    processes[id - 1].burstTime = burstTime;
    processes[id - 1].remainingTime = burstTime;
    processes[id - 1].nextArrivalTime = arrivalTime;
    q1.push_back(&processes[id - 1]);
}

void getProcessOrder(process* processes, int n, int* process_id) {
    for (int i = 0; i < n; ++i) {
        process_id[i] = processes[i].id;
    }

    std::sort(process_id, process_id + n, [&processes](int a, int b) {
        return processes[a - 1].completionTime < processes[b - 1].completionTime;
        });
}

int getTotalTime(process* processes, int n)
{
    int total_time = 0;
    for (int i = 0; i < n; ++i) {
        total_time = std::max(total_time, processes[i].completionTime);
    }
    return total_time;
}

///////////////////

int* recordProcessExecutionQueue(int currentTime, int quantum, int& total_time, std::list<process*>& q, std::list<process*>& q2)
{

    int* timeline = new int[total_time] {0};

    while (!q.empty())
    {
        std::list<process*>::iterator it1;
        for (it1 = q.begin(); it1 != q.end(); it1++) {
            if ((*it1)->nextArrivalTime == findMIN(q)) {
                break;
            }
        }

        process* p = *it1;
        q.erase(it1);

        if (currentTime < p->nextArrivalTime)
        {
            currentTime = p->nextArrivalTime;
        }

        if (p->remainingTime > quantum)
        {
            int temp = currentTime + quantum;
            for (int i = currentTime; i < temp; i++)
            {
                timeline[i] = p->id;
            }
            currentTime += quantum;
            p->remainingTime -= quantum;
            p->nextArrivalTime = currentTime;
            q2.push_back(p);

        }
        else
        {
            int temp = currentTime + p->remainingTime;

            for (int i = currentTime; i < temp; i++)
            {
                timeline[i] = p->id;
            }
            currentTime += p->remainingTime;
            p->completionTime = currentTime;
            p->remainingTime = 0;
        }
    }

    return timeline;
}

int* recordProcessExecutionQueue3(int currentTime, int& total_time, std::list<process*>& q)
{
    int* timeline = new int[total_time] {0};

    while (!q.empty())
    {
        std::list<process*>::iterator it1;
        for (it1 = q.begin(); it1 != q.end(); it1++)
        {
            if ((*it1)->nextArrivalTime == findMIN(q))
            {
                break;
            }
        }

        process* p = *it1;
        q.erase(it1);

        if (currentTime < p->nextArrivalTime)
        {
            currentTime = p->nextArrivalTime;
        }

        int temp = currentTime + p->remainingTime;

        for (int i = currentTime; i < temp; i++)
        {
            timeline[i] = p->id;
        }

        currentTime += p->remainingTime;
        p->completionTime = currentTime;
        p->remainingTime = 0;
    }

    return timeline;
}
