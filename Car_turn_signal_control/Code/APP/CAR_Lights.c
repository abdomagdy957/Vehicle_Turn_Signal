#include "StdTypes.h"
#include "MemoryMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "CAR_Lights.h"

#define  F_CPU	8000000
#include <util/delay.h>
void LeftButtonGetTransition(void);
void rightButtonGetTransition(void);
void waitButtonGetTransition(void);
Transition_type T;
//Transition_type buttonState = LEFT_BUTTON;
State_type currentState ;
State_type PreviousState;

void CAR_Init(void)
{
	DIO_Init();
	EXI_Init();
	EXI_SetCallBack(EX_INT0,&LeftButtonGetTransition);
	EXI_SetCallBack(EX_INT0,&rightButtonGetTransition);
	EXI_SetCallBack(EX_INT0,&waitButtonGetTransition);
	EXI_Enable(EX_INT0);
	EXI_Enable(EX_INT1);
	EXI_Enable(EX_INT2);
	currentState = IDLE_S;
	PreviousState = IDLE_S;
}
void CAR_Running(void)
{
	//T = Get_Transition();
	switch(currentState)
	{
		case IDLE_S:
		switch(T)
		{
			case LEFT_BUTTON:
			Left();
			currentState = LEFT_S;
			break;
			case RIGHT_BUTTON:
			Right();
			currentState = RIGHT_S;
			break;
			case WAIT_BUTTON:
			Wait();
			currentState = WAIT_S;
			PreviousState = IDLE_S;
		}
		case LEFT_S:
		switch(T)
		{
			case LEFT_BUTTON:
			Left();
			currentState = LEFT_S;
			break;
			case RIGHT_BUTTON:
			Idle();
			currentState = IDLE_S;
			break;
			case WAIT_BUTTON:
			Wait();
			currentState = WAIT_S;
			PreviousState = LEFT_S;
		}
		case RIGHT_S:
		switch(T)
		{
			case LEFT_BUTTON:
			Idle();
			currentState = IDLE_S;
			break;
			case RIGHT_BUTTON:
			Right();
			currentState = RIGHT_S;
			break;
			case WAIT_BUTTON:
			Wait();
			currentState = WAIT_S;
			PreviousState = RIGHT_S;
		}
		case WAIT_S:
		switch(T)
		{
			case LEFT_BUTTON:
			Wait();
			currentState = LEFT_S;
			break;
			case RIGHT_BUTTON:
			Wait();
			currentState = RIGHT_S;
			break;
			case WAIT_BUTTON:
			if(PreviousState == IDLE_S)
			{
				Idle();
				currentState = IDLE_S;
			}
			else if(PreviousState == RIGHT_S)
			{
				Right();
				currentState = RIGHT_S;
			}
			else if(PreviousState == LEFT_S)
			{
				Left();
				currentState = LEFT_S;
			}
			break;
		}
	}
}
void LeftButtonGetTransition(void)
{
	T = LEFT_BUTTON;
}
void rightButtonGetTransition(void)
{
	T = RIGHT_BUTTON;
}
void waitButtonGetTransition(void)
{
	T = WAIT_BUTTON;
}

/*
Transition_type Get_Transition(void)
{
	if(DIO_ReadPin(LEFT_B)==LOW)
	{
		buttonState = LEFT_BUTTON;
		_delay_ms(50);
	}
	else if(DIO_ReadPin(RIGHT_B)==LOW)
	{
		buttonState = RIGHT_BUTTON;
		_delay_ms(50);
	}
	else if(DIO_ReadPin(WAIT_B)==LOW)
	{
		buttonState = WAIT_BUTTON;
		_delay_ms(50);
	}
	else
	{
		
	}
	return buttonState;
}
*/
void Idle(void)
{
	DIO_WritePin(LEFT_FRONT,LOW);
	DIO_WritePin(LEFT_BACK,LOW);
	DIO_WritePin(RIGHT_FRONT,LOW);
	DIO_WritePin(RIGHT_BACK,LOW);
}
void Left(void)
{
	DIO_TogglePin(LEFT_FRONT);
	DIO_TogglePin(LEFT_BACK);
	DIO_WritePin(RIGHT_FRONT,LOW);
	DIO_WritePin(RIGHT_BACK,LOW);
	_delay_ms(400);
}
void Right(void)
{
	DIO_TogglePin(RIGHT_FRONT);
	DIO_TogglePin(RIGHT_BACK);
	DIO_WritePin(LEFT_FRONT,LOW);
	DIO_WritePin(LEFT_BACK,LOW);
	_delay_ms(400);
}
void Wait(void)
{
	DIO_TogglePin(LEFT_FRONT);
	DIO_TogglePin(LEFT_BACK);
	DIO_TogglePin(RIGHT_FRONT);
	DIO_TogglePin(RIGHT_BACK);
	_delay_ms(400);
}
