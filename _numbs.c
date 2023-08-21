#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @mynum: number
 * @mybase: base
 * @myflags: argument flags
 * @myparams: paramater struct
 *
 * Return: string
 */
char *convert(long int mynum, int mybase, int myflags, params_t *myparams)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = mynum;
	(void)myparams;

	if (!(myflags & CONVERT_UNSIGNED) && mynum < 0)
	{
		n = -mynum;
		sign = '-';
	}
	array = myflags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % mybase];
		n /= mybase;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @arg: argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list arg, params_t *myparams)
{
	unsigned long l;

	if (myparams->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (myparams->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	myparams->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, myparams), myparams));
}



/**
 * print_address - prints address
 * @arg: argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list arg, params_t *myparams)
{
	unsigned long int n = va_arg(arg, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, myparams);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, myparams));
}

