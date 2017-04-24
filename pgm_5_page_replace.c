#include<stdio.h>
struct PAGE_OFFSET {

	unsigned char offset;
	unsigned char page;
};
union ADDRESS{

	unsigned short int addr;
	struct PAGE_OFFSET A;
};

void main()
{
union ADDRESS obj[20];
int t,count,q[25],st[25],pgno,n,pg[25],ct[25],i,j=0,op,pf=0,flag=0,k,m=0,l,pos,small;

printf("\nMENU\n1.FIFO\n2.LRU\n\nENTER OPTION : ");
scanf("%d",&op);

printf("\nEnter No of Frames : ");
	scanf("%d",&n);
	printf("\nEnter No of Pages To be Inserted : ");
	scanf("%d",&pgno);
	printf("\nEnter Pages : ");
	for(i=0;i<pgno;i++)
            {
	printf("Enter the page %d :",i);
        scanf("%x", &obj[i].addr);
        printf("PAGE = %x\n", obj[i].A.page);
        printf("OFFSET = %x \n", obj[i].A.offset);
			}

if(op==1)
	{pf=0;
	j=0;
	for(i=0;i<pgno;i++)
		{
		flag=0;
		for(l=0;l<m;l++)
			{
				if(obj[i].A.page==pg[l])
				flag=1;
			}
	if(flag==0){
		pf++;
		if(j<n)
			{
			pg[j]=obj[i].A.page;
			j++;
			if(m!=n)
				m++;
			if(j==n)
				j=0;
			}
		printf("\n");
		for(k=0;k<m;k++)
			printf("%d\t",pg[k]);
		}
	}
	printf("\n\nPage Faults : %d\n\n",pf);}
else if(op==2)
	{pf=0;
	j=0;
	count=0;
	for(i=0;i<10;i++)
		ct[i]=0;
	for(i=0;i<pgno;i++)
		{
		flag=0;
		for(l=0;l<m;l++)
			{
			if(obj[i].A.page==pg[l])
				{
				flag=1;
				ct[l]=++count;  //
				//ct[l]=0;
				//for(t=0;t<m;t++)
				//   if(t!=l)					
				//	ct[t]++;
				}
			}
	if(flag==0){
		pf++;
		if(j<n)
			{
			pg[j]=obj[i].A.page;
			ct[j]=++count;  //
			j++;
			if(m!=n)
				m++;
			}
		else	{
			small=ct[0];
			pos=0;
			for(k=0;k<m;k++)
				if(ct[k]<small)
					{small=ct[k];
					pos=k;
					}
			pg[pos]=obj[i].A.page;
			ct[pos]=++count;//
			}
		printf("\n");
		for(k=0;k<m;k++)
			printf("%d\t",pg[k]);
		}
	}
	printf("\n\nPage Faults : %d\n\n",pf);
	}
}
