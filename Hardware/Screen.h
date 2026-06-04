#ifndef __SCREEN_H
#define __SCREEN_H

typedef struct ScreenResult
{
	uint16_t OpenState;
	
}ScreenResult;

extern  ScreenResult *sResult;

void Screen_Init(void);

#endif