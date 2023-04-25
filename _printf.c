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
	int i, c = 0;
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
				c += write(1, "%", 1);
			else if (*format == 'c')
				ch = va_arg(ap, int), c += write(1, &ch, 1);
			else if (*format == 'd')
				i = va_arg(ap, int), c += prind(i, 0);
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
				c += write(1, "%", 1), c += write(1, format, 1);
		}
		else
			c += write(1, format, 1);
		format++;
	} va_end(ap);
	return (c);
}
/**
* prind - handles %d number print
* @n: number to print
* @r: len of %d
* Return: len
**/
int prind(int n, int r)
{
	int i = r;

	if (n < 0)
		n = -n;
	if (n != 0)
	{
		prind(n / 10, i++);
		_putchar((n % 10) + '0');
	}
	return (i);
}
