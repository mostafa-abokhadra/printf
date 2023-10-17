#include "main.h"
#include "0-char_str.h"
#include "1-decimals_integers.h"

/**
  * _strlen - length
  * @str: string
  * @count: count
  *
  * Description: counting length
  * Return: length
  */
int _strlen(char *str, unsigned int *count)
{
		unsigned int i;

		if (str == NULL || str[0] == '\0')
		{
			return (0);
		}
		for (i = 0 ; str[i] != '\0' ; i++)
		{
		}
		(*count) += i;
		return (i);
}

/**
  * put_string_in_final - putting str in final
  * @final_str:  final str
  * @str: string
  * @str_index: final str index
  * @count: count
  *
  * Description: putting string arg in buffer
  * Return: buffer
  */
char *put_string_in_final(char *final_str, char *str, unsigned int *str_index,
		unsigned int *count)
{
		unsigned int i, re_size = 0, j = 0;

		re_size =  (sizeof(char) * (*str_index))
			+ _strlen(str, count) + 1;
		final_str = realloc(final_str, re_size);
		for (i = (*str_index); i < re_size && str[j] != '\0'; i++, j++)
		{
			final_str[i] = str[j];
		}
		final_str[i] = '\0';
		(*str_index) = i;
		return (final_str);
}

/**
  * put_char_in_final - printing character
  * @final_str: final string
  * @ch: char
  * @str_index: index
  * @count: counter
  *
  * Description: character to buffer
  * Return: buffer
  */
char *put_char_in_final(char *final_str, char ch, unsigned int *str_index,
		unsigned int *count)
{
		unsigned int i;

		(*count)++;
		final_str = realloc(final_str, ((sizeof(char) * (*str_index))
					+ 2));
		for (i = (*str_index) ; i <= (*str_index); i++)
		{
			final_str[i] = ch;
		}
		final_str[i] = '\0';
		(*str_index)++;
		return (final_str);
}

/**
  * _printf - printing to stdout
  * @format: formated string
  *
  * Description: print string and args
  * Return: number of printed nums
  */
int _printf(const char *format, ...)
{
		unsigned int count = 0, i, final_str_index = 0;
		char *final_str = malloc(sizeof(char));
		va_list ptr;

		if (check_null(format))
			return (-1);
		va_start(ptr, format);
		for (i = 0; format[i] != '\0'; i++)
		{
			if (final_str != NULL)
			{
				if (format[i] != '%')
					final_str = put_char_in_final(final_str,
							format[i], &final_str_index, &count);
				else if (format[i] == '%')
				{
					if (format[i + 1] == 'c')
						final_str = put_char_in_final(final_str, va_arg(ptr, int),
								&final_str_index, &count);
					else if (format[i + 1] == 's')
						final_str = put_string_in_final(final_str, va_arg(ptr, char *),
								&final_str_index, &count);
					else if (format[i + 1] == '%')
						final_str = put_char_in_final(final_str, '%',
								&final_str_index, &count);
					else if (format[i + 1] == 'd' || format[i + 1] == 'i')
						final_str = printing_nums(final_str, &final_str_index,
								&count, va_arg(ptr, int));
					else
					{
						final_str = put_char_in_final(final_str, '%',
								&final_str_index, &count);
						continue;
					} i++;
				}
			}
		}
		va_end(ptr);
		write(1, final_str, _strlen2(final_str));
		return (count);
}


