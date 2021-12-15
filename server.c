
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<ctype.h>

#define PORT 4444
int fact (int n)
{
	int i,s=1;
        for(i=1;i<=n;i++)
	{
	  s=s*i;
	}
	if (n==0) return 0;
	else return s;
}
int main(){

	    int dd;
		int sockfd;
		
		int newSocket;

		struct sockaddr_in serverAddr; 
		struct sockaddr_in newAddr; 

		char buffer[1024];
		int bufferI[100];
		
		socklen_t addr_size;
		
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		printf("[+] Server Socket Created Successfully\n");
		

		memset(&serverAddr, '\0', sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(PORT); // conversion en octets
		serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // adresse du server
		
		
		bind(sockfd,(struct sockaddr *) &serverAddr , sizeof(serverAddr));
		printf("[+] Bind to Port Number %d.\n", PORT);


		listen(sockfd, 5);
		printf("\n[+] Server en attente du Client....\n");
	
		newSocket = accept(sockfd , (struct sockaddr *) &newAddr , &addr_size);
		
		// Si le Server accepte la communication
		read(newSocket, buffer, 1024);
		printf("\n (Client) message : %s\n",buffer);
		
		printf("\n Réponse du Server:((copier cette message)) oui donne moi ce nombre \n");
		

		fgets(buffer, 1024, stdin);
		write(newSocket, buffer,1024);
		
		read(newSocket,bufferI,100);
		printf("le nombre choisie est %d",*bufferI);
                 dd = *bufferI;
		*bufferI = fact(dd);
		write(newSocket, bufferI,sizeof(int));
		
		
		
		


	
	printf("[+]Ok, I am going to close the connection.\n");
	printf("[+]SEE YOU.\n");
return 0;}



 