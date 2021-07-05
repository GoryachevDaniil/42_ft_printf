/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:29:11 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/13 13:58:52 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*str1;

	i = 0;
	while (str[i])
		i++;
	str1 = (char *)malloc(sizeof(char) * i + 1);
	if (str1 == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
