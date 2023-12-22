
											/***how to implement state machine for "dra3 el eshara ll3rbya"****/
#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#define	LEFT_FRONT	PINA0
#define	LEFT_BACK	PINA1
#define	RIGHT_FRONT	PINA2
#define	RIGHT_BACK	PINA3

#define LEFT_B		PINC0
#define RIGHT_B		PINC1
#define WAIT_B		PINC2

typedef enum{
	IDLE_S,
	LEFT_S,
	RIGHT_S,
	WAIT_S
	}State_type;
	
typedef enum{
	LEFT_BUTTON,
	RIGHT_BUTTON,
	WAIT_BUTTON	
	}Transition_type;
	
void Idle(void);
void Left(void);
void Right(void);
void Wait(void);

Transition_type Get_Transition(void);
void CAR_Running(void);
void CAR_Init(void);
#endif /* STATEMACHINE_H_ */