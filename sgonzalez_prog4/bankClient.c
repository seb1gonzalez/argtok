#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "banking.h"


/*
port 26208
ip 129.108.32.2



*/

int setupTCPClient(char *servIPAddr, unsigned int portNum)
{
    int clientSocket;
    struct sockaddr_in servAddr;

    /* Setup address of server */
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(servIPAddr);
    servAddr.sin_port = htons(portNum);

    /* Create socket */
    if((clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("Failed to create socket; Error %d: %s\n", errno, strerror(errno));
        return -1;
    }

    /* Connect socket to server */
    if(connect(clientSocket,(struct sockaddr *) &servAddr,sizeof(servAddr)) < 0)
    {
        printf("Failed to connect socket to %s:%d; Error %d: %s\n", servIPAddr, portNum, errno, strerror(errno));
        return -1;
    }

    return clientSocket;
}




int main(int argc, char **argv)
{
    int mySocket;
    char serverIP[15];
    unsigned int portNum;
    char recvBuff[1024];
    char sendString[100];

    if(argc != 6)
    {
        printf("Usage: bankClient servIPAddr servPortNum command acctNum value\n");
        return -1;
    }

	/* Setup the IP address */
	strcpy(serverIP, argv[1]);

	/* Setup TCP port number */
	portNum = atoi(argv[2]);

    /* Setup the client socket */
    if((mySocket = setupTCPClient(serverIP, portNum)) < 0)
    {
        return -1;
    }
/*instructions:
B for Balance
D for Desposit
W for withdrawal
command line arguments accepted:
bankClient servIPAddr servPortNum transaction acctNum value

example:
127.0.0.1 198.128.10.255 3306 D 123456 500
*/
     sBANK_PROTOCOL bank_sg = {
      .trans = htonl(atoi(argv[3])),
      .acctnum = htonl(atoi(argv[4])),
      .value = htonl(atoi(argv[5]))
    };
  //  for (int i=3; i < argc; i++){

      /* Setup the message */
    sprintf(sendString, "%s%s ", sendString, bank_sg.trans);
    sprintf(sendString, "%s%s ", sendString, bank_sg.acctnum);
    sprintf(sendString, "%s%s ", sendString, bank_sg.value);
//}
    sprintf(sendString, "%s\n", sendString);

    /* Send string to server */
    //char[128] message;

    //send(mySocket,bank_sg, sizeof(bank_sg), 0);
    send(mySocket,sendString, strlen(sendString), 0);
    //printf("Sent:\n%s\n", sendString);

    /* Receive a string from a server */
    recv(mySocket, recvBuff, 1023, 0);
    printf("Received:\n%s\n", recvBuff);


    close(mySocket);

}
