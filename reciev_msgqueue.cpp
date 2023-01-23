#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h> 
#include<sys/wait.h>
#include<pthread.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<sys/types.h>
#include<sys/poll.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fstream>
#include<sys/msg.h>
#include<sys/ipc.h>
using namespace std;


struct mmsg{

    long int msgt;
    char m[100];


};
pthread_t rec;

void* recc(void *arg)
{
    
    
    char ch[100];
    struct mmsg k;
    int mn;
    
    mn=msgget(197104,0666|IPC_CREAT);

    if(mn==-1)
    {
        cout<<"error";
    }

    while(1)
    {
        msgrcv(mn,(void*)&k,sizeof(k),0,0);
       

       cout<<k.m<<endl;
   }

   



    
    
    
}

int main()
{

      pthread_create(&rec,NULL,recc,NULL);




pthread_join(rec,NULL);

    }
