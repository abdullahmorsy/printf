#include "main.h"

int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	char *p, *percent;

	va_start(args, format);

	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			percent = p;
			p++;

			switch (*p)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
			}

			p++;
		}
		else
		{
			count += _putchar(*p);
		}
	}

	va_end(args);

	return count;
}
