#include<stdio.h>
void main()
{
int n,i,j,temp,bt[20],bt1[20],wt[20],at1[20],fc[20],tt[20];
float avwt=0,avta=0;
printf("ENTER THE NUMBER OF PROCESSES : ");
scanf("%d",&n);

for(i=0;i<n;i++)	
	{
	printf("ENTER BURST TIME OF PROCESS %d : ",i);
	scanf("%d",&bt[i]);
	bt1[i]=bt[i];
	fc[i]=i;	
	printf("ENTER ARRIVAL TIME OF PROCESS %d : ",i);
	scanf("%d",&at1[i]);	
	}
for(i=0;i<n-1;i++)
	{
	for(j=0;j<n-1;j++)
		{
		if(at1[j]>at1[j+1])
			{
				temp=at1[j];
				at1[j]=at1[j+1];
				at1[j+1]=temp;

				temp=fc[j];
				fc[j]=fc[j+1];
				fc[j+1]=temp;
                               
				temp=bt1[j];
				bt1[j]=bt1[j+1];
				bt1[j+1]=temp;
			}		
		}
	}
for(i=0;i<n;i++)
	{
	if(i==0)
		wt[0]=0;
	else
		wt[i]=wt[i-1]+bt1[i-1]-at1[i]+at1[i-1];
	
	if(wt[i]<0)
		wt[i]=0;    //to avoid negative	 
	tt[i]=bt[i]+wt[i];
	}
printf("\nP :");
for(i=0;i<n;i++)
	{
	printf("P%d  ",fc[i]);
	}
printf("\nWT:");
for(i=0;i<n;i++)
	{
	printf(" %d  ",wt[i]);	
		avwt+=wt[i];


	}
printf("\nTA:");
for(i=0;i<n;i++)
	{
	printf(" %d  ",tt[i]);	
		avta+=tt[i];
	}
avwt=avwt/n;
avta=avta/n;

printf("\n");
printf("\nAverage WT = %f ",avwt);
printf("\nAverage TA = %f ",avta);
}


