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
	char *str;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == "c")
		{
			_putchar(va_arg(ap, int));
			c++;
		}
		else if (format[i] == '%' && format[i + 1] == "s")
		{
			str = va_arg(ap, char*);
			if (str == NULL)
				str = "(null)";
			while (str[len] != '\0')
			{
				_putchar(str[len]);
				c++;
			}
		}
		else
		{
			_putchar(forma[i]);
			c++;
		}
	}
	va_end(ap);
	return (c);
}
