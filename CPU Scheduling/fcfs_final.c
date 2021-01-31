// C program for implementation of FCFS

/*

DOCUMENTATION : What is this code doing ???

We have num_processes, which stores number of processes
        burst_time, which stores their burst times, both of them are arrays
        
we have to find the average waiting time and 
                    average turn around time using FCFS
                    
We assume arrival time is zero                   
                    

########### ALGORITHM ############
1. Input Processes and their Burst Time

2. Find waiting time for all processes
    for first process waiting time is zero
        wt[0] = 0
    for others
        wt[i] = bt[i-1] + wt[i-1]

3. Find turn around time for all processes
        turn around time = waiting time + burst time
        
4. Find average time and average turn around time
        average time = total wait time / number of processes
        turn around time = total turn around time / number of processes

5. Print avrage time and turn around time
##################################

Feel free to modify according to your needs :)

*/


#include<stdio.h>

int main()
{
	int num_pr;
	int process[32], burst_time[32];
	int wait_time[32], turn_around_time[32];
	float total_wt = 0, total_tat = 0;
	float avg_wt_time, avg_ta_time;

	printf("Enter the number of process : \n");
	scanf("%d", &num_pr);
	printf("\n");

	printf("Enter the burst times of the processes\n");

	for (int i = 0; i < num_pr; ++i)
	{
		printf("P%d: ", i+1);
		scanf("%d", &burst_time[i]);
		process[i] = i+1;
	}

	printf("process | burst_time | waiting_time | turn_around_time\n"); 

	// finding wait time
	wait_time[0] = 0;
	for (int i = 1; i < num_pr; ++i)
		wait_time[i] = burst_time[i-1] + wait_time[i-1];

	// finding turn around time
	for (int i=0; i<num_pr; i++) 
		turn_around_time[i] = burst_time[i] + wait_time[i];

	// finding total and turn around time
	for (int i=0; i<num_pr; i++) 
	{ 
		total_wt = total_wt + wait_time[i]; 
		total_tat = total_tat + turn_around_time[i]; 

		printf("   %d ", (i+1)); 
		printf("	       %d ", burst_time[i]); 
		printf("	       %d", wait_time[i]); 
		printf("	       %d\n", turn_around_time[i]); 
	} 

	 avg_wt_time = (float)total_wt / (float)num_pr; 
	 avg_ta_time = (float)total_tat / (float)num_pr;

	printf("\nAverage waiting time = %0.4f", avg_wt_time); 
	printf("\n"); 
	printf("Average turn around time = %0.4f \n", avg_ta_time); 

	printf("\nGantt Chart\n");

	for (int i = 0; i < num_pr; ++i)
		printf("___P%d___", process[i]);

	printf("\n");

	for (int i = 0; i < num_pr+1; ++i)
		printf("|\t");

	printf("\n0\t");

	for (int i = 0; i < num_pr; ++i)
		printf(" %d \t", turn_around_time[i]);

	printf("\n");

	return 0;
}