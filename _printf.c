# include "main.h"
# include <stdarg.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
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
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				c += write(1, '%', 1);
				return (1);
			}
			if (*format == 'c')
				ch = va_arg(ap, int), c += write(1, &ch, 1);
			else if (*format == 's')
			{
				str = va_arg(ap, char *);
				if (str == NULL)
					str = "(null)";
				c += write(1, str, strlen(str));
			} else if (*format == '\0')
			{
				return (-1);
			}
			else
			{
				c += _putchar('%');
				c += write(1, format, 1);
			}
		}
		else
			c += write(1, format, 1);
		format++;
	} va_end(ap);
	return (c);
}
