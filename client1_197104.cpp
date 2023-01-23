//Adith
//CNLAB
//197104
//CLIENT
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



int main()
{
char m[1000];
    
int sfd,g,p,cname,sname;

struct sockaddr_in s;
socklen_t slen,clen;
struct hostent*se;

p=219201;
sfd=socket(AF_INET,SOCK_STREAM,0);

se=gethostbyname("127.0.0.1");


	s.sin_family = AF_INET;
	s.sin_port = htons(p);

	
	bcopy(se->h_addr, (char *) &s.sin_addr, se->h_length);	


	int l;
	l=connect(sfd, (struct sockaddr*) &s, sizeof(s)); 
    cname=getsockname(sfd,(sockaddr *)&s,&slen);
     cout<<"Hi everybody i am the client the local ip is: "<<cname<<endl;
	sname=getpeername(sfd,(sockaddr *)&s,&clen);
     cout<<"Hi everybody i am the client the foreign ip is: "<<sname<<endl;

	

	
	
	while (1) {
		cout<<"Hi i am the client enter the message to send to the server:"<<endl;
        cin>>m;
		send(sfd, m, strlen(m), 0);

        char ch[3];
        cin>>ch;
        if(strcmp(ch,"end")==0)
        break;
	}

close(sfd);
	return 0;








}

