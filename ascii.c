/*************************************************************************
Title: Game Console ASCII functions
Initial Author:   Benjamin Ding - 694920
Software: AVR-GCC 
Hardware: ATMEGA16 @ 8Mhz 

DESCRIPTION:
	Write ASCII letters to LCD function, currently only has upper case 'alphabet

*************************************************************************/

#include "ascii.h"

// Define this as 1 or 0 depending on orientation of screen
#define REVERSE_ROW 1
#define REVERSE_COL 1

void print_num(int num, byte text_page, byte text_column) {
	char* num_str[MAX_NUM_DIGITS];
	itoa(num, num_str, 10);
	if(num < 10) {
		print_line(num_str, 2, text_page, text_column + CHAR_WIDTH);
		print_line("  ", 2, text_page, text_page + 2 * CHAR_WIDTH);
	} else if (num < 100) {
		print_line(num_str, 2, text_page, text_column + CHAR_WIDTH);
		print_line("  ", 1, text_page, text_page + 3 * CHAR_WIDTH);
	} else {
		print_line(num_str, text_page, text_page, text_column + CHAR_WIDTH);
	}
}

void print_line(char* string, uint8_t len, byte text_page, byte text_column) {
	char current_char;
	int current_char_index = 0;
	while(current_char_index < len && text_column < MAX_COLS) {
		current_char = string[current_char_index];

		switch(current_char) {
			
			case 'A':
			write_char_a(text_page, text_column);
			break;

			case 'B':
			write_char_b(text_page, text_column);
			break;

			case 'C':
			write_char_c(text_page, text_column);
			break;

			case 'D':
			write_char_d(text_page, text_column);
			break;

			case 'E':
			write_char_e(text_page, text_column);
			break;

			case 'F':
			write_char_f(text_page, text_column);
			break;

			case 'G':
			write_char_g(text_page, text_column);
			break;

			case 'H':
			write_char_h(text_page, text_column);
			break;

			case 'I':
			write_char_i(text_page, text_column);
			break;

			case 'J':
			write_char_j(text_page, text_column);
			break;

			case 'K':
			write_char_k(text_page, text_column);
			break;

			case 'L':
			write_char_l(text_page, text_column);
			break;

			case 'M':
			write_char_m(text_page, text_column);
			break;

			case 'N':
			write_char_n(text_page, text_column);
			break;

			case 'O':
			write_char_o(text_page, text_column);
			break;

			case 'P':
			write_char_p(text_page, text_column);
			break;

			case 'Q':
			write_char_q(text_page, text_column);
			break;

			case 'R':
			write_char_r(text_page, text_column);
			break;

			case 'S':
			write_char_s(text_page, text_column);
			break;

			case 'T':
			write_char_t(text_page, text_column);
			break;

			case 'U':
			write_char_u(text_page, text_column);
			break;

			case 'V':
			write_char_v(text_page, text_column);
			break;

			case 'W':
			write_char_w(text_page, text_column);
			break;

			case 'X':
			write_char_x(text_page, text_column);
			break;

			case 'Y':
			write_char_y(text_page, text_column);
			break;

			case 'Z':
			write_char_z(text_page, text_column);
			break;

			case ' ':
			write_char_space(text_page, text_column);
			break;
			
			case '-':
			write_char_dash(text_page, text_column);
			break;

			case '1':
			write_char_one(text_page, text_column);
			break;

			case '2':
			write_char_two(text_page, text_column);
			break;

			case '3':
			write_char_three(text_page, text_column);
			break;

			case '4':
			write_char_four(text_page, text_column);
			break;

			case '5':
			write_char_five(text_page, text_column);
			break;

			case '6':
			write_char_six(text_page, text_column);
			break;

			case '7':
			write_char_seven(text_page, text_column);
			break;

			case '8':
			write_char_eight(text_page, text_column);
			break;

			case '9':
			write_char_nine(text_page, text_column);
			break;

			case '0':
			write_char_zero(text_page, text_column);
			break;

			default:
			write_char_space(text_page, text_column);
		}
		text_column += CHAR_WIDTH;
		current_char_index++;
	}
}
		
	

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

void write_char_dash( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
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
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_space( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_one( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x84 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x80 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_two( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x84 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0xC2 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0xA2 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x8C ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_three( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x44 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x6C ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_four( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x30 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x28 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x24 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x20 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_five( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x9E ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x72 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_six( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0xFE ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0xF2 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_seven( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x2 ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x82 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x42 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x22 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x12 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0xE ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_eight( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_nine( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0xC ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}

void write_char_zero( byte text_page , byte text_column) { 
	lcd_select_page(text_page + 0); 
	text_column = REVERSE_COL ? MAX_COLS -text_column :text_column; 
	lcd_select_column(text_column - 0 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
	lcd_select_column(text_column - 1 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 2 ); 
	lcd_data( reverse_byte( 0xA2 ) ) ; 
	lcd_select_column(text_column - 3 ); 
	lcd_data( reverse_byte( 0x92 ) ) ; 
	lcd_select_column(text_column - 4 ); 
	lcd_data( reverse_byte( 0x8A ) ) ; 
	lcd_select_column(text_column - 5 ); 
	lcd_data( reverse_byte( 0x86 ) ) ; 
	lcd_select_column(text_column - 6 ); 
	lcd_data( reverse_byte( 0x7C ) ) ; 
	lcd_select_column(text_column - 7 ); 
	lcd_data( reverse_byte( 0x0 ) ) ; 
}
