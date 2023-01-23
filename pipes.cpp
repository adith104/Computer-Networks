#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h> 
#include<sys/wait.h>
using namespace std;
int main()
{

    int pfd[2];


    char ch[100],ch2[111];
pipe(pfd);
    int c=fork();
  


    if(c>0)
    {
        while(wait(NULL) > 0);
        cout<<"Hi i am p2"<<endl;
        

        read(pfd[0],ch2,sizeof(ch));

        cout<<"Message sent by p1 is "<<ch2<<endl;


    }
    else
    {
    
       
        cout<<"Hi i am p1"<<endl;
        cout<<"Enter the message"<<endl;
        cin>>ch;

        write(pfd[1],ch,sizeof(ch));


    }



}   