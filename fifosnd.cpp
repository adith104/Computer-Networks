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
{

char mm[100];
int f3;

mkfifo("lmoa",0666);

f3=open("lmoa",O_WRONLY);


while(1){
 cin>>mm;


  write(f3,mm,strlen(mm));}
   
   



}