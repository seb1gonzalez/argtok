//READ from a buffer
/*
Write a read function in C that will read a specific block (block = 128 words)
using the storage device with the 2 register interface below.
Buffer has enough memory allocated to accomodate 128 words

--------------------------------------------------------------
    - - - - -  REG 1 0xFF00 - - - - - - - -
    |0       | Status (0 idle/1 busy)[Read Only]
    |1       | Operation (0 read/1 write)[Read Write]
    |8:15    | 8-bit word number [Write Only]
    |16:31   | 16-bit block number [Write Only]
    - - - - - REG 2 0xFF04 - - - - - - - - - -
    |0:31    | 32-bit word [Read Write]
----------------------------------------------------------------
*/
int read(unsigned int blockNum, unsigned int buffer[]){
  volatile unsigned int *cmdReg = 0xFF00;
  volatile unsigned int *dataReg = 0xFF04;
  unsigned int i;
  //wait for device to be IDLE
  while((*cmdReg & 0x1));
  for (i = 0; i < 128; i++) {
    //read word i in blockNum
    *cmdReg = ((i & 0xFF)<<8) | ((blockNum & 0xFFFF)<<16))
    //wait until the value is read
    while((*cmdReg & 0x1));
    buffer[i] = *dataReg;
  }
  return 1;
}


//WRITE from a buffer
/*
--------------------------------------------------------------
    - - - - -  REG 1 0xFF00 - - - - - - - -
    |0       | Status (0 idle/1 busy)[Read Only]
    |1       | Operation (0 read/1 write)[Read Write]
    |8:15    | 8-bit word number [Write Only]
    |16:31   | 16-bit block number [Write Only]
    - - - - - REG 2 0xFF04 - - - - - - - - - -
    |0:31    | 32-bit word [Read Write]
----------------------------------------------------------------
*/
int write(unsigned int blockNum, unsigned int buffer[]){
  volatile unsigned int *cmdReg = 0xFF00;
  volatile unsigned int *dataReg = 0xFF04;
  unsigned int i;
  //wait for device to be IDLE
  while((*cmdReg & 0x1));
  for (i = 0; i < 128; i++) {
    //read word i in blockNum
    *dataReg = buffer[i]; //write from Buffer
    *cmdReg = ((1<<1) | (i << 8) | (blockNum << 16));
    //wait until the value is written
    while((*cmdReg & 0x1));
  }
  return 1;
}
