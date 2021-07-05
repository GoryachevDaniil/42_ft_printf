/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:12:33 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/13 20:53:03 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (++i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = count(n);
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);
	str[l] = '\0';
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i = 1;
	}
	while (l-- > i ? 1 : 0)
	{
		str[l] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
