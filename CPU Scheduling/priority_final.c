// C program for implementation of Priority Scheduling

/*

DOCUMENTATION : What is this code doing ???

We have num_processes, which stores number of processes
        burst_time, which stores their burst times, both of them are arrays
        
we have to find the average waiting time and 
                    average turn around time using Priority Scheduling
                    
We assume arrival time is zero                   
                    

########### ALGORITHM ############
1. Input Processes with their Burst Time and Priority

2. Sort all processes, burst time in the increasing order of their priority

3. Find waiting time for all processes
    for first process waiting time is zero
        wt[0] = 0
    for others
        wt[i] = bt[i-1] + wt[i-1]

4. Find turn around time for all processes
        turn around time = waiting time + burst time
        
5. Find average time and average turn around time
        average time = total wait time / number of processes
        turn around time = total turn around time / number of processes

6. Print avrage time and turn around time
##################################

Feel free to modify according to your needs :)

*/

#include<stdio.h>

int main()
{
	int num_pr, swap_var, pos;
	int process[32], burst_time[32], priority[32];
	int wait_time[32], turn_around_time[32];
	float total_wt = 0, total_tat = 0;
	float avg_wt_time, avg_ta_time;

	printf("Enter the number of process : ");
	scanf("%d", &num_pr);

	printf("Enter the burst time and priority of the processes\n");

	for (int i = 0; i < num_pr; ++i)
	{
		printf("Burst Time P%d : ", i+1);
		scanf("%d", &burst_time[i]);
		printf("Priority   P%d : ", i+1);
		scanf("%d", &priority[i]);
		printf("\n");
		process[i] = i+1;
	}

	// selection sort
	for(int i=0; i<num_pr; i++)
    {
        pos=i;
        for(int j=i+1; j<num_pr; j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
 
        swap_var=priority[i];
        priority[i]=priority[pos];
        priority[pos]=swap_var;
 
        swap_var=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=swap_var;
 
        swap_var=process[i];
        process[i]=process[pos];
        process[pos]=swap_var;
    }

	printf("process | burst_time | waiting_time | turn_around_time\n"); 

	// finding waiting time
	wait_time[0] = 0;
	for (int i = 1; i < num_pr; ++i)
		wait_time[i] = burst_time[i-1] + wait_time[i-1];

	// finding turn around time
	for (int i=0; i<num_pr; i++) 
		turn_around_time[i] = burst_time[i] + wait_time[i];

	// finding total and average times
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

	return 0;
}