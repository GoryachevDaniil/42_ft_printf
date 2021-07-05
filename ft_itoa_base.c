/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.21-shoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:03:48 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/10 19:08:23 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long int i, unsigned long long j, char c)
{
	unsigned long long int	tmp;
	char					*str;
	int						len;

	len = 1;
	tmp = i;
	while ((tmp /= j) >= 1)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		if (i % j < 10)
			str[len] = i % j + '0';
		else
			str[len] = i % j + c - 10;
		i /= j;
	}
	return (str);
}
