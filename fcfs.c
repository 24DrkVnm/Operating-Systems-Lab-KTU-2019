#include<stdio.h>
void main()
{
int n,i;
printf("Enter the total number of processes ");
scanf("%d" ,&n);
int wt_time[n],bt_time[n],tat_time[n];
float avg_wt=0,avg_tat=0;
printf("Enter the burst time of the processes ");
for(i=0;i<n;i++)
{
printf("\nP%d burst time: ",i);
scanf("%d",&bt_time[i]);
if(i<1)
{
wt_time[i]=0;
tat_time[i]=bt_time[i];
avg_wt=(avg_wt+wt_time[i]);
avg_tat=(avg_tat+tat_time[i]);
}
else
{
wt_time[i]=wt_time[i-1]+bt_time[i-1];
tat_time[i]=wt_time[i]+bt_time[i];
avg_wt=avg_wt+wt_time[i];
avg_tat=avg_tat+tat_time[i];
}
}
printf("\n_______________________________________________");
printf("\n| Process | BurstTime | WaitingTime | TATtime |");
for(i=0;i<n;i++)
{
printf("\n| P%d      | %d         | %d           | %d       |",i,bt_time[i],wt_time[i],tat_time[i]);
}
printf("\n--------------------------------------------------------\n");
printf("Average waiting time : %.2f\nAverage turn around time : %.2f",(avg_wt/n-1),(avg_tat/n-1));
printf("\n--------------------------------------------------------\n");
for(i=0;i<n;i++)
{
printf("| P%d ",i);
}
printf("|\n------------------------------------------\n");
printf("0");
for(i=1;i<n;i++)
{
printf("    %d",bt_time[i-1]+wt_time[i-1]);
}
printf("    %d\n",bt_time[n-1]+wt_time[n-1]);
}

