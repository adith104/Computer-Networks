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
#include<semaphore.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
using namespace std;

struct shared{
    int k;
   
};

int main()
{




    cout<<"Hello this is semaphore practice..."<<endl;
sem_t *s12;
       s12=sem_open("s12", O_CREAT, 0644, 0);
       sem_t *s21;
       s21=sem_open("s21", O_CREAT, 0644, 0);

       struct shared *s;
   int shmid;
   shmid=shmget(102,sizeof(struct shared),IPC_CREAT|0666);
   s=(shared *)shmat(shmid,NULL,0);
    
       s->k=5;

    int c=fork();


    if(c>0)
    {
        cout<<"CHILD:HI NOW I HAVE ACCESS TO THE RESOURCE BALLE BALLE"<<endl;
       cout<<"CHILD:okk im going into waiting state and allowing parent to takeover "<<++s->k<<endl;
       
       sleep(2);
       sem_post(s21);
      sem_wait(s12);
      cout<<"CHILD:HI NOW I HAVE ACCESS TO THE RESOURCE BALLE BALLE"<<endl;
      cout<<++s->k;
    }
    else
    {
        sem_wait(s21);
        cout<<--s->k;
        cout<<" PARENT:HI NOW I HAVE ACCESS TO THE RESOURCE BALLE BALLE"<<endl;
       cout<<"PARENT:okk im going into waiting state and allowing child to retake control"<<endl;
       sleep(2);

     sem_post(s12);

    }


}