#include "libft/libft.h"
#include <stdarg.h>
#include "hexhelpers.h"
#include "uhelpers.h"
#include "handlers.h"
#include <stdio.h>
#include <limits.h>

static void	handle_formats(va_list args, char const *s, int *count_addr)
{
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
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			handle_formats(args, s, &count);
		}
		else
			handle_char(*s, &count);
		s++;
	}
	va_end(args);
	return (count);
}
