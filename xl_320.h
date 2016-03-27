#ifndef XL_320_H
#define	XL_320_H

unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);

typedef struct{
	uint32_t HEADER;
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
	uint8_t INST;
	uint8_t * PARAM;
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
	MODEL_NUMBER=0x00,
	FIRMWARE_VERSION=0x02,
	ID=0x03,
	BAUDRATE=0x04,
	RETURN_DELAY_TIME=0x05,
	CW_ANGLE_LIMIT=0x06,
	CCW_ANGLE_LIMIT=0x08,
	CONTROL_MODE=0x11,
	LIMIT_TEMPERATURE=0x12,
	LOWER_LIMIT_VOLTAGE=0x13,
	UPPER_LIMIT_VOLTAGE=0x14,
	MAX_TORQUE=0x15,
	RETURN_LEVEL=0x17,
	ALARM_SHUTDOWN=0x18,
	TORQUE_ENABLE=0x24,
	LED=0x25,
	D_GAIN=0x27,
	I_GAIN=0x28,
	P_GAIN=0x29,
	GOAL_POSITION=0x30,
	GOAL_VELOCITY=0x32,
	GOAL_TORQUE=0x35,
	PRESENT_POSITION=0x37,
	PRESENT_SPEED=0x39,
	PRESENT_LOAD=0x41,
	PRESENT_VOLTAGE=0x45,
	PRESENT_TEMPERATURE=0x46,
	REGISTERED_INSTRUCTION=0x47,
	MOVING=0x49,
	HDW_ERROR_STATUS=0x50,
	PUNCH=0x51,
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

#endif	/* XL_320 */
