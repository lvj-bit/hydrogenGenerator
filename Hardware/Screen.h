#ifndef __SCREEN_H
#define __SCREEN_H

typedef enum 
{
	sRes_Init =0,
	sRes_Open = 1,
	sRes_Close = 2,
	sRes_Pause = 3
	
}ScreenResStatus;	

typedef struct ScreenResult
{
	uint16_t OpenState;
	
}ScreenResult;

extern  ScreenResult *sResult;

void Screen_Init(void);

#endif