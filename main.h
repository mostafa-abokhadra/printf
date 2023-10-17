#ifndef __HEADER__
#define __HEADER__

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
char *put_char_in_final(char *final_str, char ch, unsigned int *str_index,
		unsigned int *count);
char *put_string_in_final(char *final_str, char *str, unsigned int *str_index,
		unsigned int *count);

int _strlen(char *str, unsigned int *count);
int check_null(const char *format);
int _strlen2(char *str);
char *printing_nums(char *final_str, unsigned int *str_index,
		unsigned int *count, int num);
char *positive_handling(int num);
char *minus_handling(int num);

#endif /* __HEADER__ */

