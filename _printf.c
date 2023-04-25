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
				i = va_arg(ap, int), c += prind(i, 0, 0);
			else if (*format == 'i')
				i = va_arg(ap, int), c += prind(i, 0, 1);
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
* @si: flag
* Return: len
**/
int prind(int n, int r, int si)
{
	int i = r;

	if (si == 0)
	{
		if (n < 0)
		{
			n = -n;
			_putchar('-');
			i++;
		}
		if (n != 0)
		{
			prind(n / 10, i++, si);
			_putchar((n % 10) + '0');
		}
	}
	if (si == 1)
	{
		char buffer[21];
		int k;

		handli(n, buffer);
		for (k = 0; buffer[k] != '\0'; k++)
		{
			_putchar(buffer[k]);
			i++;
		}
	}

	return (i);
}
/**
* handli - convert int to string
* @i: int
* @b: string
* Return: string.
**/
char *handli(int i, char b[])
{
	char const digits[] = "0123456789";
	char *p = b;
	int shift;

	if (i < 0)
	{
		*p++ = '-';
		i *= -1;
	}
	shift = i;
	do {
		++p;
		shift = shift / 10;
	} while (shift);
	*p = '\0';
	do {
		*--p = digits[i % 10];
		i = i / 10;
	} while (i);
	return (b);
}
