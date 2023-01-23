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
pthread_t sen;

void* ssnd(void *arg)
{
    
    
    struct mmsg k;
    int mn;
    
    mn=msgget(197104,0666|IPC_CREAT);

    if(mn==-1)
    {
        cout<<"error";
    }
    while(1){

      cout<<"ENTER SOMETHING:\n";
        fgets(k.m,100,stdin);
      
        k.msgt=1;

        msgsnd(mn, (void*)&k,100,0);}
        
   



    
    
    
}

int main()
{
    pthread_create(&sen,NULL,ssnd,NULL);




pthread_join(sen,NULL);
}