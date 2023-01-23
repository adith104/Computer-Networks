//197104
//CNLAB
//28-1-2022
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
#include<signal.h>

using namespace std;
pthread_t cli,cli2;
char m[1000],n[1000],o[1000],p[1000];
    
    int sfd,nsfd,g,nsfd2;
    int sname,cname;
    struct sockaddr_in s,c;


  

int main()
{

    
socklen_t clen,slen;

    sfd=socket(AF_INET,SOCK_STREAM,0);

    s.sin_family=AF_INET;
    s.sin_port=htons(290322);
    s.sin_addr.s_addr=INADDR_ANY;
     bzero(&s.sin_zero,sizeof(s));

     slen=sizeof(struct sockaddr_in);


     bind(sfd,(struct sockaddr *)&s,slen);

    



     listen(sfd,100);
     clen=sizeof(c);

     
     cout<<"SIGNAL_SENDER:----"<<endl;
        
        
        
     



nsfd=accept(sfd,(struct sockaddr *)&c,&clen);
 cout<<"SIGNAL_SENDER:Connected to RECIVER"<<endl;
        
          



     read(nsfd,o,1000);
     
     int l=atoi(o);

    // kill(l,SIGUSR1);
     

        


    

  
}