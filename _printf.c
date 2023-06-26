#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: Is a character string
 *
 * Return: The number of charcters printed
 * excluding the null byte.
 */
int _printf(const char *format, ...)
{

int i, num = 0;
char *string, ch;

va_list arg;

va_start(arg, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
{
ch = ((char)va_arg(arg, int));
_putchar(ch);
num++;
break;
}
case 's':
{
string = va_arg(arg, char *);
while (*string)
{
_putchar(*string);
num++;
string++;
}
break;
}
case '%':
{
_putchar(format[i]);
num++;
break;

case 'd':
case 'i':
num += handle_int(va_arg(arg, int));
break;

default:
break;
}
}
}
else
{
_putchar(format[i]);
num++;
}
}

va_end(arg);
return (num);
}
