#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	conversion_to_c()
{
	//convert and print here using write
	//return 0 if no error
	return (0);
}

int	check_conversions(const char *printy, va_list vlist)
{
	if (*printy == 'c')
		return (ft_putchar((char)va_arg(vlist, int)));
	else if (*printy == 's')
	else if (*printy == 'p')
	else if (*printy == 'd')
	else if (*printy == 'i')
	else if (*printy == 'u')
	else if (*printy == 'x')
	else if (*printy == 'X')
	else if (*printy == '%')
	return (0);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *printy, ...)
{
	va_list	vlist;
	int	count;
	int	res;

	if (!printy)
		return (-1);
	count = 0;
	res = 0;
	va_start(vlist, printy);
	while (*printy)
	{
		if (*printy == '%' && *(++printy))
			res = check_conversions(printy, vlist);
		else
			res = ft_putchar(*printy);
		if (res == -1)
			return (va_end(vlist), -1);
		count += res;
		printy++;
	}
	return (va_end(vlist), count);
}
