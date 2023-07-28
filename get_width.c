#include "main.h"

/**
 * get_width1 - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width1(const char *format, int *i, va_list list)
{
	int cur_i;
	int w = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit1(format[cur_i]))
		{
			w *= 10;
			w += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (w);
}
