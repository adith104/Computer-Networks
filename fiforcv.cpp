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
    char m[100];

int l;

l=open("lmoa",O_RDONLY);


read(l,m,100);

cout<<m;





}