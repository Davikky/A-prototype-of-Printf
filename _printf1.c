#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - .
 * @format: .
 * Return: .
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int output_count = 0;
	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					putchar(va_arg(args, int));
					output_count++;
					break;
				case 's':
				{
					char *str = va_arg(args, char *);
					for (int j = 0; str[j] != '\0'; j++)
					{
						putchar(str[j]);
						output_count++;
					}
					break;
				}
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					if (num < 0)
					{
						putchar('-');
						output_count++;
						num = -num;
					}
					int digit_count = 0;
					for (int n = num; n > 0; n /= 10)
					{
						digit_count++;
					}
					if (digit_count == 0)
					{
						putchar('0');
						output_count++;
					}
					else
					{
						char digits[digit_count];
						for (int j = digit_count - 1; j >= 0; j--)
						{
							digits[j] = num % 10 + '0';
							num /= 10;
						}
						for (int j = 0; j < digit_count; j++)
						{
							putchar(digits[j]);
							output_count++;
						}
					}
					break;
				}
				case '%':
					putchar('%');
					output_count++;
					break;
				default:
					break;
			}
		}
		else
		{
			putchar(format[i]);
			output_count++;
		}
	}

	va_end(args);
	return (output_count);
}

