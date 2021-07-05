/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:48:48 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/14 20:09:44 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toch_nbs(char *nbs, int *i, int toch)
{
	char	*str;

	if (nbs[0] == '-')
	{
		str = malloc(sizeof(char) * (toch + 2));
		*i += 2;
		ft_memset(str, '0', *i);
		str[*i] = '\0';
		str = ft_strjoin(str, &nbs[1]);
		str[0] = '-';
	}
	else
	{
		str = malloc(sizeof(char) * toch + 1);
		ft_memset(str, '0', *i);
		str[*i] = '\0';
		str = ft_strjoin(str, nbs);
	}
	return (str);
}

void	ft_put_numbers(t_tab *t, char *number)
{
	if ((t->flag == '0' && t->toch >= 0) || t->flag == 0)
	{
		ft_print_shir(t->shir, ft_strlen(number), ' ');
		ft_putstr(number);
	}
	else
	{
		if (number[0] == '-')
		{
			ft_putchr('-');
			ft_print_shir(t->shir, ft_strlen(number), '0');
			ft_putstr(&number[1]);
		}
		else
		{
			ft_print_shir(t->shir, ft_strlen(number), '0');
			ft_putstr(number);
		}
	}
}

char	*ft_toch_d_i(int toch, int nb)
{
	char	*str;
	char	*nbs;
	int		len;
	int		i;

	i = 0;
	str = NULL;
	nbs = ft_itoa(nb);
	len = ft_strlen(nbs);
	if (toch >= len)
	{
		i = toch - len;
		str = ft_toch_nbs(nbs, &i, toch);
		free(nbs);
		return (str);
	}
	return (nbs);
}

int		ft_print_d_i(t_tab *t, int i)
{
	char	*number;
	int		len;

	number = ft_toch_d_i(t->toch, i);
	len = ft_strlen(number);
	if (i == 0 && t->toch == 0)
	{
		ft_print_shir(t->shir, len - 1, ' ');
	}
	else if (t->flag == 0 || t->flag == '0')
		ft_put_numbers(t, number);
	else if (t->flag == '-')
	{
		ft_putstr(number);
		ft_print_shir(t->shir, len, ' ');
	}
	free(number);
	if (i == 0 && t->toch == 0)
		len -= 1;
	return (t->shir > len) ? t->shir : len;
}
