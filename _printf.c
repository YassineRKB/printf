# include "main.h"
# include <stdarg.h>
# include <stddef.h>

/**
* _printf - function that produces output according to a format.
* @format: format
* Return: prints value
**/

int _printf(const char *format, ...)
{
	int i, c = 0, len = 0;
	char *str, ch;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			_putchar(format[i]), c++;
		}
		else if (format[i + 1] == 'c')
		{
			ch = va_arg(ap, int);
			_putchar(ch), c++;
		}
		else if (format[i + 1] == 's')
		{
			str = va_arg(ap, char *);
			if (str == NULL)
				str = "(null)";
			while (str[len])
			{
				_putchar(str[len]);
			}
			c += len;
		}
		else if (format[i] == '\0')
		{
			return (-1);
		}
		else
		{
			_putchar(format[i]), c++;
		}
	} va_end(ap);
	return (c);
}
