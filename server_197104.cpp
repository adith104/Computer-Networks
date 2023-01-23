//Adith
//CNLAB
//197104
//SERVER
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

using namespace std;



int main()
{
char m[1000];
    
    int sfd,nsfd,g;
    int sname,cname;
    struct sockaddr_in s,c;
    
socklen_t clen,slen;

    sfd=socket(AF_INET,SOCK_STREAM,0);

    s.sin_family=AF_INET;
    s.sin_port=htons(219201);
    s.sin_addr.s_addr=INADDR_ANY;
     bzero(&s.sin_zero,sizeof(s));

     slen=sizeof(struct sockaddr_in);


     bind(sfd,(struct sockaddr *)&s,slen);

     sname=getsockname(sfd,(sockaddr *)&s,&slen);
     cout<<"Hi everybody i am the server the local ip is: "<<sname<<endl;



     listen(sfd,100);
     clen=sizeof(c);

     nsfd=accept(sfd,(struct sockaddr *)&c,&clen);
     cname=getpeername(nsfd,(sockaddr *)&c,&clen);
     cout<<"Hi everybody i am the server the foreign ip is: "<<cname<<endl;


     while(1)
     {

         bzero(m,1000);
         g=read(nsfd,m,1000);

         cout<<"Message sent by the client is: "<<m;

        char ch[3];
        cin>>ch;
        if(strcmp(ch,"end")==0)
        break;





     }

     close(nsfd);
     close(sfd);

  return 0;
}





     





    
