#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
             int locreq[100],n,head,i,j,k,seek=0,temp;


             printf("\n\n*** FCFS Disk Scheduling Algorithm ***\n\n");
             printf("Enter the no of process requests\t:");
             scanf("%d",&n);

             for(i=1;i<=n;i++)
             {
                          printf("Enter the location requested by process no.%d: ",i);
                          scanf("%d",&locreq[i]);
             }
             printf("Enter the initial head position\t");
             scanf("%d",&head);
             locreq[0]=head;
             printf("\n");
             for(j=0;j<=n-1;j++)
             {
                          temp=abs(locreq[j+1]-locreq[j]);
                          seek+=temp;
                          printf("Head moves from location %d to location %d with Seek time: %d\n",locreq[j],locreq[j+1],temp);
             }
             printf("\nTotal Seek Time is :%d\t",seek);
             getch();
}
