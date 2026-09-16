/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchee <gchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:43:10 by gchee             #+#    #+#             */
/*   Updated: 2026/09/16 17:43:19 by gchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *printy, ...);
int	conversion_to_c(char c);
int	conversion_to_s(char *str);
int	conversion_to_diu(long nbr);
int	conversion_to_p(void *addr);
int	conversion_to_x(uintptr_t unbr, char p);
int	check_conversions(const char *printy, va_list vlist);

#endif
