/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:56:55 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/12 04:34:04 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toch_of_str(int toch, char *s)
{
	char	*str;

	if (!s)
		s = "(null)";
	if (ft_strlen(s) > (size_t)toch)
		str = ft_substr(s, 0, toch);
	else
		str = ft_substr(s, 0, ft_strlen(s));
	return (str);
}

int		ft_print_s(t_tab *t, char *s)
{
	int		len;
	char	*str;

	if (t->flag == -1)
		return (-1);
	str = ft_toch_of_str(t->toch, s);
	len = ft_strlen(str);
	if (t->flag == 0)
	{
		ft_print_shir(t->shir, len, ' ');
		ft_putstr(str);
	}
	if (t->flag == '0')
	{
		ft_print_shir(t->shir, len, '0');
		ft_putstr(str);
	}
	else if (t->flag == '-')
	{
		ft_putstr(str);
		ft_print_shir(t->shir, len, ' ');
	}
	free(str);
	return (t->shir > len) ? t->shir : len;
}
