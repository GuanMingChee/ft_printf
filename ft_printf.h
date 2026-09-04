#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *printy, ...);
int	conversion_to_c(char c);
int	conversion_to_s(va_list vlist);
int	conversion_to_diu(long nbr);
int	check_conversions(const char *printy, va_list vlist);


#endif
