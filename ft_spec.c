#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: string of the format
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s))(va_list arg, myparams_t *myparams)

{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 * @s: string of the format
 * @arg: argument pointer
 * @myparams: the parameters struct
 * Return: the number of bytes printed
 */

int get_print_func(char *s, va_list arg, myparams_t *myparams)
{
	int (*f)(va_list, myparams_t *) = get_specifier(s);

	if (f)
		return (f(arg, myparams));
	return (0);
}

/**
 * get_flag - finds the flag functions
 * @s: the format string
 * @myparams: the parameters struct
 * Return: if flag was valid
 */

int get_flag(char *s, myparams_t *myparams)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = myparams->plus_flag = 1;
			break;
		case ' ':
			i = myparams->space_flag = 1;
			break;
		case '#':
			i = myparams->hashtag_flag = 1;
			break;
		case '-':
			i = myparams->minus_flag = 1;
			break;
		case '0':
			i = myparams->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier function
 * @s: string for format
 * @myparams: parameter structure
 * Return: if modifier was valid
 */

int get_modifier(char *s, myparams_t *myparams)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = myparams->h_modifier = 1;
			break;
		case 'l':
			i = myparams->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @myparams: the parameters struct
 * @arg: the argument pointer
 * Return: new pointer
 */

char *get_width(char *s, myparams_t *myparams, va_list arg)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(arg, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	myparams->width = d;
	return (s);
}

