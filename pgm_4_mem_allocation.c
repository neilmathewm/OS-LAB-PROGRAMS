#include<stdio.h>
#include<stdlib.h>
struct node
{   int beg,end;
    char name[5];
    struct node *next;
}*start=NULL,*temp=NULL,*prev,*insaft;
int first=100,last=1500;
main()
{
void display();
void insend();
void firstfit(struct node *,int);
void bestfit(struct node *,int);
void worstfit(struct node *,int);
void deletespec();
int op,i,n,size;
printf("Enter Current No of Process");
scanf("%d",&n);
for(i=0;i<n;i++)
    insend();
while(1){
    printf("\n\nMENU\n\n1.First Fit\n2.Worst Fit\n3.Best Fit\n4.Display\n5.Deallocate\n6.Exit");
    printf("\n\nENTER THE OPTION");
    scanf("%d",&op);
    if(op==6)
        break;

    if(op==4)
        display();
    else{
        if(op==5)
            deletespec();
        else{
    struct node *newn=(struct node*)malloc(sizeof(struct node));
    printf("\n\nENTER PROCESS NAME:");
    scanf("%s",&newn->name);
    printf("\n\nENTER PROCESS SIZE:");
    scanf("%d",&size);
    if(op==1)
        firstfit(newn,size);
    else if(op==2)
        worstfit(newn,size);
    else if(op==3)
       {

       printf("besttt");
        bestfit(newn,size);
       }
    else
        break;
        }
    }
 }
}
void firstfit(struct node *newn,int size)
{
temp=start;
if(temp->beg-first>=size)   //start is memory location 100 as per question
    {
            newn->beg=100;
            newn->end=newn->beg+size-1;  //actual size
            newn->next=temp;
            start=newn;  //change start
    }
else{
    while(temp->next!=NULL)
        {
        if((((temp->next)->beg)-(temp->end)-1)>=size)//actual free size end-beg-1
            {
            newn->beg=temp->end+1;
            newn->end=newn->beg+size-1;  //actual size
            newn->next=temp->next;
            temp->next=newn;
            break;
            }
        temp=temp->next;
        if(temp->next==NULL)  //if not found still,check for last space till 1500 as per que
            {
            if((last-temp->end)>=size)
                {
                temp->next=newn;
                newn->next=NULL;
                newn->beg=(temp->end)+1;
                printf("%d+%d",temp->end,newn->beg);
                newn->end=newn->beg+size-1;
                break;   //otherwise while repeats again since temp changes
                }
            }
        }
    }
}
void bestfit(struct node *newn,int size)
{
int min=999,pos=-1;
temp=start;
if(((temp->beg)-first)>=size)   //start is memory location 100 as per question
    {
    min=temp->beg-first;
    insaft=NULL;
    pos=0;
    }
    while(temp->next!=NULL)
        {
            if((((temp->next)->beg)-(temp->end)-1)>=size)
            {
            if((((temp->next)->beg)-(temp->end)-1)<min){
                min=(((temp->next)->beg)-(temp->end)-1);
                insaft=temp;
                pos=-1;
                }
            }
        temp=temp->next;
        if(temp->next==NULL)  //check if last is minimum
            {
            if((last-temp->end)>=size&&(last-temp->end)<min)
                {
                pos=-1;
                temp->next=newn;
                newn->next=NULL;
                newn->beg=(temp->end)+1;
                newn->end=newn->beg+size-1;
                break;   //otherwise while repeats again since temp changes
                }
            else        //if not first and last insert in btwn
                {
                if(pos==0)   //if best fit is at begnig
                    {
                    newn->next=start;
                    newn->beg=100;
                    newn->end=100+size-1;
                    start=newn;
                    }
                else{                       //best fit in btwn
                newn->next=insaft->next;
                insaft->next=newn;
                newn->beg=insaft->end+1;
                newn->end=newn->beg+size-1;
                    }
                }
              break;
            }
        }
}
void worstfit(struct node *newn,int size)
{
int max=0,pos=-1;
temp=start;
if(((temp->beg)-first)>=size)   //start is memory location 100 as per question
    {
    max=temp->beg-first;
    insaft=NULL;
    pos=0;
    }
    while(temp->next!=NULL)
        {
       if((((temp->next)->beg)-(temp->end)-1)>=size)
            {
            if((((temp->next)->beg)-(temp->end)-1)>max){
            max=(((temp->next)->beg)-(temp->end)-1);
            insaft=temp;
            pos=-1;
                }
            }
        temp=temp->next;
        if(temp->next==NULL)  //check if last is minimum
            {
            if((last-temp->end)>=size&&(last-temp->end)>max)
                {
                pos=-1;
                temp->next=newn;
                newn->next=NULL;
                newn->beg=(temp->end)+1;
                newn->end=newn->beg+size-1;
                break;   //otherwise while repeats again since temp changes
                }
            else        //if not first and last insert in btwn
                {
                if(pos==0)   //if best fit is at begnig
                    {
                    newn->next=start;
                    newn->beg=100;
                    newn->end=100+size-1;
                    start=newn;
                    }
                else{                       //best fit in btwn
                newn->next=insaft->next;
                insaft->next=newn;
                newn->beg=insaft->end+1;
                newn->end=newn->beg+size-1;
                    }
                }
              break;
            }
        }
}
void insend()
{
temp=start;
struct node *newn=(struct node*)malloc(sizeof(struct node));
printf("\n\nENTER PROCESS NAME:");
scanf("%s",&newn->name);
printf("\n\nENTER STARTING ADDRESS:");
scanf("%d",&newn->beg);
printf("\n\nENTER END ADDRESS:");
scanf("%d",&newn->end);
 if(start==NULL){
         newn->next=NULL;
         start=newn;
                }
else{
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newn;
        newn->next=NULL;
    }
            }

void display()
{
temp=start;
if(start==NULL)
    printf("NO ELEMENTS TO DISPLAY");
else
    {
    printf("\nCURRENT RUNNING PROCESSES\n\n");
    while(temp->next!=NULL)
    {       printf("%s",temp->name);
            printf("\t%d",temp->beg);
            printf("\t%d\n",temp->end);

            temp=temp->next;
    }
    printf("%s",temp->name);
    printf("\t%d",temp->beg);
    printf("\t%d",temp->end);
    }
}
void deletespec()
{
int flag=0,num;
char name[5];
prev=start;
temp=start;
struct node *ptr;
 if(start==NULL)
    printf("UNDERFLOW");
 else
    {
    printf("\nENTER PROCESS TO BE DELETED : ");
    scanf("%s",name);
    while(temp!=NULL)
        {
        if(strcmp(temp->name,name))
                {
                prev=temp;
                temp=temp->next;
                }
        else
                {
                if(temp==start)
                    start=start->next;
                flag=1;
                ptr=temp;
                temp=temp->next;
                prev->next=temp;
                free(ptr);
                }
        }
if(flag==0)
printf("NO SUCH PROCESS EXIST");
    }
}

