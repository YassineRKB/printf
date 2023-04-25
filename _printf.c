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
	int i, c = 0;
	char *str, ch;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'))
		{
			c += _putchar(format[i]);
			if (format[i + 1] == 'c')
			{
				ch = va_arg(ap, int);
				c += _putchar(ch), i++;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(ap, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					_putchar(*str);
					str++;
				}
				c += strlen(str), i++;
			}
		}
		else if (format[i] == '\0')
		{
			return (-1);
		}
		else
		{
			c += _putchar(format[i]);
		}
	} va_end(ap);
	return (c);
}
