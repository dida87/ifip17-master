#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define ServPort 2222
#define BufSize 1024

int main(int argc, char *argv[]){
//variables
int sd, rc;
struct sockaddr_in servaddr;
struct sockaddr_in clientaddr;
int servaddrlen = sizeof(servaddr);
int clientaddrlen = sizeof(clientaddr);
char buf[BufSize];
char *ptrbuf = buf;
int lenbuf = sizeof(buf);
//creation de socket
sd = socket(AF_INET, SOCK_DGRAM, 0);
if (sd <0){
	perror("Serv-socket() error\n");
	exit(-1);
}
else
printf("Serv-socket() OK\n");
//bind
printf("UDP-Server try to bind....\n");
//preparation des parametres
memset(&servaddr, '0', servaddrlen);
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(ServPort);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
rc = bind(sd, (struct sockaddr *) &servaddr, servaddrlen);
if (rc < 0){
	perror("Server-bind() error\n");
	close(sd);
	exit(-1);
}
else
printf("Server-bind() OK\n");
printf("Using IP %s and port %d\n", inet_ntoa(servaddr.sin_addr), ServPort);
printf("UDP-Server Listening.......\n");
//wait on client request
rc = recvfrom(sd, ptrbuf, lenbuf, 0,(struct sockaddr *) &clientaddr, &clientaddrlen);
if (rc < 0){
	perror("Server-recvfrom() error\n");
	close(sd);
	exit(-1);
}
else
printf("Server-recvfrom() OK\n");
printf("UDP-Server() receive the message : %s\n", ptrbuf);
printf("From port %d and address %s\n", ntohs(clientaddr.sin_port), inet_ntoa(clientaddr.sin_addr));
//sending a reply message
rc = sendto(sd, ptrbuf, lenbuf, 0, (struct sockaddr *) &clientaddr, clientaddrlen);
if (rc < 0){
	perror("Server-sendto() error\n");
	close(sd);
	exit(-1);
}
else
printf("Server-sendto() OK\n");
close(sd);

return 0;
}
