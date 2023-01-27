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
#include<signal.h>
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
    
    int sfd,nsfd,g,nsfd2,usfd,sfd1,nsfd22;
    int sname,cname;
    struct sockaddr_in s,c;
struct sockaddr_un aa;

    

int main()
{

    
socklen_t clen,slen;

    

     
     cout<<"BOWLER:----"<<endl;
        
        
        

sfd=open("spin_speed197104.txt",O_RDONLY);




cout<<"BOWLER:Opened file descriptor....."<<endl;


char j[100],j2[100];

     
					
		
			char *pp="./batbolla";
            
   usfd = socket(AF_UNIX, SOCK_STREAM, 0)  ; 
   memset(&aa, 0, sizeof(aa));
	aa.sun_family = AF_UNIX;
	strcpy(aa.sun_path, pp);
	unlink(pp);
   bind(usfd, (struct sockaddr*)&aa, sizeof(aa));

   listen(usfd, 7);

   nsfd2 = accept(usfd, (struct sockaddr*)&c, &clen);

cout<<"BOWLER:Connected to batsman..."<<endl;

   send_fd(nsfd2,sfd);

   socklen_t clenn,slenn;
struct sockaddr_in ss,cc;
    sfd1=socket(AF_INET,SOCK_STREAM,0);

    ss.sin_family=AF_INET;
    ss.sin_port=htons(202289);
    ss.sin_addr.s_addr=INADDR_ANY;
     bzero(&ss.sin_zero,sizeof(ss));

     slenn=sizeof(struct sockaddr_in);


     bind(sfd1,(struct sockaddr *)&ss,slenn);

    


cout<<"BOWLER:Bowled ball to batsman...."<<endl;
     listen(sfd1,100);
     clenn=sizeof(cc);
     nsfd22=accept(sfd1,(struct sockaddr *)&cc,&clenn);
     

read(nsfd22,o,1000);
     
     int l=atoi(o);

     kill(l,SIGUSR1);
     cout<<"BOWLER:Notified umpire...."<<endl;
     
socklen_t clennn,slennn;
struct sockaddr_un abc;
int usfd33,nsfd33;
    char *pppp = "./umpireballer";
     
     cout<<"BOWLER:----"<<endl;
        usfd33 = socket(AF_UNIX, SOCK_STREAM, 0);
        memset(&abc, 0, sizeof(abc));
	abc.sun_family = AF_UNIX;
	strcpy(abc.sun_path, pppp);
   sleep(5);
    connect(usfd33, (struct sockaddr*)&abc, sizeof(abc));
    cout<<"BOWLER:connected to umpire"<<endl;

    nsfd33=recv_fd(usfd33);
 cout<<"BOWLER:recieved fd back from umpire for next ball"<<endl;








  

        


    

  
}
