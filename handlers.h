/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 02:12:26 by meltek            #+#    #+#             */
/*   Updated: 2024/04/26 02:12:28 by meltek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

void		handle_x(unsigned long long n, int *count, int lowercase, int is_p);
void		handle_char(char c, int *count);
void		handle_string(char *s, int *count);
void		handle_u(unsigned long long u, int *count);
void		handle_num(int n, int *count);

#endif