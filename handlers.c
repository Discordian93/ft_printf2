#include <stdlib.h>
#include "libft/libft.h"
#include "hexhelpers.h"
#include "uhelpers.h"
#include <limits.h>

void	handle_x(unsigned long long n, int *count, int lowercase, int is_p)
{
	char	*hex_repr;

	hex_repr = num_to_hex(n);
	if (hex_repr == NULL)
		return ;
	if (is_p)
	{
		*count += 2;
		ft_putstr_fd("0x", 1);
	}
	else
	{
		n = (unsigned int) n;
		free(hex_repr);
		hex_repr = num_to_hex(n);
	}
	if (lowercase)
		hex_to_min(hex_repr);
	ft_putstr_fd(hex_repr, 1);
	*count += ft_strlen(hex_repr);
	free(hex_repr);
}


void	handle_char(char c, int *count)
{
	(*count)++;
	ft_putchar_fd(c, 1);
}

void	handle_string(char *s, int *count)
{
	if (s == NULL)
		s = "(null)" ;
	(*count) += ft_strlen(s);
	ft_putstr_fd(s, 1);
}

void	handle_u(unsigned long long u, int *count)
{
	char	*u_repr;

	u = (unsigned int) u;
	u_repr = u_to_s(u);
	if (u_repr == NULL)
		return ;
	ft_putstr_fd(u_repr, 1);
	(*count) += ft_strlen(u_repr);
	free(u_repr);
}

void	handle_num(int n, int *count)
{
	char	*n_repr;

	n_repr = ft_itoa(n);
	if (n_repr == NULL)
		return ;
	(*count) += ft_strlen(n_repr);
	ft_putstr_fd(n_repr, 1);
	free(n_repr);
}
