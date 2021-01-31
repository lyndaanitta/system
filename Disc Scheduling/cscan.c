#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



void main()
{
    int i=0,locvar,n_req,head,seek=0,temp[100],trk_cap,locreq1[100],locreq2[100],dir,j=0,k=0,n=0,chk,diff=0;
    int seq[100];
    printf("\n\n_________CSCAN SHEDULING OF DISK__________\n\n");
    printf("Enter the number of tracks in the cylinder:");
    scanf("%d",&trk_cap);
    while(i==0)
    {
        printf("Enter the current head position:");
        scanf("%d",&head);
        if(head>trk_cap||head<0)
            printf("\n\n*****INVALID TRACK LOCATION*****\n\n");
        else
            i++;
    }
    printf("which direction you choose to move the head:\n\tFor 'TO LEFT'  press 1\n\tFor 'TO RIGHT' press 2\n");
    scanf("%d",&dir);
    printf("Enter the no of process requests\t:");
    scanf("%d",&n_req);
    i=0;
    while(i!=n_req)
    {
        printf("Enter the track location requested by process no.%d: ",i+1);
        scanf("%d",&locvar);
        if(locvar>trk_cap||locvar<0)
        {
            printf("\n\n*****INVALID TRACK LOCATION*****\n\n");
            printf("DO YOU WANT TO RE-ENTER:\n\tFOR 'YES' PRESS 1\n\tFOR 'NO'  PRESS 2\n");
            scanf("%d",&chk);
            switch(chk)
            {
                case 1:break;
                case 2:i+=1;
                       break;
                default:printf("\n\n*****INVALID KEY:ASKING TO RE-ENTER*****\n");
            }
        }
        else
        {
            if((locvar>head)||((locvar==head)&&dir==2))
            {
                locreq1[j]=locvar;
                j++;
            }
            else if((locvar<head)||((locvar==head)&&dir==1))
            {
                locreq2[k]=locvar;
                k++;
            }
            else
            {
                printf("\n\n****wrong head direction value selected****\n\n");
                exit(0);
            }



            i++;
        }
    }




  auto void bubble(int *temp,int a,int len)
  {
    bool swp;
    int temp2;
    switch(a)
    {
        case 1:/*ascending sorting*/
               for(i=0;i<len-1;i++)
               {
                  swp=false;
                  for(int b=0;b<len-i-1;b++)
                  {
                      if(temp[b]>temp[b+1])
                      {
                          temp2=temp[b];
                          temp[b]=temp[b+1];
                          temp[b+1]=temp2;
                          swp=true;
                      }
                  }
                  if(swp==false)
                    break;
               }
               break;
        case 2:/*descending sorting*/
               for(i=0;i<len-1;i++)
               {
                  swp=false;
                  for(int b=0;b<len-i-1;b++)
                  {
                      if(temp[b]<temp[b+1])
                      {
                          temp2=temp[b];
                          temp[b]=temp[b+1];
                          temp[b+1]=temp2;
                          swp=true;
                      }
                  }
                  if(swp==false)
                    break;
               }
               break;
    }
  }
 switch(dir)
 {
     case 1:locreq2[k++]=0;
            locreq1[j++]=trk_cap;
            locreq2[k++]=head;
            bubble(locreq1,2,j);
            bubble(locreq2,2,k);
            locreq2[k++]=locreq1[0];
            printf("\n\n");
            for(int d=0;d<k-1;d++)
            {

                diff=abs(locreq2[1+d]-locreq2[d]);
                seek+=diff;
                printf(" Head moves from location %d to location %d with Seek time: %d\n",locreq2[d],locreq2[1+d],diff);
                seq[n]=locreq2[1+d];
                n++;

            }
            n--;
            for(int d=0;d<j-1;d++)
            {
                /*printf("%d ",locreq1[d]);*/
                diff=abs(locreq1[1+d]-locreq1[d]);
                seek+=diff;
                printf(" Head moves from location %d to location %d with Seek time: %d\n",locreq1[d],locreq1[1+d],diff);
                seq[n-1]=locreq1[1+d];
                n++;
            }
            printf("\n\n*****SCAN SHEDULING SEQUENCE*****\n\n");
            for(i=0;i<n-1;i++)
            {
                printf("\t%d",seq[i]);
            }
            break;
     case 2:locreq1[j++]=trk_cap;
            locreq1[j++]=head;
            locreq2[k++]=0;
            bubble(locreq1,1,j);
            bubble(locreq2,1,k);
            locreq1[j++]=locreq2[0];
            printf("\n\n");
            for(int d=0;d<j-1;d++)
            {
                diff=abs(locreq1[1+d]-locreq1[d]);
                          seek+=diff;
                printf(" Head moves from location %d to location %d with Seek time: %d\n",locreq1[d],locreq1[1+d],diff);
                seq[n]=locreq1[1+d];
                n++;
            }
            n--;
            for(int d=0;d<k-1;d++)/* printf("%d ",locreq1[d]);*/
            {
                diff=abs(locreq2[1+d]-locreq2[d]);
                          seek+=diff;
                printf(" Head moves from location %d to location %d with Seek time: %d\n",locreq2[d],locreq2[1+d],diff);
                seq[n-1]=locreq2[1+d];
                n++;
            }
            printf("\n\n*****SCAN SHEDULING SEQUENCE*****\n\n");
            for(i=0;i<n-1;i++)
            {
                printf("\t%d",seq[i]);
            }
            break;
    default:printf("\n\n****wrong head direction value selected****\n\n");

 }
  printf("\nTotal Seek Time is :%d\t",seek);
}
