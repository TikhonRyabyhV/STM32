/*
 * my_lcd.c
 *
 *  Created on: 15 мая 2024 г.
 *      Author: Tiray
 */
#include "my_lcd.h"

const char  nums_sym[]  = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };



BUTTON_st* CreateButton ( uint16_t x, uint16_t y, uint16_t length, uint16_t height, char *name, unsigned char name_len ) {
	if( name == NULL )
		return NULL;

	BUTTON_st *res = (BUTTON_st *) calloc( sizeof(BUTTON_st), 1 );
	if( res == NULL )
		return NULL;

	res->X = x;
	res->Y = y;
	res->length = length;
	res->height = height;
	res->name = name;
	res->name_len = name_len;

	return res;
}

void DestroyButton ( BUTTON_st *button ) {
	if( button == NULL )
		return;

	free(button);
}

void DrawButton ( BUTTON_st *button ) {
	uint16_t indent_x =  (button->length - 17 * button->name_len) / 2;
	uint16_t indent_y =  (button->height - 20) / 2;

	 BSP_LCD_DisplayStringAt(button->X + indent_x, button->Y + indent_y, (uint8_t *) button->name, LEFT_MODE);
	 BSP_LCD_DrawRect(button->X, button->Y, button->length, button->height);

}

int CheckButton ( BUTTON_st *button, uint16_t x, uint16_t y ) {


	if((x >= button->X && x <= (button->X + button->length)) && (y >= button->Y && y <= (button->Y + button->height)))
		return 1;
	else
		return 0;
}

void My_strcpy (char *dst, char *src, int from, int to) {
	if( dst == NULL || src == NULL || from < 0 || to < 0 || to < from)
		return;

	for( int i = from; i < to; ++i )
		dst[i] = src[i];

	return;
}

int deg( int base, int deg ) {
	if( deg < 0 )
		return 0;

	int res = 1;
	for( int i = 0; i < deg; ++i )
		res *= base;

	return res;
}

int str2num (char *string, int size) {
	if( string == NULL )
		return -1;

	unsigned int res = 0;
	for( int i = size - 1; i >= 0; --i )
		res += ((string[i] - '0') * deg(10, size - i - 1));

	return res;
}

void DrawWhiteRect (uint16_t x, uint16_t y, uint16_t length, uint16_t height) {

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(x, y, length, height);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	return;
}
void PrintInTRS( char *TRS_line, char *CHAR_line, int *cnt_t, int *char_flag ) {
	if(TRS_line == NULL || CHAR_line == NULL)
		return;

	if( (*char_flag) == 1 && (*cnt_t < TRS_SIZE - 1) ) {
		TRS_line[(*cnt_t)] = CHAR_line[0];
		CHAR_line[0] = '\0';

		++(*cnt_t);
		(*char_flag) = 0;

		TRS_line[(*cnt_t)] = '\0';
	}

	return;
}


void PreConvert ( char *ASCII_line, char *CHAR_line, int *char_flag ) {
	char symbol = '\0';
	int intermed = str2num(ASCII_line, 3);

	if( intermed >= 0 && intermed <= 127 )
		symbol = intermed;

	if( symbol >= 32 && symbol <= 126 ) {
		CHAR_line[0] = symbol;
		CHAR_line[1] = '\0'  ;

		(*char_flag) = 1;
	}

	else {
		CHAR_line[0] = 'E' ;
		CHAR_line[1] = 'R' ;
		CHAR_line[2] = 'R' ;
		CHAR_line[3] = '\0';
	}

	return;
}

void DeleteSymbol ( char *line, int *line_iter ) {

	int i = (*line_iter);
	if( i > 0 ) {
		--i;
		line[i] = '\0';
	}

	(*line_iter) = i;

	return;
}

void ButtonResponse ( uint16_t x, uint16_t y, BUTTON_st **but_array, char *ASCII_line, char *TRS_line, char *RCV_line, char *CHAR_line, int *cnt_a, int *cnt_t, int *cnt_r, int *char_flag ) {

	if( but_array == NULL )
		return;

	int i_a = (*cnt_a), i_t = (*cnt_t), i_r = (*cnt_r);
	int i = 0;
	for( i = 0; i < 15; ++i ) {
		if( CheckButton(but_array[i], x, y) )
			break;
	}

	if( i < 10 && i >= 0 ) {
		if(i_a < ASCII_SIZE - 1) {
			ASCII_line[i_a] = nums_sym[i];
			++i_a;
		}

		if(i_a == ASCII_SIZE - 1)
			PreConvert( ASCII_line, CHAR_line, char_flag );

		ASCII_line[i_a] = '\0';
	}

	else {
		switch(i) {
			case 10:
				DeleteSymbol(ASCII_line, &i_a);
				CHAR_line[0] = '\0';
				break;

			case 11:
				DeleteSymbol(TRS_line  , &i_t);
				break;

			case 12:
				DeleteSymbol(RCV_line  , &i_r);
				break;

			case 13:
				PrintInTRS( TRS_line, CHAR_line, &i_t, char_flag );
				ASCII_line[0] = '\0';
				i_a = 0;
				break;

			case 14:
				SendData(TRS_line, &i_t);
				break;

			default:
				break;
		}
	}

	(*cnt_a) = i_a;
	(*cnt_t) = i_t;
	(*cnt_r) = i_r;

	return;

}

void UpdateScreen( BUTTON_st **but_array, char *ASCII_line, char *TRS_line, char *RCV_line, char *CHAR_line ) {

	DrawWhiteRect(but_array[10]->X + but_array[10]->length + 5, but_array[10]->Y + 10, 65 , 40);
	BSP_LCD_DisplayStringAt(but_array[10]->X + but_array[10]->length + 5, but_array[10]->Y + 10, (uint8_t *) ASCII_line, LEFT_MODE);

	DrawWhiteRect(but_array[11]->X + but_array[11]->length + 5, but_array[11]->Y + 10, 280 , 40);
	BSP_LCD_DisplayStringAt(but_array[11]->X + but_array[11]->length + 5, but_array[11]->Y + 10, (uint8_t *) TRS_line, LEFT_MODE);

	DrawWhiteRect(but_array[12]->X + but_array[12]->length + 5, but_array[12]->Y + 5, 280 , 40);
	BSP_LCD_DisplayStringAt(but_array[12]->X + but_array[12]->length + 5, but_array[12]->Y + 5, (uint8_t *) RCV_line, LEFT_MODE);

	DrawWhiteRect(290, 30, 60, 25);
	BSP_LCD_DisplayStringAt(290, 30, (uint8_t *) CHAR_line, LEFT_MODE);

}

void UpdateRCV ( char *RCV_line ) {
	DrawWhiteRect(85, 125, 280 , 40);
	BSP_LCD_DisplayStringAt(85, 125, (uint8_t *) RCV_line, LEFT_MODE);

}
