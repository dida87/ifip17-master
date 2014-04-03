#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>

#define SERVER "dida"
#define ServPort 2222
#define BufSize 1024
//argv[1] => the host or the address of the server
int main(int argc, char *argv[]){
int sd, rc;
struct sockaddr_in serveraddr, clientaddr;
int serveraddrlen = sizeof(serveraddr);
int clientaddrlen = sizeof(clientaddr);
char clibuf[BufSize];
char server[255];
char *ptrbuf = clibuf;
int lenbuf = sizeof(clibuf);
struct hostent *hostp;
memset(clibuf, '0', lenbuf);
memcpy(clibuf, "hello,client request", 21);
//creation de socket
sd = socket(AF_INET, SOCK_DGRAM, 0);
if(sd < 0){
	perror("Client-socket() error\n");
	exit(-1);
}
else
printf("Client-socket() OK\n");
if (argc > 1)
	//copier l'argument de l'adresse dans le buffer serveur
	strcpy(server,argv[1]);
	else{
		printf("UDP client - Usage %s <Server hostname or IP @>\n", argv[0]);
	printf("UDP Client - Uing default host or IP\n");
	strcpy(server, SERVER);
	}
//preparation des parametres
memset(&serveraddr, '0', serveraddrlen);
serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(ServPort);
if ((serveraddr.sin_addr.s_addr =  inet_addr(server)) == (unsigned long) INADDR_NONE){
	//recuperer l'adresse de l'hote du server, si l'hote du server est passé comme argument
	hostp = gethostbyname(server);
	if (hostp == (struct hostent *) NULL){
		printf("erroeNumb %d\n", h_errno);
		exit(-1);
	}
	else
	printf("UDP client - gethostbyname() is OK\n");
	memcpy(&serveraddr.sin_addr, hostp->h_addr, sizeof(serveraddr.sin_addr));
}
//envoyer la requete au serveur
rc = sendto(sd, ptrbuf, lenbuf, 0, (struct sockaddr *) &serveraddr, serveraddrlen);
if (rc < 0){
	perror("Client-sendto() error\n");
	close(sd);
	exit(-1);
}
else
printf("Client-sendto() OK\n");
printf("Waiting reply from UDP Server.....\n");
rc = recvfrom(sd,ptrbuf, lenbuf, 0, (struct sockaddr *) &serveraddr, &serveraddrlen);
if (rc < 0){
	perror("Client-recvfrom() error\n");
	close(sd);
	exit(-1);
}
else {
printf("UDP client receive the following message %s\n",ptrbuf);
printf("From port %d and the address %s\n", ntohs(serveraddr.sin_port), inet_ntoa(serveraddr.sin_addr));
}
close(sd);
return 0;
}
