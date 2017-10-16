/*************************************************************************
Title: Game Console ASCII functions
Initial Author:   Benjamin Ding - 694920
Software: AVR-GCC 
Hardware: ATMEGA16 @ 8Mhz 

DESCRIPTION:
	Write ASCII letters to LCD function, currently only has upper case alphabet

*************************************************************************/

#ifndef ASCII_H

#define ASCII_H

#include "values.h"
#include "lcd.h"

void write_char_a( byte text_page , byte text_column);
void write_char_b( byte text_page , byte text_column);
void write_char_c( byte text_page , byte text_column);
void write_char_d( byte text_page , byte text_column); 
void write_char_e( byte text_page , byte text_column); 
void write_char_f( byte text_page , byte text_column); 
void write_char_g( byte text_page , byte text_column); 
void write_char_h( byte text_page , byte text_column); 
void write_char_i( byte text_page , byte text_column); 
void write_char_j( byte text_page , byte text_column);
void write_char_k( byte text_page , byte text_column); 
void write_char_l( byte text_page , byte text_column); 
void write_char_m( byte text_page , byte text_column); 
void write_char_n( byte text_page , byte text_column); 
void write_char_o( byte text_page , byte text_column);
void write_char_p( byte text_page , byte text_column);
void write_char_q( byte text_page , byte text_column); 
void write_char_r( byte text_page , byte text_column); 
void write_char_s( byte text_page , byte text_column);
void write_char_t( byte text_page , byte text_column); 
void write_char_u( byte text_page , byte text_column); 
void write_char_v( byte text_page , byte text_column);
void write_char_w( byte text_page , byte text_column);
void write_char_x( byte text_page , byte text_column);
void write_char_y( byte text_page , byte text_column);
void write_char_z( byte text_page , byte text_column);

#endif
