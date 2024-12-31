#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>



int main(int argc,char *argv[]) {

    if(argc<2){
	perror("Erreur : Argument insuffisant");
	printf("Usage : %s Port \n",argv[0]);
	return 0;

    }
    int sock;
    struct sockaddr_in server;
    const char * host ="127.0.0.1";
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(host);
   
    printf("Scanning ports %d-%d on %s...\n", 0, 3000, host);

    for (int port = 0; port <= 3000; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    return 0;
}
