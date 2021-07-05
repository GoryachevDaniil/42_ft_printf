/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_shir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:19:36 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/14 18:40:43 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_shir(int shir, int len, char c)
{
	while (shir-- > len)
		ft_putchr(c);
}

int		ft_print_shir2(int shir, int len, char c)
{
	int i;

	i = 0;
	while (shir-- > len)
		i += ft_putchr2(c);
	return (i);
}
