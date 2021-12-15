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

int main(){

        FILE *fr;
        int bufferI[100];
		int clientSocket;
		
		struct sockaddr_in serverAddr; 
		
		char buffer[1024];
	
		clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		printf("[+] Client Socket Created Successfully\n");
		
		memset(&serverAddr, '\0', sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(PORT); // conversion en octets
		serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // adresse du server
		
		connect(clientSocket , (struct sockaddr *)&serverAddr , sizeof(serverAddr));
		printf("[+] Client Connected to Server Successfully\n");
		
		
		printf("\n Entrer un message pour le Server:(copier cette message)tu peux m'aider a calculer le factoriel d'un nmbre \n");
		fgets(buffer, 1024, stdin); 
		write(clientSocket, buffer, strlen(buffer));
		
		// Le client va faire appel à la fonction de lecture "read()"
		read(clientSocket, buffer, 1024);
		printf("\n (Server) message : %s\n",buffer);

		printf("\n Entrer un nombre:(copier cette message)5 \n");
		scanf("%d",bufferI);
		write(clientSocket,bufferI,100);
		
		read(clientSocket, bufferI, 100);
		printf("\n (Server) message : %d\n",*bufferI);
		
		fr = fopen("g.txt","w");
		if(fr != NULL)
		{
			fprintf(fr,"le fact est %d",*bufferI);
		    fclose(fr);
		}
		else {
		printf("fichier non ouvert");
		}
		
		
	printf("[+]OK.\n");
	printf("[+]SEE YOU\n");
	return 0;
		
return 0;
}