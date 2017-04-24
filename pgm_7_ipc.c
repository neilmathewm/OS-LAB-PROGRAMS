#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h> 
 void main()
{
int fd,op,c,a,b,i=0,*p;
fd=shm_open("mem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
p=mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
ftruncate(fd,100);
if(p==MAP_FAILED)
	printf("\nFailed TO Map");
printf("ENTER 2 OPERANDS ");
scanf("%d",&a);
scanf("%d",&b);
*p=a;
p=p+2;
*p=b;
p=p+2;
printf("\nMENU\n1.Addition\n2.Subtraction\n3.Division\n4.Multiplication\n\nEnter Option : ");
scanf("%d",&op);
*p=op;
munmap(NULL,100);
close(fd);
}
