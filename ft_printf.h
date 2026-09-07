#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *printy, ...);
int	conversion_to_c(char c);
int	conversion_to_s(char *str);
int	conversion_to_diu(long nbr);
int	conversion_to_p(void *addr);
int	conversion_to_x(uintptr_t unbr, char p);
int	check_conversions(const char *printy, va_list vlist);

#endif
