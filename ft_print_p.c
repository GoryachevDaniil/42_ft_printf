/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:46:16 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/14 20:18:01 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toch_nb(char *nb, int *i, int toch)
{
	char	*str;

	str = malloc(sizeof(char) * (toch + 1));
	ft_memset(str, '0', *i);
	str[*i] = '\0';
	str = ft_strjoin(str, nb);
	return (str);
}

char	*ft_toch_p(int toch, long int c)
{
	char	*str;
	char	*nb;
	int		len;
	int		i;

	i = 0;
	str = NULL;
	nb = ft_itoa_base(c, 16, 'a');
	len = ft_strlen(nb);
	if (toch > len)
	{
		i = toch - len;
		str = ft_toch_nb(nb, &i, toch);
		free(nb);
		return (str);
	}
	return (nb);
}

int		ft_put_nb(t_tab *t, char *nbs, int len)
{
	int		count;

	count = 0;
	if (t->toch == -1)
	{
		count += ft_print_shir2(t->shir, len + 2, ' ');
		count += write(1, "0x", 2);
		count += ft_putstr2(nbs);
	}
	else if (t->toch != -1)
	{
		count += ft_print_shir2(t->shir, len + 2, ' ');
		count += write(1, "0x", 2);
		if (t->toch == 0 || t->toch == -1)
			return (count);
		count += ft_putstr2(nbs);
	}
	return (count);
}

int		ft_print_p(t_tab *t, long int c)
{
	int		count;
	int		len;
	char	*nbs;

	count = 0;
	nbs = ft_toch_p(t->toch, c);
	len = ft_strlen(nbs);
	if (c == 0 && t->toch != -1)
		len -= 1;
	if (t->flag == 0)
		count = ft_put_nb(t, nbs, len);
	if (t->flag == '-')
	{
		count += write(1, "0x", 2);
		if (t->toch != 0)
			count += ft_putstr2(nbs);
		count += ft_print_shir2(t->shir, len + 2, ' ');
	}
	free(nbs);
	return (count);
}
