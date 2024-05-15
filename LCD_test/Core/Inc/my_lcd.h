/*
 * my_lcd.h
 *
 *  Created on: 15 мая 2024 г.
 *      Author: Tiray
 */

#ifndef INC_MY_LCD_H_
#define INC_MY_LCD_H_

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BUTTON {
	uint16_t 		X;
	uint16_t 		Y;
	uint16_t 		length;
	uint16_t 		height;
	char     		*name;
	unsigned char	name_len;
} BUTTON_st;

#define ASCII_SIZE 4
#define CHAR_SIZE  4
#define TRS_SIZE   14
#define RCV_SIZE   14

#define ScanScreen                  						\
		do {												\
			if( rcv_flag ) {								\
				My_strcpy(RCV_line, rcv_line, 0, rcv_flag); \
				cnt_r = rcv_flag;							\
				rcv_flag = 0;								\
				RCV_line[cnt_r] = '\0';						\
				UpdateRCV(RCV_line);						\
			}												\
															\
			BSP_TS_GetState( &ts ); 						\
			HAL_Delay(50);          						\
			} while( !ts.touchDetected ) ;   				\

BUTTON_st* CreateButton ( uint16_t x, uint16_t y, uint16_t length, uint16_t height, char *name, unsigned char name_len );

void DestroyButton ( BUTTON_st *button );

void DrawButton ( BUTTON_st *button );

int CheckButton ( BUTTON_st *button, uint16_t x, uint16_t y );

void DrawWhiteRect (uint16_t x, uint16_t y, uint16_t length, uint16_t height);

void PrintInTRS( char *TRS_line, char *CHAR_line, int *cnt_t, int *char_flag );

void SendData ( char *TRS_line, int *cnt_t );

void PreConvert ( char *ASCII_line, char *CHAR_line, int *char_flag );

void DeleteSymbol ( char *line, int *line_iter );

void ButtonResponse ( uint16_t x, uint16_t y, BUTTON_st **but_array, char *ASCII_line, char *TRS_line, char *RCV_line, char *CHAR_line, int *cnt_a, int *cnt_t, int *cnt_r, int *char_flag );

void UpdateScreen( BUTTON_st **but_array, char *ASCII_line, char *TRS_line, char *RCV_line, char *CHAR_line );

void My_strcpy (char *dst, char *src, int from, int to);

int deg( int base, int deg );

int str2num (char *string, int size);



#endif /* INC_MY_LCD_H_ */
