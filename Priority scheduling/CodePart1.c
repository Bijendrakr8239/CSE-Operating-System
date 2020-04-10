#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int et[20],at[10],n,i,j,temp,p[10],start[10],ft[10],wt[10],ta[10];
    int totwaittime=0,totturnaround=0;
    float avgwtime,avgtatime;
    char pn[10][10],t[10];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Process_Name\n");
        scanf("%s",pn[i]);
        printf("Enter ArrivalTime\n");
        scanf("%d",&at[i]);
        printf("Enter Burst Time\n");
        scanf("%d",&et[i]);
        printf("Enter Priority\n");
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
}
