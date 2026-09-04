#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	conversion_to_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	conversion_to_s(va_list vlist)
{
	char	*str;
	int	count;
	int	res;

	str = va_arg (vlist, char *);
	if (!str)
		str = "(null)";
	count = 0;
	res = 0;
	while (*str)
	{
		res = ft_putchar(*str);
		if (res == -1)
			return (-1);
		count += res;
		str++;
	}
	return (count);
}

/* skip for now
int	conversion_to_p(va_list vlist)
{

	void *ptr;
	uintptr_t adr;
	int count;
	int res;

	ptr = va_arg(vlist, void *);
	if (!ptr)
		ptr = "(null)";
	count = 0;
	res = 0;
	while (*ptr)
	{
		res = ft_putchar(*str);
		if (res == -1)
			return (-1);
		count += res;
		str++;
	}
	return (count);
}*/

int	conversion_to_xX(unsigned int unbr, char p)
{
	char	*hex_list;
	int	hex;
	int	h;

	hex_list = "0123456789abcdef";
	while (nbr >= 0)
	{
		h = 0;
		hex = unbr % 16;
		if (p == 'X')
			h = 'x' - 'X';
		if (write(1, hex_list[hex] - h, 1) == -1)
			return (-1);
		unbr /= 16;
		res++;
	}
}

int	conversion_to_diu(long nbr)
{
	char	c;
	int	res;
	int	tmp_check;

	res = 0;
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nbr *= -1;
		res++;
	}
	if (nbr > 9)
	{
		tmp_check = conversion_to_di(nbr / 10);
		if (tmp_check == -1)
			return (-1);
		res += tmp_check;
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (res + 1);
}

int	check_conversions(const char *printy, va_list vlist)
{
	if (*printy == 'c')
		return (conversion_to_c((char)va_arg(vlist, int)));
	else if (*printy == 's')
		return (conversion_to_s(va_arg(vlist, char *)));
	else if (*printy == 'p')
	else if (*printy == 'd' || *printy == 'i')
		return (conversion_to_diu((long)va_arg(vlist, int)));
	else if (*printy == 'u')
		return (conversion_to_diu((long)va_arg(vlist, unsigned int));
	else if (*printy == 'x' || *printy == 'X')
		return (conversion_to_xX(va_arg(vlist, unsigned int), *printy));
	//else if (*printy == 'X')
	else if (*printy == '%')
		return (conversion_to_c('%'));
	return (0);
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
			res = conversion_to_c(*printy);
		if (res == -1)
			return (va_end(vlist), -1);
		count += res;
		printy++;
	}
	return (va_end(vlist), count);
}
