#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h> 
 void main()
{
int a,b,ch,op,*p,fd,res;
float c,d;
fd=shm_open("mem",O_RDWR,S_IRUSR|S_IWUSR);
p=mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
ch=*p;
a=*p;
p=p+2;
b=*p;
p=p+2;
op=*p;
c=a;
d=b;
if(op==1)
	printf("Result\n%d + %d = %d \n\n",a,b,a+b);
else if(op==2)
	printf("Result\n%d - %d = %d \n\n",a,b,a-b);
else if(op==3)
	printf("Result\n%f / %f = %f \n\n",c,d,c/d);
else if(op==4)
	printf("Result\n%d * %d = %d \n\n",a,b,a*b);

else
	 printf("Invalid Operator");
}
