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
#include<time.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/select.h>
#include<pthread.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/un.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<pcap.h>
#include<errno.h>
#include<netinet/if_ether.h>
#include<net/ethernet.h>

#include<netinet/udp.h>
#include<sys/ipc.h>
#include<sys/msg.h>

using namespace std;
int no=20;


int main()
{
	int kk=6;
	iif(argc<2)cout<<"Enter protocol in arguments\n";
	int rsfd=socket(AF_INET,SOCK_RAW,atoi(argv[1]));
	if(rsfd==-1)custom_perror("socket")
		char buf[BUF_LEN];
	struct sockaddr_in client;
	socklen_t clilen=sizeof(client);
	cout<<"receive"<<endl;
	recvfrom(rsfd,buf,BUF_LEN,0,(sockaddr*)&client,(socklen_t*)clilen);
	perror("recv");
	 struct iphdr *ip;
  ip=(struct iphdr*)buf;
	cout<<(buf+(ip->ihl)*4)<<endl;
	 


}