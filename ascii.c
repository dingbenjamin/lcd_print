/*************************************************************************
Title: Game Console ASCII functions
Initial Author:   Benjamin Ding - 694920
Software: AVR-GCC 
Hardware: ATMEGA16 @ 8Mhz 

DESCRIPTION:
	Write ASCII letters to LCD function, currently only has upper case alphabet

*************************************************************************/

#include "ascii.h"

// Define this as 1 or 0 depending on orientation of screen
#define REVERSE_ROW 1
#define REVERSE_COL 1

unsigned char reverse_byte(unsigned char b) {
	if(REVERSE_ROW) {
	   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	}
   return b;
}

void write_char_a( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFC ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xFC ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_b( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x6C ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_c( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_d( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_e( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_f( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_g( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x62 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_h( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_i( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_j( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x62 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x7E ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_k( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x28 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x44 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_l( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_m( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x4 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x8 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x8 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x4 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_n( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x4 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x8 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x20 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x40 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_o( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_p( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xC ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_q( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0xA2 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x42 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xBC ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_r( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x32 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x52 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x8C ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_s( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x8C ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x62 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_t( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_u( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_v( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x6 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x18 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x60 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x60 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x18 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x6 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_w( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x7E ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x70 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x7E ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_x( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x44 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x28 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x10 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x28 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x44 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_y( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x4 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x8 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0xF0 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x8 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x4 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_z( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0);
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0xC2 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0xA2 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x8A ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x86 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}
