#pragma once

class processfcfs {
private:
    int Process_Id;
    int Arrival_Time;
    int Burst_Time;
    int Completion_Time;
    int Turn_Around_Time;
    int Waiting_Time;
    processfcfs* next;

public:
    processfcfs(int pid, int arrival, int burst);

    void setnext(processfcfs* nxt);
    processfcfs* getnext();

    void set_Completion_Time(int time);
    int get_Completion_Time();

    int get_Burst_Time();
    int get_Process_Id();

    void calculateTurnAroundTime();
    void calculateWaitingTime();

    int get_Turn_Around_Time();
    int get_Waiting_Time();
    int get_Arrival_Time();
};
