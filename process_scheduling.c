#include <stdio.h>
#include "process_scheduling.h"

void fcfs(Process processes[], int n) {
    int current_time = 0;
    double total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].response_time = current_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].response_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        
        current_time += processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
    }

    printf("=== First Come First Served (FCFS) ===\n");
    print_gantt_chart(processes, n);
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time,
               processes[i].response_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Response Time: %.2f\n\n", total_response_time / n);
}

void sjf(Process processes[], int n) {
    int completed = 0, current_time = 0, min_index;
    double total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;
    int is_completed[n];

    for (int i = 0; i < n; i++) is_completed[i] = 0;

    while (completed < n) {
        min_index = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !is_completed[i]) {
                if (min_index == -1 || processes[i].burst_time < processes[min_index].burst_time) {
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {
            current_time++;
        } else {
            processes[min_index].response_time = current_time - processes[min_index].arrival_time;
            processes[min_index].waiting_time = processes[min_index].response_time;
            processes[min_index].turnaround_time = processes[min_index].burst_time + processes[min_index].waiting_time;
            current_time += processes[min_index].burst_time;
            is_completed[min_index] = 1;
            completed++;

            total_waiting_time += processes[min_index].waiting_time;
            total_turnaround_time += processes[min_index].turnaround_time;
            total_response_time += processes[min_index].response_time;
        }
    }

    printf("=== Shortest Job First (SJF) ===\n");
    print_gantt_chart(processes, n);
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time,
               processes[i].response_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Response Time: %.2f\n\n", total_response_time / n);
}

void print_gantt_chart(Process processes[], int n) {
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].pid);
    }
    printf("|\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    fcfs(processes, n);
    sjf(processes, n);

    return 0;
}
