#include "ft_printf.h"
#include <stdarg.h>

int	check_conversions(const char *printy, va_list vlist)
{
	if (*printy == 'c')
		return (conversion_to_c((char)va_arg(vlist, int)));
	else if (*printy == 's')
		return (conversion_to_s(va_arg(vlist, char *)));
	else if (*printy == 'p')
		return (conversion_to_p(va_arg(vlist, void *)));
	else if (*printy == 'd' || *printy == 'i')
		return (conversion_to_diu((long)va_arg(vlist, int)));
	else if (*printy == 'u')
		return (conversion_to_diu((long)va_arg(vlist, unsigned int)));
	else if (*printy == 'x' || *printy == 'X')
		return (conversion_to_x(va_arg(vlist, uintptr_t), *printy));
	else if (*printy == '%')
		return (conversion_to_c('%'));
	return (0);
}

int	ft_printf(const char *printy, ...)
{
	va_list	vlist;
	int		count;
	int		res;

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
			res = conversion_to_c(*printy);
		if (res == -1)
			return (va_end(vlist), -1);
		count += res;
		printy++;
	}
	return (va_end(vlist), count);
}
