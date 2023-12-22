
#include "StdTypes.h"
#include "MemoryMap.h"
#include "Utils.h"

#include "DIO_Interface.h"
#include "CAR_Lights.h"

#define  F_CPU	8000000
#include <util/delay.h>


int main(void)
{
	CAR_Init();
    while (1) 
    {
		CAR_Running();
    }
}
