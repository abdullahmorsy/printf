#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list arg;
	char *p, *start;

	params_t myparams = PARAMS_INIT;

	va_start(arg, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&myparams, arg);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &myparams))
		{
			p++;
		}
		p = get_width(p, &myparams, arg);
		p = get_precision(p, &myparams, arg);
		if (get_modifier(p, &myparams))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					myparams.l_modifier || myparams.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, arg, &myparams);
	}
	_putchar(BUF_FLUSH);
	va_end(arg);
	return (sum);
}
