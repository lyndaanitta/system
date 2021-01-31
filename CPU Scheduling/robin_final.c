// C program for implementation of Round Robin

/*

DOCUMENTATION : What is this code doing ???

We have num_processes, which stores number of processes
        burst_time, which stores their burst times, both of them are arrays
        
we have to find the average waiting time and 
                    average turn around time using Round Robin
                    
We assume arrival time is zero                   
                    

########### ALGORITHM ############
1. Enter process and their burst times

2. Copy Burst time array to remaining_burst_time array

3. Enter quantum time

4. Repeat 5 until num_process == count, where count is process tracker

5. In a loop,
		5.1 if remaining_burst_time == 0
				increment count to 1
		5.2 if remaining_burst_time > quantum_time
				remaining_burst_time = remaining_burst_time - quantum_time
			else
			    if remaining_burst_time >= 0
						store remaining_burst_time in temp
						remaining_burst_time = 0;

				temp2 = temp + remaining_burst_time
				turn_around_time = temp2

6. Find total waiting time and total turn around time

7. Print average waiting time and average turn around time

##################################

Feel free to modify according to your needs :)

*/

#include<stdio.h>

int main()
{
	int num_pr, i, temp, sq = 0, swap_var;
	int quantum_time, count = 0;
	int burst_time[32], wait_time[32], process[32];
	int turn_around_time[32], rem_burst_time[32];
	float avg_wt = 0, avg_tat = 0;

	printf("Enter No Of Process : ");
	scanf("%d", &num_pr);

	for (int i = 0; i < num_pr; ++i)
	{
		printf("Burst Time P%d : ", i+1);
		scanf("%d", &burst_time[i]);
		printf("\n");
		rem_burst_time[i] = burst_time[i];
		process[i] = i+1;
	}

	printf("Enter Quantum Time : ");
	scanf("%d", &quantum_time);

	while(1==1)
	{
		// count --> if a process completely executes count++
		for(i=0, count=0; i<num_pr; i++)
		{
			temp = quantum_time;
			if (rem_burst_time[i] == 0)
			{
				count++;
				continue;
			}

			if (rem_burst_time[i] > quantum_time)
				rem_burst_time[i] = rem_burst_time[i] - quantum_time;
			else
				if(rem_burst_time[i] >= 0)
				{
					temp = rem_burst_time[i];
					rem_burst_time[i] = 0;
				}
				sq = sq + temp;
				turn_around_time[i] = sq;
		}

		if (num_pr == count)
			break;
	}

	printf("process | burst_time | waiting_time | turn_around_time\n"); 

	for(i=0; i<num_pr; i++)
	{
		wait_time[i] = turn_around_time[i] - burst_time[i];
		avg_wt += wait_time[i];
		avg_tat += turn_around_time[i];

		printf("\n%d\t%d\t\t%d\t\t%d", i+1, burst_time[i], wait_time[i], turn_around_time[i]);
	}

	avg_wt /= num_pr;
	avg_tat /= num_pr;

	printf("\nAverage waiting time = %0.4f", avg_wt); 
	printf("\n"); 
	printf("Average turn around time = %0.4f \n", avg_tat); 

	// gantt chart sorting
	for (int i = 0; i < num_pr; ++i)
	{
		for (int j = 0; j < num_pr-i-1; ++j)
		{
			if(turn_around_time[j] > turn_around_time[j+1])
			{
				swap_var = turn_around_time[j];
				turn_around_time[j] = turn_around_time[j+1];
				turn_around_time[j+1] = swap_var;

				swap_var = process[j];
				process[j] = process[j+1];
				process[j+1] = swap_var;				
			}
		}
	}

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