#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h> 
#include<sys/wait.h>
#include<pthread.h>
#include<sys/stat.h>
#include <fcntl.h>
using namespace std;


int main()
{char m2[100];

FILE *ff;
ff=popen("./popen2","w");
if(ff==NULL)
	{
		perror("popen failed");exit(0);
	}
int f22=fileno(ff);



cin>>m2;

write(f22,m2,strlen(m2));




}
