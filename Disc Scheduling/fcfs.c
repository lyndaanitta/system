#include<stdio.h>
void main()
{
int i,j,n,a[50],frame[50],fm_size,k,avail,count=0;
printf("\nENTER No. OF PAGE REFERENCES:");
scanf("%d",&n);
printf("\nENTER PAGE REFERENCES\n");
for(i=1;i<=n;i++)
{
    printf("\tREFERENCE No.%d:",i);
    scanf("%d",&a[i]);
}
printf("\n ENTER THE NUMBER OF FRAMES :");
scanf("%d",&fm_size);
for(i=0;i<fm_size;i++)
            frame[i]= -1;
j=0;
printf("\n\t PAGE FRAMES\n\n");
for(i=1;i<=n;i++)
{
avail=0;
for(k=0;k<fm_size;k++)
 {
   if(frame[k]==a[i])
   {
       avail=1;
       printf("PAGE HIT ON REFERENCE NO:%d =>",i);
   }
 }

if (avail==0)
{
  frame[j]=a[i];
  j=(j+1)%fm_size;
  count++;
  for(k=0;k<fm_size;k++)
     printf("\t\t\t\t%d",frame[k]);
}
  printf("\n");
}
printf("\n\nTOTAL Page Fault :%d\n\n",count);

}
