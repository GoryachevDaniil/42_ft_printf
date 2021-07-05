/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:09:37 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/14 19:55:14 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		ft_putstr2(char *s)
{
	int i;

	i = 0;
	i += write(1, s, ft_strlen(s));
	return (i);
}
