#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BufSize 1024
#define ServPort 12345

int main(int argc, char *argv[]){
//les variables
int sd, nsd;
struct sockaddr_in servaddr;
struct sockaddr_in clientaddr;
int servaddrlen = sizeof(servaddr);
int clientaddrlen = sizeof(clientaddr);
//buffer pour lire et envoyer les requetes au client
char buffer[BufSize];
time_t servtime;

//creation de socket (TCP connection)
sd = socket(AF_INET, SOCK_STREAM, 0);
if(sd<0){
	perror("Server-socket() error\n");
	exit(-1);
}
else
printf("Server-socket() OK\n");
//vider les memoire
memset(&servaddr, '0', servaddrlen);
memset(buffer, '0', sizeof(buffer));
//preparation des attributs
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(ServPort);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
//bind=>attacher le socket a un port et une adresse IP
if(bind(sd, (struct sockaddr *) &servaddr, servaddrlen)<0){
	perror("Server-bind() error\n");
	exit(-1);
}
else
printf("Server-bind() OK\n");
//listen=>nombre de connexion autorise
if(listen(sd, 10)<0){
	perror("Server-listen() eror\n");
	exit(-1);
}
else
printf("Server-listen() OK\n");
while(1){
	//accept
	nsd = accept(sd, (struct sockaddr *) &clientaddr, &clientaddrlen);
	if(nsd<0){
		perror("Server-accept() error\n");
		exit(-1);
	}
	else
	printf("Server-accept() OK\n");
	servtime = time(NULL);
	//snprintf=>send the output to string and precise the length 
	snprintf(buffer, BufSize, "%.24s\r\n", ctime(&servtime));
	write(nsd, buffer, strlen(buffer));
	close(nsd);
	sleep(1);
}

return 0;
}
