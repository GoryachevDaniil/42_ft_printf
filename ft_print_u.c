/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:45:41 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/14 20:09:13 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_count(unsigned int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa_u(unsigned int n)
{
	char		*str;
	int			i;

	i = (n < 0) ? size_count(n) + 1 : size_count(n);
	if (!(str = ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		while (i > 0)
		{
			str[i] = '0' - (n % 10);
			i--;
			n /= 10;
		}
		str[i] = '-';
	}
	else
		while (i >= 0)
		{
			str[i] = n % 10 + '0';
			i--;
			n /= 10;
		}
	return (str);
}

char		*ft_toch_u(int toch, unsigned int nb)
{
	char	*str;
	char	*nbs;
	int		len;
	int		i;

	i = 0;
	nbs = ft_itoa_u(nb);
	len = ft_strlen(nbs);
	if (toch > len)
	{
		i = toch - len;
		str = malloc(sizeof(char) * toch);
		ft_memset(str, '0', i);
		str[i] = '\0';
		str = ft_strjoin(str, nbs);
		free(nbs);
		return (str);
	}
	return (nbs);
}

int			ft_print_u(t_tab *t, unsigned int i)
{
	char	*nbs;
	int		len;

	nbs = ft_toch_u(t->toch, i);
	len = ft_strlen(nbs);
	if (i == 0 && t->toch == 0)
		ft_print_shir(t->shir, len - 1, ' ');
	else if (t->flag == 0 || t->flag == '0')
	{
		if ((t->flag == '0' && t->toch >= 0) || t->flag == 0)
			ft_print_shir(t->shir, len, ' ');
		else
			ft_print_shir(t->shir, len, '0');
		ft_putstr(nbs);
	}
	else if (t->flag == '-')
	{
		ft_putstr(nbs);
		ft_print_shir(t->shir, len, ' ');
	}
	free(nbs);
	if (i == 0 && t->toch == 0)
		len -= 1;
	return (t->shir > len) ? t->shir : len;
}
