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

#ifndef HEXHELPERS_H
# define HEXHELPERS_H

unsigned int	hex_len(unsigned long long n);
char			n_to_hex(unsigned long long n);
char			*num_to_hex(unsigned long long n);
void			hex_to_min(char *hx);

#endif
