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

/*
instructions:
B for Balance
D for Desposit
W for Withdrawal

command line arguments accepted:
bankClient servIPAddr servPortNum transaction acctNum value

Example:
./bankClient 129.108.32.2 26207 B  666 0

  /*Create the struct, reading the command line arguments*/
  sBANK_PROTOCOL bank_sg = {
    .acctnum = atoi(argv[4]),
    .value = atoi(argv[5])
  };

    /*Set Transaction*/
  if(strcmp(argv[3],"B") == 0){
    bank_sg.trans = BANK_TRANS_INQUIRY;
  }
  else if(strcmp(argv[3],"D") == 0){
    bank_sg.trans = BANK_TRANS_DEPOSIT;
  }
  else if(strcmp(argv[3],"W") == 0){
    bank_sg.trans = BANK_TRANS_WITHDRAW;
  }
  else{
    return -1;
  }

//How to send struct? stackoverflow says it's crazy
  /* Send protocol to server */
  send(mySocket,&bank_sg, sizeof(bank_sg), 0);// the & fixed everything, :| it's always the little things



  /* Receive a protocol from a server */
  sBANK_PROTOCOL response;
  recv(mySocket, &response, sizeof(response), 0);

  //Handle results VALUE = PENNIES!

/*Withdrawal Response*/
if(response.trans == BANK_TRANS_WITHDRAW){
  printf("%s for account %d\n","Withdrawal",response.acctnum);
  if(response.value <= 0){
    printf("%s\n","Can't process transaction, insufficient funds :(" );
  }
  else{
    int dollars = response.value / 100;
    int cents = response.value % 100;
    printf("Here you go: $ %d . %d\n",dollars,cents);
  }
}
/*Deposit Response*/
if(response.trans == BANK_TRANS_DEPOSIT){
  int dollars = response.value / 100;
  int cents = response.value % 100;
  printf("Account number: %d\n",response.acctnum);
  printf("%s :%d . %d\n", "You desposited",dollars,cents);
}

/*Balance Response*/
if (response.trans == BANK_TRANS_INQUIRY) {
  int dollars = response.value / 100;
  int cents = response.value % 100;
  printf("Account number %d\n",response.acctnum );
  printf("Current Balance: $ %d.%d \n",dollars,cents);
}



  close(mySocket);
}
