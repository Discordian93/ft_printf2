/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexhelpers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 02:21:40 by meltek            #+#    #+#             */
/*   Updated: 2024/04/26 02:21:41 by meltek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

unsigned int	u_len(unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*u_to_s(unsigned long long n)
{
	char				*buffers;
	unsigned int		len;
	unsigned int		cindex;

	len = u_len(n);
	buffers = malloc(len + 1);
	if (buffers == NULL)
		return (buffers);
	if (n != 0)
	{
		cindex = len - 1;
		while (n > 0)
		{
			buffers[cindex] = (n % 10) + '0';
			n /= 10;
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
