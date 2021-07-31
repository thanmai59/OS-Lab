#include<stdio.h>
 
int main()
{
      int bt[20], process[20], wt[20], tat[20], priority[20];
      int i, j, n, sum = 0, position, temp;
      float average_wait_time,average_turnaround_time;
      printf("Enter Total Number of Processes: ");
      scanf("%d", &n);
      printf("\nEnter Burst Time and Priority For %d Processes\n", n);
      for(i = 0; i < n; i++)
      {
            printf("\nProcess[%d]\n", i + 1);
            printf("Process Burst Time: ");
            scanf("%d", &bt[i]);
            printf("Process Priority: ");
            scanf("%d", &priority[i]);
            process[i] = i + 1;
      }
      for(i = 0; i < n; i++)
      {
            position = i;
            for(j = i + 1; j < n; j++)
            {
                  if(priority[j] > priority[position])
                  {
                        position = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[position];
            priority[position] = temp; 
            temp = bt[i];
            bt[i] = bt[position];
            bt[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      }
      wt[0] = 0;
      for(i = 1; i < n; i++)
      {
            wt[i] = 0;
            for(j = 0; j < i; j++)
            {
                  wt[i] = wt[i] + bt[j];
            }
            sum = sum + wt[i];
      }
      average_wait_time = sum / n;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < n; i++)
      {
            tat[i] = bt[i] + wt[i];
            sum = sum + tat[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], bt[i], wt[i], tat[i]);
      }
      average_turnaround_time = sum / n;
      printf("\nAverage Waiting Time: %f", average_wait_time);
      printf("\nAverage Turnaround Time: %f\n", average_turnaround_time);
      return 0;
}