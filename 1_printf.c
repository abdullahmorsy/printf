#include "main.h"

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list arg;

	va_start(arg, format);

	if (!format)
		return (-1);

	for (const char *p = format; *p; p++)
	{
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}

		p++; // Move past '%'

		if (*p == '\0')
			return (-1); // Incomplete format specifier

		if (*p == 'c')
		{
			char c = va_arg(arg, int);
			sum += _putchar(c);
		}
		else if (*p == 's')
		{
			char *str = va_arg(arg, char *);
			if (str == NULL)
				str = NULL_STRING;

			// Handle precision for the 's' specifier
			char *precision = get_precision(p + 1, &myparams, arg);
			int max_chars = (precision != NULL) ? atoi(precision) : -1;

			if (max_chars == -1 || _strlen(str) < max_chars)
				sum += _puts(str);
			else
				sum += print_from_to(str, str + max_chars, NULL);

			// Move past the precision specifier (if present)
			while (_isdigit(*p))
				p++;
		}
		else if (*p == '%')
		{
			sum += _putchar('%');
		}
		else
		{
			// Unsupported format specifier, ignore it
		}
	}

	va_end(arg);
	return (sum);
}

