#include<stdio.h>

int arrival_time[10], burst_time[10], priority[10], waiting_time[10], turnaround_time[10];
int temp_burst_time[10];

int main()
{
    int num_processes, time = 0, process_count = 0, shortest_priority_index;
    float total_waiting_time = 0, total_turnaround_time = 0, avg_waiting_time, avg_turnaround_time;
    
    printf("Enter the number of processes\n");
    scanf("%d", &num_processes);
    
    printf("Enter the arrival time, burst time, and priority of each process\n");
    printf("AT BT PT\n");
    for(int i=0; i<num_processes; i++)
    {
        scanf("%d%d%d", &arrival_time[i], &burst_time[i], &priority[i]);
        temp_burst_time[i] = burst_time[i];
    }
    
    priority[9] = 10000;
    
    for(time=0; process_count!=num_processes; time++)
    {
        shortest_priority_index = 9;
        
        for(int i=0; i<num_processes; i++)
        {
            if(priority[i] < priority[shortest_priority_index] && arrival_time[i] <= time && burst_time[i] > 0)
            {
                shortest_priority_index = i;
            }
        }
        
        burst_time[shortest_priority_index] = burst_time[shortest_priority_index] - 1;
        
        if(burst_time[shortest_priority_index] == 0)
        {
            process_count++;
            waiting_time[shortest_priority_index] = time + 1 - arrival_time[shortest_priority_index] - temp_burst_time[shortest_priority_index];
            turnaround_time[shortest_priority_index] = time + 1 - arrival_time[shortest_priority_index];
            
            total_waiting_time = total_waiting_time + waiting_time[shortest_priority_index];
            total_turnaround_time = total_turnaround_time + turnaround_time[shortest_priority_index];
        }
    }
    
    avg_waiting_time = total_waiting_time / num_processes;
    avg_turnaround_time = total_turnaround_time / num_processes;
    
    printf("ID WT TAT\n");
    for(int i=0; i<num_processes; i++)
    {
        printf("%d %d\t%d\n", i+1, waiting_time[i], turnaround_time[i]);
    }
    
    printf("Avg waiting time of the process is %f\n", avg_waiting_time);
    printf("Avg turn around time of the process is %f\n", avg_turnaround_time);
    
    return 0;
}
