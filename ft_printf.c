/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:56:44 by meltek            #+#    #+#             */
/*   Updated: 2024/04/26 06:56:51 by meltek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include "hexhelpers.h"
#include "uhelpers.h"
#include "handlers.h"
#include <stdio.h>
#include <limits.h>

static int	handle_formats(va_list args, char const *s, int *count_addr, int *f)
{
	int	valid;

	valid = 0;
	if (ft_strchr("cspdiuxX%", *s) != NULL)
		valid = 1;
	else
		*f = 0;
	if (*s == 'c')
		handle_char(va_arg(args, int), count_addr);
	if (*s == 's')
		handle_string(va_arg(args, char *), count_addr);
	if (*s == 'x' || *s == 'X' || *s == 'p')
		handle_x(va_arg(args, unsigned long long),
			count_addr, (*s == 'x' || *s == 'p'), *s == 'p');
	if (*s == 'u')
		handle_u(va_arg(args, unsigned long long), count_addr);
	if (*s == 'd' || *s == 'i')
		handle_num(va_arg(args, int), count_addr);
	if (*s == '%')
		handle_char('%', count_addr);
	return (valid);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		count;
	int		valid;
	int		final_valid;

	final_valid = 1;
	count = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			valid = handle_formats(args, s, &count, &final_valid);
			if (!valid)
				s--;
		}
		else
			handle_char(*s, &count);
		s++;
	}
	va_end(args);
	if (final_valid)
		return (count);
	return (-1);
}
