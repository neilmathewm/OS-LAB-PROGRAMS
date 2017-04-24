#include<stdio.h>
#include<string.h>
#include <dirent.h>
void main(int argc, char* argv[])
{
char c,path[20],str[20],temp[100],line[100];
int m,i,flag=0,ch,count=0,r,j=0;
DIR *d;
struct dirent *dir;
FILE *fptr,*fd;
if(argv[1][0]=='l' && argv[1][1]=='s'){
	if(argv[1][2]=='\0')             //for simple ls command
		d = opendir(".");
	else{
        d = opendir(argv[2]);
		}
    if (d){
        while ((dir = readdir(d)) != NULL)
            printf("%s\n", dir->d_name);
        closedir(d);
          }
  } //if of ls
else if(argv[1][0]=='c'&&argv[1][1]=='a'&&argv[1][2]=='t'){
    fptr = fopen(argv[2], "r");
  	if (fptr == NULL)
        printf("Cannot open file \n");
    else {
	    c = fgetc(fptr);
    	while (c != EOF){
        	printf ("%c", c);
        	c = fgetc(fptr);
    		}
        fclose(fptr);
		}
	}//else  if of cat
else if(argv[1][0]=='g'&&argv[1][1]=='r'&&argv[1][2]=='e'&&argv[1][3]=='p'){
    FILE *fp;
    fp = fopen(argv[3],"r");  //arg2 is file
	while(1){
		fgets(temp,1000,fp);
		if(feof(fp))
            break;
        if(strstr(temp,argv[2])) {
		printf(" %s",temp);
		flag=1;
            }
		}
    if(flag==0)
		printf("\npattern not found\n");
    fclose(fp);
	} //else if of grep
else if(argv[1][0]=='m'&&argv[1][1]=='o'&&argv[1][2]=='r'&&argv[1][3]=='e'){
    FILE *fp = fopen(argv[2],"r");
    if(fp == NULL){
        printf("File doesn't exist\n");
        return;
             }
    while((ch=fgetc(fp))!=EOF){
		putchar(ch);
		if(ch=='\n'){
            count++;
		if(count==25){
            getchar();
                }
            }
		}
    fclose(fp);
    }
}
