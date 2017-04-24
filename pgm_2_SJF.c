#include<stdio.h>
void main()
{
int count=0,n,i,j,temp,bt[20],bt1[20],wt,at1[20],ss[20],tt,min=9999,flag;
float av1=0,av2=0;
printf("ENTER THE NUMBER OF PROCESSES : ");
scanf("%d",&n);

for(i=0;i<n;i++)	
	{
	printf("ENTER BURST TIME OF PROCESS %d : ",i);
	scanf("%d",&bt[i]);
	bt1[i]=bt[i];
	ss[i]=i;	
	printf("ENTER ARRIVAL TIME OF PROCESS %d : ",i);
	scanf("%d",&at1[i]);	
         if(at1[i]<min)
		min=at1[i];	
	}
for(i=0;i<n-1;i++)
	{
	for(j=0;j<n-1;j++)
		{
		if(bt1[j]>bt1[j+1])
			{
				temp=at1[j];
				at1[j]=at1[j+1];
				at1[j+1]=temp;

				temp=ss[j];
				ss[j]=ss[j+1];
				ss[j+1]=temp;
                               
				temp=bt1[j];
				bt1[j]=bt1[j+1];
				bt1[j+1]=temp;
			}		
		}
	}
count=min;
flag=1;
for(i=0;i<n;)
	{
	if(flag==0)
		count++;
	flag=0;
	for(j=0;j<n;j++)
		{
		if(count>=at1[j])
			{			
			wt=count-at1[j];
                        if(wt<0)
				wt=0;  
			tt=wt+bt1[j];
			printf("P%d\tWT:%d\tTT:%d\n ",ss[j],wt,tt);
			count+=bt1[j];	
			at1[j]=999;		
			flag=1;			
			i++;		
			av1+=wt;
			av2+=tt;		
			break;			
					
			}
					
		}
	}

printf("Average Waiting Time : %f\n",av1/n);
printf("Average Turn Around Time : %f\n",av2/n);
}


