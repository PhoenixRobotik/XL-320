#include <stdint.h>
#include <stdio.h>
#include "xl_320.h"

int main(void)
{
	_INSTR_FRAME test;
	test.HEADER=XL_320_HEADER;
	printf("0x%08x\n",*((char*)(&test.HEADER+1*sizeof(char))));
	test.ID=BROADCAST_ID;
	test.INSTR=PING;
	test.LEN=3;
	//test.LEN=0x0201;
	char instr_buff[255];
	uint8_t instr_buff_len; 
	get_instruction_string(test, instr_buff,255, &instr_buff_len);
	int i;
	for(i=0;i<instr_buff_len;i++)
	{
			printf("\\x%08x",instr_buff[i]);
	}
	printf("\n");
	printf("0x%08x\n",test.LEN_H);
	uint8_t data_blk[11]={0xFF,0xFF,0xFD,0x00,0xFE,0x06,0x00,0x03,0x25,0x00,0x03};
	printf("0x%08x\n",update_crc(0,data_blk,11));
	return 0;
}
