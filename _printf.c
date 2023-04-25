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
	int i, len = 0;
	char *ar[] = {"c","s"};
	char *str;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == ar[0])
			_putchar(va_arg(ap, int));
		if (format[i] == '%' && format[i + 1] == ar[1])
		{
			str = va_arg(ap, char*);
			while(str[len] != '\0')
			{
				_putchar(str[len]);
			}
		}
	}
	va_end(ap);
	return (0);
}
