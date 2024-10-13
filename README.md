# Process Scheduling Simulation (FCFS & SJF)

## Files

1. **process_scheduling.h**  
   Contains the `Process` structure and function prototypes for both scheduling algorithms (FCFS and SJF).

2. **process_scheduling.c**  
   Implements the FCFS and SJF algorithms, calculates waiting, turnaround, and response times, and prints the Gantt chart.

## How to Run

1. **Compile the code**  
   Run the following command in your terminal:
   ```bash
   gcc process_scheduling.c -o process_scheduling
   ```

2. **Execute the program**  
   After compiling, run the program with:
   ```bash
   ./process_scheduling
   ```

3. **Input**  
   Enter the number of processes and provide their arrival times and burst times as prompted.

The program will display the Gantt charts, and process details for both FCFS and SJF algorithms.
