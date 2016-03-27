#ifndef XL_320_H
#define	XL_320_H

#define XL_320_HEADER 0xFFFFFD00
#define BROADCAST_ID 0xFE

typedef struct{
	union {
		struct {
			uint32_t HEADER;
		};
		struct {
			uint8_t RES;
			uint8_t H_BYTE1;
			uint8_t H_BYTE2;
			uint8_t H_BYTE3;
		};
	};
	uint8_t ID;
	union {
		struct {
			uint16_t LEN;
		};
		struct {
			uint8_t LEN_L;
			uint8_t LEN_H;
		};
	};
	uint8_t INSTR;
	uint8_t * PARAM;
	//uint8_t PARAM_LEN; usefull ?
	union {
		struct {
			uint16_t CRC;
		};
		struct {
			uint8_t CRC_L;
			uint8_t CRC_H;
		};
	};
} _INSTR_FRAME;

//http://support.robotis.com/en/product/dynamixel/xl-320/xl-320.htm
typedef enum {
	MODEL_NUMBER=00,
	FIRMWARE_VERSION=02,
	ID=03,
	BAUDRATE=04,
	RETURN_DELAY_TIME=05,
	CW_ANGLE_LIMIT=06,
	CCW_ANGLE_LIMIT=08,
	CONTROL_MODE=11,
	LIMIT_TEMPERATURE=12,
	LOWER_LIMIT_VOLTAGE=13,
	UPPER_LIMIT_VOLTAGE=14,
	MAX_TORQUE=15,
	RETURN_LEVEL=17,
	ALARM_SHUTDOWN=18,
	TORQUE_ENABLE=24,
	LED=25,
	D_GAIN=27,
	I_GAIN=28,
	P_GAIN=29,
	GOAL_POSITION=30,
	GOAL_VELOCITY=32,
	GOAL_TORQUE=35,
	PRESENT_POSITION=37,
	PRESENT_SPEED=39,
	PRESENT_LOAD=41,
	PRESENT_VOLTAGE=45,
	PRESENT_TEMPERATURE=46,
	REGISTERED_INSTRUCTION=47,
	MOVING=49,
	HDW_ERROR_STATUS=50,
	PUNCH=51,
} _XL_320_ADRR;

//http://support.robotis.com/en/product/dynamixel_pro/communication/instruction_status_packet.htm
typedef enum {
	PING=0x01,
	READ=0x02,
	WRITE=0x03,
	REG_WRITE=0x04,
	ACTION=0x05,
	FACTORY_RESET=0x06,
	REBOOT=0x08,
	STATUS=0x55,
	SYNC_READ=0x82,
	SYNC_WRITE=0x83,
	BULK_READ=0x92,
	BULK_WRITE=0x93,
} _XL_320_INSTRUCTION;


void get_instruction_string(_INSTR_FRAME instruction, char * instr_buff, int max_len, uint8_t * instr_buff_len);
_INSTR_FRAME build_instruction_frame(_XL_320_INSTRUCTION instruction, uint8_t device_id, uint8_t * parameters, uint8_t parameters_length);
unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);

#endif	/* XL_320 */
