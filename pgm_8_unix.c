#include <dirent.h>
#include<stdlib.h>
#include <stdio.h>

 

int main(void)

{
    int pid;
    DIR *d;
    char s[20],cmd[25],st[25];
    struct dirent *dir;
    printf("\n enter the directory path\n");
    scanf("%s",s);  // ./New
	sprintf(st,"./%s",s);
    d = opendir(st);

    if (d){
     while ((dir = readdir(d)) != NULL)
     {
if(dir->d_name[0]!='.'){
    printf(" %s\n", dir->d_name);
	
//system("ls");
    pid=fork();
    if(pid<0)
    {
        printf("\n Error ");
       
    }
    else if(pid==0)
    {
	
        printf("\n child process ");

        printf("\n My pid is %d ",getpid());
	sprintf(cmd,"wc -w %s >>output3.txt",dir->d_name);
	
	chdir(s);        
	system(cmd);
	printf("\nSTATUS\n");
	sprintf(cmd,"stat %s",dir->d_name);
	system(cmd);
	printf("\n child process end ");
        exit(0);
    }
    else
    { int returnstatus;
  waitpid(pid,&returnstatus,0);
        printf("\n  parent process ");
        printf("\n My actual pid is %d \n ",getpid());
        //exit(0);
    }
}
}
       

        closedir(d);

    }
      else
          printf("no such file found\n");
    return(0);

}
