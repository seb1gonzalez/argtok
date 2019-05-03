/*
 * Banking Protocol
 *
 */

/* Bank Transaction Types */
#define BANK_TRANS_DEPOSIT    0
#define BANK_TRANS_WITHDRAW   1
#define BANK_TRANS_INQUIRY    2

typedef struct
{
    unsigned int trans;		/* transaction types */
    unsigned int acctnum;	/* account number */
    unsigned int value;		/* value */
} sBANK_PROTOCOL;
int setupTCPClient(char *servIPAddr, unsigned int portNum);
int atoi(char *str);
int close(int socket);
