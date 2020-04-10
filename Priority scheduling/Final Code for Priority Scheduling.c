#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int et[20],at[10],n,i,j,temp,p[10],start[10],ft[10],wt[10],ta[10];
    int totwaittime=0,totturnaround=0;
    float avgwtime,avgtatime;
    char pn[10][10],t[10];
    printf("Enter the number of process : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Process_Name : ");
        scanf("%s",pn[i]);
        printf("Enter ArrivalTime : ");
        scanf("%d",&at[i]);
        printf("Enter Burst Time : ");
        scanf("%d",&et[i]);
        printf("Enter Priority : ");
        scanf("%d",&p[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            start[i]=at[i];
            wt[i]=start[i]-at[i];
            ft[i]=start[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            start[i]=ft[i-1];
            wt[i]=start[i]-at[i];
            ft[i]=start[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        totwaittime+=wt[i];
        totturnaround+=ta[i];
    }
    avgwtime=(float)totwaittime/n;
    avgtatime=(float)totturnaround/n;
    printf("\nProcess Name\tArrival Time\t\tBurst Time\tPriority\t\tWaiting Time\tTurnAround Time");
    for(i=0; i<n; i++)
        printf("\n%s\t\t%5d\t\t\t%5d\t\t%5d\t\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
    printf("\nAverage Waiting Time is:%f",avgwtime);
    printf("\nAverage Turnaround Time is:%f",avgtatime);
    getch();
}
