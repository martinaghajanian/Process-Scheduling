#ifndef PROCESS_SCHEDULING_H
#define PROCESS_SCHEDULING_H

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
} Process;

void fcfs(Process processes[], int n);
void sjf(Process processes[], int n);
void print_gantt_chart(Process processes[], int n);

#endif
