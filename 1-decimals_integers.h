#ifndef __DECIMALS_H
#define __DECIMALS_H
#include "main.h"

/**
  * digit_num - number of digits
  * @num: the number
  *
  * Description: digit num
  * Return: the number of digits
  */
int digit_num(int num)
{
		int i;

		for (i = 0 ; num ; i++)
		{
			num /= 10;
		}
		return (i);
}

/**
  * minus_handling - convert minus
  * @num: the number
  *
  * Description: converting minus number to string
  * Return: the converted string
  */
char *minus_handling(int num)
{
		int size = 1, i = 0, j = 0, min = 0;
		char *str, *str2;

		if (num != -2147483648)
		{
			num = -num;
			size += digit_num(num);
		}
		else
		{
			min = 1;
			num -= 1;
			size += 10;
		}
		str = malloc(sizeof(char) * (size + 1));
		str2 = malloc(sizeof(char) * (size + 1));
		if (min)
		{
			str[i] = ((num % 10) + '0') + 1;
			i++;
			num /= 10;
		}
		for (; num; i++)
		{
			str[i] = (num % 10) + '0';
			num /= 10;
		}
		str[i] = '-';
		str[++i] = '\0';
		for (i = i - 1, j = 0; i >= 0; i--, j++)
		{
			str2[j] = str[i];
		}
		str2[j] = '\0';
		return (str2);
}

/**
  * positive_handling - print positives
  * @num: the num
  *
  * Description: converting positive to string
  * Return: the converted string
  */
char *positive_handling(int num)
{
		char *str, *str2;
		int size, i, temp = num, j;

		size = digit_num(num);
		str = malloc(sizeof(char) * (size + 1));
		str2 = malloc(sizeof(char) * (size + 1));
		for (i = 0 ; temp ; i++)
		{
			str[i] = (temp % 10) + '0';
			temp /= 10;
		}
		str[i] = '\0';
		for (i = i - 1, j = 0; i >= 0 ; i--, j++)
		{
			str2[j] = str[i];
		}
		str2[j] = '\0';
		return (str2);
}

/**
  * printing_nums - print nums
  * @final_str: final string
  * @str_index: string index
  * @count: counter
  * @num: the number
  *
  * Description: handling 0, positives and negatives
  * Return: the returned string from the above functions
  */
char *printing_nums(char *final_str, unsigned int *str_index,
		unsigned int *count, int num)
{
		char *str;
		int i, j;

		if (num == 0)
		{
			str = malloc(2);
			str[0] = '0';
			str[1] = '\0';
		}
		else
		{
			if (num > 0)
			{
				str = positive_handling(num);
			}
			else
			{
				str = minus_handling(num);
			}
		}
		final_str = realloc(final_str, (sizeof(char) * (*str_index))
				+ _strlen(str, count) + 1);
		for (j = 0, i = (*str_index); str[j] != '\0'; j++, i++)
		{
			final_str[i] = str[j];
		}
		final_str[i] = '\0';
		(*str_index) = i;
		return (final_str);
}
#endif /* __DECIMALS_H */
