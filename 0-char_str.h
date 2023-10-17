#ifndef __STRINGS_H__
#define __STRINGS_H__

#include "main.h"

/**
  * check_null - checking null
  * @format: the string
  *
  * Description: if null or empty
  * Return: 1 if yes, 0 if not
  */
int check_null(const char *format)
{
		if (format == NULL)
		{
			return (1);
		}
		else if (format[0] == '\0')
		{
			return (1);
		}
		return (0);
}

/**
  * _strlen - length of a stirng
  * @str: the string
  *
  * Description: size of a string
  * Return: the length
  */
int _strlen2(char *str)
{
		int i;

		if (str == NULL || str[0] == '\0')
		{
			return (0);
		}
		for (i = 0 ; str[i] != '\0' ; i++)
		{
		}
		return (i);
}

/**
  * print_char - printing character
  * @c: the char
  *
  * Description: char to stdout
  * Return: the char
  */
int print_char(char c)
{
		return (write(1, &c, 1));
}

#endif /* __STRINGS_H__ */

