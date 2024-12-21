#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8;
typedef   signed char s8;
typedef          char c8;

typedef unsigned int u16;  // int == 2 bytes at Atmega32
typedef   signed int s16;

typedef unsigned long u32;
typedef   signed long s32;

#define NULL_PTR  ((void*)0)


typedef enum{
	FALSE,
	TRUE
	}bool_type;
typedef enum{
	OK,
	NOK,
	NULL,
	OUTOFRANGE
	}Error_Type;
	
#define MAX_U8  ((u8)255)    //(2^8)-1
#define MIN_U8  ((u8)0)   
#define MAX_S8  ((s8)127)   //(2^(8-1))-1
#define MIN_S8  ((s8)-128)   //-(2^(8-1))

#define MAX_U16  ((u16)65535)   //(2^16)-1
#define MIN_U16  ((u16)0)   
#define MAX_S16  ((s16)32767)  //(2^(16-1))-1
#define MIN_S16  ((s16)-32768)  //-(2^(16-1))

#define MAX_U32  ((u32)4294967295)   //(2^32)-1
#define MIN_U32  ((u32)0)   
#define MAX_S32  ((s32)2147483647)   //(2^(32-1))-1
#define MIN_S32  ((s32)-2147483648)   //-(2^(32-1))

#endif /* STDTYPES_H_ */
