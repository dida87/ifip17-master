#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BufSize 1024
#define ServPort 12345

int main(int argc, char *argv[]){
int sd, n;
char recvBuf[BufSize];
struct sockaddr_in servaddr;
int servaddrlen = sizeof(servaddr);
if (argc!=2){
	printf("Usage : %s <@IP server>\n", argv[0]);
	exit(-1);
}
//vider la memoire du buffer
memset(recvBuf, '0', BufSize);
//creation de socket
sd = socket(AF_INET, SOCK_STREAM, 0);
if (sd<0){
	perror("client-socket() error\n");
	exit(-1);

}
else
printf("client-socket() OK\n");
//prepartion des paramatres
memset(&servaddr, '0', servaddrlen);
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(ServPort);
if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr)<=0){
	printf("\n inet_pton error\n");
	return 1;
}
//connect
if (connect(sd, (struct sockaddr *)&servaddr, servaddrlen)<0){
	perror("Client-connect() error\n");
	exit(-1);
}
else
printf("Client-connect() OK\n");
while((n = read(sd, recvBuf, BufSize))>0){
	recvBuf[n] = 0;
	//fputs=> write string to specified stream
	if(fputs(recvBuf, stdout) == EOF){
		//EOF => error
		printf("\n Error : fputs error\n");
	}
}
if(n<0){
	perror("Client-read() error\n");
	exit(-1);

}
return 0;
}
