/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_procent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:11:47 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/09 13:06:01 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_procent(t_tab *t)
{
	if (t->flag == -1 || t->flag == '-')
	{
		ft_putchr('%');
		ft_print_shir(t->shir, 1, ' ');
	}
	else if (t->flag == '0')
	{
		ft_print_shir(t->shir, 1, '0');
		ft_putchr('%');
	}
	else
	{
		ft_print_shir(t->shir, 1, ' ');
		ft_putchr('%');
	}
	return (t->shir > 1) ? t->shir : 1;
}
