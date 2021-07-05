/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:15:02 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/13 14:01:49 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_tab *t, char c)
{
	if (t->flag == -1)
		return (-1);
	if (t->flag == '-')
	{
		ft_putchr(c);
		ft_print_shir(t->shir, 1, ' ');
	}
	else if (t->flag == '0')
	{
		ft_print_shir(t->shir, 1, '0');
		ft_putchr(c);
	}
	else
	{
		ft_print_shir(t->shir, 1, ' ');
		ft_putchr(c);
	}
	if (t->shir == 0)
		return (1);
	return (t->shir);
}
