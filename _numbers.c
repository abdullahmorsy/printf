#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @myparams: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *myparams)
{
	unsigned int i = _strlen(str);
	int neg = (!myparams->unsign && *str == '-');

	if (!myparams->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (myparams->precision != UINT_MAX)
		while (i++ < myparams->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!myparams->minus_flag)
		return (print_number_right_shift(str, myparams));
	else
		return (print_number_left_shift(str, myparams));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @myparams: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *myparams)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (myparams->zero_flag && !myparams->minus_flag)
		pad_char = '0';
	neg = neg2 = (!myparams->unsign && *str == '-');
	if (neg && i < myparams->width && pad_char == '0' && !myparams->minus_flag)
		str++;
	else
		neg = 0;
	if ((myparams->plus_flag && !neg2) ||
		(!myparams->plus_flag && myparams->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (myparams->plus_flag && !neg2 && pad_char == '0' && !myparams->unsign)
		n += _putchar('+');
	else if (!myparams->plus_flag && myparams->space_flag && !neg2 &&
		!myparams->unsign && myparams->zero_flag)
		n += _putchar(' ');
	while (i++ < myparams->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (myparams->plus_flag && !neg2 && pad_char == ' ' && !myparams->unsign)
		n += _putchar('+');
	else if (!myparams->plus_flag && myparams->space_flag && !neg2 &&
		!myparams->unsign && !myparams->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @myparams: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *myparams)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (myparams->zero_flag && !myparams->minus_flag)
		pad_char = '0';
	neg = neg2 = (!myparams->unsign && *str == '-');
	if (neg && i < myparams->width && pad_char == '0' && !myparams->minus_flag)
		str++;
	else
		neg = 0;

	if (myparams->plus_flag && !neg2 && !myparams->unsign)
		n += _putchar('+'), i++;
	else if (myparams->space_flag && !neg2 && !myparams->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < myparams->width)
		n += _putchar(pad_char);
	return (n);
}
