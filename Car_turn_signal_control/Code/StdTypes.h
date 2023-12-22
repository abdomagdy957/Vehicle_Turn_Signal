

#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char	u8;
typedef signed char	s8;

typedef unsigned short	u16;
typedef signed short	s16;

typedef unsigned long	u32;
typedef signed long	s32;
 
typedef enum{
	 FALSE,
	 TRUE
	 }Bool_t;

typedef enum{
	OK,
	NOK,
	NULLPTR,
	OUTOFRANGE
	}Error_t;

#define		NULL_PTR	((void*)0)
#define		NULL		0

#define		MIN_U8		((U8)0)
#define		MAX_U8		((u8)255)
#define		MIN_S8		((s8)-128)
#define		MAX_S8		((s8)127)
#define		ZERO_S8		((s8)0)		//if i want to put zero in signed variable




#endif /* STDTYPES_H_ */