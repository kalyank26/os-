#include<stdio.h>

void findWaitingTime(int processes[], int n,
                          int bt[], int wt[])
{
    wt[0] = 0;
   
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
   
void findTurnAroundTime( int processes[], int n,
                  int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
   
void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);

    findTurnAroundTime(processes, n, bt, wt, tat);
  
    printf("Processes   Burst time   Waiting time   Turn around time\n");
   
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("     %d ",(i+1));
        printf("       %d ", bt[i] );
        printf("          %d",wt[i] );
        printf("                %d\n",tat[i] );
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d",s);
    printf("\n");
    printf("Average turn around time = %d ",t);
}
   
int main()
{   int s;
    printf("Enter the number of processes you want to enter");
    scanf("%d",&s);
    int processes[s];
    int  burst_time[s];
    for(int i=0;i<s;i++){
        processes[i]=i+1;
        printf("Enter the process %d burst time",i+1);
        scanf("%d",&burst_time[i]);
    }
    int n = sizeof processes / sizeof processes[0];
   
   
   
    findavgTime(processes, n,  burst_time);
    return 0;
}
