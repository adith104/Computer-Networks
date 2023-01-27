//197104
//CNLAB
//15-3-2022
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
#include <sys/un.h>
#include <arpa/inet.h>
#include<netinet/in.h>

using namespace std;
int mm=0;

int recv_fd(int socket)
{
int sent_fd, available_ancillary_element_buffer_space; struct msghdr socket_message;
struct iovec io_vector[1];
struct cmsghdr *control_message = NULL;
char message_buffer[1];
char ancillary_element_buffer[CMSG_SPACE(sizeof(int))];
/* start clean */
memset(&socket_message, 0, sizeof(struct msghdr)); memset(ancillary_element_buffer, 0, CMSG_SPACE(sizeof(int)));
/* setup a place to fill in message contents */ io_vector[0].iov_base = message_buffer; io_vector[0].iov_len = 1; socket_message.msg_iov = io_vector; socket_message.msg_iovlen = 1;
/* provide space for the ancillary data */ socket_message.msg_control = ancillary_element_buffer; socket_message.msg_controllen = CMSG_SPACE(sizeof(int));
if(recvmsg(socket, &socket_message, mm) < 0) return -1;
  if(message_buffer[0] != 'F')
{
/* this did not originate from the above function */ return -1;
}
if((socket_message.msg_flags & MSG_CTRUNC) == MSG_CTRUNC)
{
/* we did not provide enough space for the ancillary element array */
return -1; }
/* iterate ancillary elements */
for(control_message = CMSG_FIRSTHDR(&socket_message);
control_message != NULL;
control_message = CMSG_NXTHDR(&socket_message, control_message))
{
if( (control_message->cmsg_level == SOL_SOCKET) &&
(control_message->cmsg_type == SCM_RIGHTS) ) {
sent_fd = *((int *) CMSG_DATA(control_message));
    return sent_fd;
   }
}
return -1; }

int send_fd(int socket, int fd_to_send)
{
struct msghdr socket_message;
struct iovec io_vector[1];
struct cmsghdr *control_message = NULL;
char message_buffer[1];
/* storage space needed for an ancillary element with a paylod of
length is CMSG_SPACE(sizeof(length)) */
char ancillary_element_buffer[CMSG_SPACE(sizeof(int))]; int available_ancillary_element_buffer_space;
/* at least one vector of one byte must be sent */ message_buffer[0] = 'F';
io_vector[0].iov_base = message_buffer; io_vector[0].iov_len = 1;
/* initialize socket message */ memset(&socket_message, 0, sizeof(struct msghdr)); socket_message.msg_iov = io_vector; socket_message.msg_iovlen = 1;
/* provide space for the ancillary data */ available_ancillary_element_buffer_space = CMSG_SPACE(sizeof(int)); memset(ancillary_element_buffer, 0,
available_ancillary_element_buffer_space); socket_message.msg_control = ancillary_element_buffer; socket_message.msg_controllen =
available_ancillary_element_buffer_space;
/* initialize a single ancillary data element for fd passing */ control_message = CMSG_FIRSTHDR(&socket_message); control_message->cmsg_level = SOL_SOCKET; control_message->cmsg_type = SCM_RIGHTS; control_message->cmsg_len = CMSG_LEN(sizeof(int));
*((int *) CMSG_DATA(control_message)) = fd_to_send;
return sendmsg(socket, &socket_message, 0); }



char m[1000],n[1000],o[1000],p[1000];
    
    int sfd,nsfd,g,nsfd2,usfd,nfd,usfd2,nfd2;
    int sname,cname;
    struct sockaddr_in s,c;
    struct sockaddr_un a,aaa;

int generrand(int a,int b)
{srand (time(NULL));
    int k=abs(a-b);
  k=k/10;
    
k=(rand()%40)+k;

return k;

}
    

int main()
{

    
socklen_t clen,slen;

    char *pp = "./batbolla";
     
     cout<<"BATSMAN:----"<<endl;
        usfd = socket(AF_UNIX, SOCK_STREAM, 0);
        memset(&a, 0, sizeof(a));
	a.sun_family = AF_UNIX;
	strcpy(a.sun_path, pp);
    connect(usfd, (struct sockaddr*)&a, sizeof(a));
cout<<"BATSMAN:Connected to bowler....."<<endl;

    nsfd=recv_fd(usfd);
 
 
cout<<"BATSMAN:Got the first ball..."<<endl;

char ch[20];
        
 cout<<"BATSMAN:Reading from file....."<<endl;       

dup2(nsfd,0);
cin>>ch;

int a=atoi(ch);

cin>>ch;

int b=atoi(ch);

cout<<"BATSMAN:Speed is: "<<a<<" Spin is: "<<b<<endl; 
 int r=generrand(a,b);

cout<<"BATSMAN:Have hit the ball number r = "<<r<<endl;

if(r%4==0)
{
    cout<<"BATSMAN:HAVE HIT A BOUNDARY......."<<endl;;
    char *ppp="./batumpire";
            
   usfd2 = socket(AF_UNIX, SOCK_STREAM, 0)  ; 
   memset(&aaa, 0, sizeof(aaa));
	aaa.sun_family = AF_UNIX;
	strcpy(aaa.sun_path, ppp);
	unlink(ppp);
   bind(usfd2, (struct sockaddr*)&aaa, sizeof(aaa));

   listen(usfd2, 7);

   nsfd2 = accept(usfd2, (struct sockaddr*)&c, &clen);
   send_fd(nsfd2,nsfd);
   cout<<"BATSMAN:SENT FD BAck to umpire"<<endl;

}
else
if(r%6==0)
{
    cout<<"BATSMAN:HAVE HIT A SIXER......."<<endl;
    char *ppp="./batumpire";
            
   usfd2 = socket(AF_UNIX, SOCK_STREAM, 0)  ; 
   memset(&aaa, 0, sizeof(aaa));
	aaa.sun_family = AF_UNIX;
	strcpy(aaa.sun_path, ppp);
	unlink(ppp);
   bind(usfd2, (struct sockaddr*)&aaa, sizeof(aaa));

   listen(usfd2, 7);

   nsfd2 = accept(usfd2, (struct sockaddr*)&c, &clen);
   send_fd(nsfd2,nsfd);
   cout<<"BATSMAN:SENT FD BAck to umpire"<<endl;
}
else
{
    cout<<"BATSMAN:OUT.....";
  
	int rsfd=socket(AF_INET,SOCK_RAW,200);
	
	int optval=1;
	setsockopt(rsfd, IPPROTO_IP, SO_BROADCAST, &optval, sizeof(int));

		struct sockaddr_in client;
	client.sin_family=AF_INET;
	client.sin_addr.s_addr=inet_addr("127.0.0.1");

		char buff[]="out";	
	client.sin_addr.s_addr=INADDR_ANY;

	unsigned int client_len=sizeof(client);
	cout<<"sending"<<endl;
  sendto(rsfd,buff,strlen(buff)+1,0,(struct sockaddr*)&client,sizeof(client));
 
  

}



            
           
  

        


    

  
}
