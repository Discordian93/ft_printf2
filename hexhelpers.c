/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexhelpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:57:05 by meltek            #+#    #+#             */
/*   Updated: 2024/04/26 06:57:06 by meltek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

unsigned int	hex_len(unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	n_to_hex(unsigned long long n)
{
	if (n <= 9)
	{
		return (n + '0');
	}
	return (n + 'A' - 10);
}

char	*num_to_hex(unsigned long long n)
{
	char				*buffers;
	unsigned int		len;
	unsigned int		cindex;

	len = hex_len(n);
	buffers = malloc(len + 1);
	if (buffers == NULL)
		return (buffers);
	if (n != 0)
	{
		cindex = len - 1;
		while (n > 0)
		{
			buffers[cindex] = n_to_hex(n % 16);
			n /= 16;
			cindex--;
		}
		buffers[len] = '\0';
	}
	else
	{
		buffers[0] = '0';
		buffers[1] = '\0';
	}
	return (buffers);
}

void	hex_to_min(char *hx)
{
	while (*hx != '\0')
	{
		if (*hx >= 'A' && *hx <= 'F')
		{
			*hx = *hx - 'A' + 'a';
		}
		hx++;
	}
}
