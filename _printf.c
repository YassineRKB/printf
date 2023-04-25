# include "main.h"
# include <stdarg.h>
# include <stddef.h>
# include <string.h>

/**
* _printf - function that produces output according to a format.
* @format: format
* Return: prints value
**/

int _printf(const char *format, ...)
{
	int c = 0;
	char *str, ch;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
		{
			c += _putchar(*format);
			if (*(format + 1) == 'c')
			{
				ch = va_arg(ap, int);
				c += _putchar(ch);
			}
			else if (*(format + 1) == 's')
			{
				str = va_arg(ap, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					_putchar(*str);
					str++;
				}
				c += strlen(str);
			}
		}
		else if (*format == '\0')
		{
			return (-1);
		}
		else
			c += _putchar(*format);
		format++;
	} va_end(ap);
	return (c);
}
