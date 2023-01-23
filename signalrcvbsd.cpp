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
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>


using namespace std;
char m[1000];
    
int sfd,g,p,cname,sname;

struct sockaddr_in s;
socklen_t slen,clen;
struct hostent*se;

pthread_t ss;

 

    void handler(int m)
    {
        cout<<"YOU MY SON ARE A CHAMP AND HAVE EXECUTED THIS PERFECTLY-SIGNAL RECIVED"<<endl;
    }
int main()
{


p=290322;
sfd=socket(AF_INET,SOCK_STREAM,0);

se=gethostbyname("127.0.0.1");


	s.sin_family = AF_INET;
	s.sin_port = htons(p);

	
	bcopy(se->h_addr, (char *) &s.sin_addr, se->h_length);	


	int l,o;
	l=connect(sfd, (struct sockaddr*) &s, sizeof(s)); 
   cout<<"SIGNAL_RECIVER:----"<<endl;
        cout<<"SIGNAL_RECIVER:Connected to SENDER"<<endl;

	signal(SIGUSR1,handler);
	
	while(1){
        int a=1333323333,i;
        string g=to_string(a);
        
        for(i=0;i<g.length();i++)
        {
            m[i]=g[i];
        }
       
		send(sfd, m, strlen(m), 0);
		

		bzero(m,1000);

		

		}

      

close(sfd);
cout<<"SIGNAL_RECIVER:Connection closed......"<<endl;
	return 0;
	








}