#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @arg: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list arg, params_t *myparams)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (myparams->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (myparams->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, myparams);
	if (myparams->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	myparams->unsign = 1;
	return (c += print_number(str, myparams));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @arg: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list arg, params_t *myparams)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (myparams->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (myparams->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, myparams);
	if (myparams->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	myparams->unsign = 1;
	return (c += print_number(str, myparams));
}
/**
 * print_binary - prints unsigned binary number
 * @arg: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list arg, params_t *myparams)
{
	unsigned int n = va_arg(arg, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, myparams);
	int c = 0;

	if (myparams->hashtag_flag && n)
		*--str = '0';
	myparams->unsign = 1;
	return (c += print_number(str, myparams));
}

/**
 * print_octal - prints unsigned octal numbers
 * @arg: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list arg, params_t *myparams)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (myparams->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (myparams->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, myparams);

	if (myparams->hashtag_flag && l)
		*--str = '0';
	myparams->unsign = 1;
	return (c += print_number(str, myparams));
}

