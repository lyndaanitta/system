#include<stdio.h>

void main()
{
      printf("\n\n*** LRU PAGE REPLACEMENT ALGORITHM ***\n\n");
      int frames[10], temp[10], pages[10];
      int pgnum, i, n, position, k, j, fm_size;
      int a = 0, b = 0, page_fault = 0;
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &fm_size);
      for(i = 0; i < fm_size; i++)
      {
            frames[i] = -1;
      }
      printf("Enter Total Number of Pages:\t");
      scanf("%d", &pgnum);
      printf("Enter Values for Reference String:\n");
      for(i = 0; i < pgnum; i++)
      {
            printf("\tREFERENCE No.%d:\t", i + 1);
            scanf("%d", &pages[i]);
      }
      for(n = 0; n < pgnum; n++)
      {
            a = 0, b = 0;
            for(i = 0; i < fm_size; i++)
            {
                  if(frames[i] == pages[n])
                  {
                        a = 1;
                        b = 1;
                        break;
                  }
            }
            if(a == 0)
            {
                  for(i = 0; i < fm_size; i++)
                  {
                        if(frames[i] == -1)
                        {
                              frames[i] = pages[n];
                              b = 1;
                              break;
                        }
                  }
            }
            if(b == 0)
            {
                  for(i = 0; i < fm_size; i++)
                  {
                        temp[i] = 0;
                  }
                  for(k = n - 1, j = 1; j <= fm_size - 1; j++, k--)
                  {
                        for(i = 0; i < fm_size; i++)
                        {
                              if(frames[i] == pages[k])
                              {
                                    temp[i] = 1;
                              }
                        }
                  }
                  for(i = 0; i < fm_size; i++)
                  {
                        if(temp[i] == 0)
                        position = i;
                  }
                  frames[position] = pages[n];
                  page_fault++;
            }
            printf("\n");
            for(i = 0; i < fm_size; i++)
            {
                  printf("%d\t", frames[i]);
            }
      }
      printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
}
