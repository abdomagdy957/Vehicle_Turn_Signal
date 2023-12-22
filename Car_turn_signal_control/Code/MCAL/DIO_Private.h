

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];

static void DIO_InitPin(DIO_Pin_type pin, DIO_PinStatus_type status);
static void DIO_InitPin_2(DIO_Port_type port, u8 pin_num, DIO_PinStatus_type status);

#endif /* DIO_PRIVATE_H_ */