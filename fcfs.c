#include<stdio.h>
int main()
{
	int n;
	printf("enter the number of processes: ");
	scanf("%d",&n);
	float avgTime, waitTime = 0;
	int arrivalTime[n], exeTime[n], serviceTime[n], i;
	serviceTime[0] = 0;
    printf("enter the arrival time");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arrivalTime[i]);
	}
	printf("enter the execution time");
	for(i=0;i<n;i++)
	{
		scanf("%d",&exeTime[i]);
	}
	for(i=0;i<n;i++)
	{
		serviceTime[i] = serviceTime[i-1] + exeTime[i-1];
	}
	for(i=1;i<n;i++)
	{
		waitTime = waitTime + serviceTime[i] - arrivalTime[i];
	}
	avgTime = waitTime / n;
	printf("average waiting time: %f",avgTime);
}
