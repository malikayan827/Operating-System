#include<stdio.h>

int arrivalTime[10], burstTime[10], waitingTime[10], turnaroundTime[10];

int main()
{
    int n, temp[10];
    int count = 0, t = 0, shortestJob;
    float totalWaitingTime = 0, totalTurnaroundTime = 0, avgWaitingTime, avgTurnaroundTime;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time of the processes:\n");
    printf("AT BT\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &arrivalTime[i], &burstTime[i]);
        temp[i] = burstTime[i];
    }

    burstTime[9] = 10000;

    for(t = 0; count != n; t++)
    {
        shortestJob = 9;

        for(int i = 0; i < n; i++)
        {
            if(burstTime[i] < burstTime[shortestJob] && (arrivalTime[i] <= t && burstTime[i] > 0))
            {
                shortestJob = i;
            }
        }

        burstTime[shortestJob] = burstTime[shortestJob] - 1;

        if(burstTime[shortestJob] == 0)
        {
            count++;

            waitingTime[shortestJob] = t + 1 - arrivalTime[shortestJob] - temp[shortestJob];
            turnaroundTime[shortestJob] = t + 1 - arrivalTime[shortestJob];

            // Total calculation
            totalWaitingTime += waitingTime[shortestJob];
            totalTurnaroundTime += turnaroundTime[shortestJob];
        }
    }

    avgWaitingTime = totalWaitingTime / n;
    avgTurnaroundTime = totalTurnaroundTime / n;

    printf("Process WT TAT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, waitingTime[i], turnaroundTime[i]);
    }

    printf("Average waiting time: %f\n", avgWaitingTime);
    printf("Average turnaround time: %f\n", avgTurnaroundTime);
}
