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
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <sys/un.h>
#include<signal.h>



using namespace std;
char m[1000];
int mm=0;
struct sockaddr_un aaa,aaaa;
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
int sfd,g,p,cname,sname;

struct sockaddr_in s,c;

socklen_t slen,clen;
struct hostent*se;



 

    void handler(int m)
    {
        cout<<"UMPIRE:Bowler has bowled the ball to batsman and notified me...."<<endl;
    }
int main()
{


p=202289;
sfd=socket(AF_INET,SOCK_STREAM,0);

se=gethostbyname("127.0.0.1");


	s.sin_family = AF_INET;
	s.sin_port = htons(p);

	
	bcopy(se->h_addr, (char *) &s.sin_addr, se->h_length);	


	int l,o;
	
	signal(SIGUSR1,handler);
	
l=connect(sfd, (struct sockaddr*) &s, sizeof(s)); 
   cout<<"UMPIRE:----"<<endl;
        cout<<"UMPIRE:Connected..."<<endl;

	
	
        int a=getpid(),i;

        
        string g=to_string(a);
        
        for(i=0;i<g.length();i++)
        {
            m[i]=g[i];
        }

		send(sfd, m, strlen(m), 0);
		

		bzero(m,1000);

		
int usfd;
		
sleep(5);
  socklen_t clen,slen;

  int nsfd;

    char *pp = "./batumpire";
     
     cout<<"UMPIRE:----"<<endl;
        usfd = socket(AF_UNIX, SOCK_STREAM, 0);
        memset(&aaa, 0, sizeof(aaa));
	aaa.sun_family = AF_UNIX;
	strcpy(aaa.sun_path, pp);
    connect(usfd, (struct sockaddr*)&aaa, sizeof(aaa));
    cout<<"UMPIRE:connected to batsman."<<endl;

    nsfd=recv_fd(usfd);    

    cout<<"UMPIRE:recived fd from batsman"<<endl;


int usfd33,nsfd200;
socklen_t clennnn;
  cout<<"UMPIRE:connecting to bowler to send fd back for next ball"<<endl;
  
    char *ppp="./umpireballer";
            
   usfd33 = socket(AF_UNIX, SOCK_STREAM, 0)  ; 
   memset(&aaaa, 0, sizeof(aaaa));
	aaaa.sun_family = AF_UNIX;
	strcpy(aaaa.sun_path, ppp);
	unlink(ppp);
   bind(usfd33, (struct sockaddr*)&aaaa, sizeof(aaaa));

   listen(usfd33, 7);

   nsfd200 = accept(usfd33, (struct sockaddr*)&c, &clennnn);
   cout<<"UMPIRE:connected to bowler"<<endl;
   send_fd(nsfd200,nsfd);
   cout<<"UMPIRE:SENT FD BAck to bowler"<<endl;






}