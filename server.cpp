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

using namespace std;
pthread_t cli,cli2;
char m[1000],n[1000],o[1000],p[1000];
    
    int sfd,nsfd,g,nsfd2;
    int sname,cname;
    struct sockaddr_in s,c;


    void*client1(void*args)
    {
        while(1){
    
         bzero(m,1000);
         g=read(nsfd,m,1000);

       

         cout<<"CLIENT_1:"<<m<<endl;
        
         }


    }
    void*client2(void*args)
    {
        while(1){
    
         bzero(o,1000);
         g=read(nsfd2,o,1000);

       

         cout<<"CLIENT_2:"<<o<<endl;
         
         }


    }

int main()
{

    
socklen_t clen,slen;

    sfd=socket(AF_INET,SOCK_STREAM,0);

    s.sin_family=AF_INET;
    s.sin_port=htons(75983);
    s.sin_addr.s_addr=INADDR_ANY;
     bzero(&s.sin_zero,sizeof(s));

     slen=sizeof(struct sockaddr_in);


     bind(sfd,(struct sockaddr *)&s,slen);

    



     listen(sfd,100);
     clen=sizeof(c);

     
     cout<<"SERVER:----"<<endl;
        cout<<"SERVER:Connected to client1"<<endl;
        
        cout<<"SERVER:Connected to client2"<<endl;
     


struct pollfd pfd[2];
nsfd=accept(sfd,(struct sockaddr *)&c,&clen);
            nsfd2=accept(sfd,(struct sockaddr *)&c,&clen);
    pfd[0].fd=nsfd;
    pfd[0].events=POLLIN;
    pfd[1].fd=nsfd2;
    pfd[1].events=POLLIN;


char j[100],j2[100];

      while(1){
			int p = poll(pfd,2,1000);
            
         
            
			if (p == 0)								
				{ }
			else if (pfd[0].revents &&POLLIN) {			
				
				read(pfd[0].fd, j, sizeof(j));
				cout<<"CLIENT_1:"<<j<<endl;
				
				
			}
			else if (pfd[1].revents && POLLIN) {			
				
				read(pfd[1].fd, j2, sizeof(j2));
				cout<<"CLIENT_2:"<<j2<<endl;
				
			}
            
           
   }

        


    

  
}

