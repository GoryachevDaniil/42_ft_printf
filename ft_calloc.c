/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:02:23 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/09 13:10:45 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(unsigned num, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (void *)malloc(num * size);
	if (str == NULL)
		return (NULL);
	while (i < num * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
