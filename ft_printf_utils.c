#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"

int	conversion_to_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	conversion_to_s(char *str)
{
	int	count;
	int	res;

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

int	conversion_to_p(void *addr)
{
	int	res;

	if (!addr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write (1, "0x", 2) == -1)
		return (-1);
	res = conversion_to_x((uintptr_t)addr, 'x');
	if (res == -1)
		return (-1);
	return (res + 2);
}

int	conversion_to_x(uintptr_t unbr, char p)
{
	char	*hex_list;
	int		i;
	int		res;

	res = 0;
	hex_list = "0123456789abcdef";
	if (p == 'X')
		hex_list = "0123456789ABCDEF";
	if (unbr >= 16)
	{
		res = conversion_to_x(unbr / 16, p);
		if (res == -1)
			return (-1);
	}
	i = unbr % 16;
	if (write(1, &hex list[i], 1) == -1)
		return (-1);
	return (res + 1);
}

int	conversion_to_diu(long nbr)
{
	char	c;
	int		res;
	int		tmp_check;

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
		tmp_check = conversion_to_diu(nbr / 10);
		if (tmp_check == -1)
			return (-1);
		res += tmp_check;
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (res + 1);
}
