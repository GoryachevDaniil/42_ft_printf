/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:16:44 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/14 19:05:51 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag(char *str, int *i)
{
	int j;

	j = 0;
	while (str[*i] && (str[*i] == '-' || str[*i] == '0'))
	{
		if (str[*i] == '-')
		{
			j = str[*i];
			while (str[*i] && (str[*i] == '-' || str[*i] == '0'))
				*i += 1;
			break ;
		}
		else if (str[*i] == '0')
			j = str[*i];
		*i += 1;
	}
	return (j);
}

int		ft_shir(char *str, int *i, va_list arg)
{
	char	*str2;
	int		start;
	int		j;

	start = *i;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		*i += 1;
	if (str[*i] == '*')
	{
		j = va_arg(arg, int);
		*i += 1;
	}
	else
	{
		if (!(str2 = ft_substr(str, start, *i - start)))
			return (-1);
		j = ft_atoi(str2);
		free(str2);
	}
	return (j);
}

int		ft_toch(char *str, int *i, va_list arg)
{
	char	*str2;
	int		start;
	int		j;

	if (str[*i] != '.')
		return (-1);
	*i += 1;
	start = *i;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		*i += 1;
	if (str[*i] == '*')
	{
		j = va_arg(arg, int);
		*i += 1;
	}
	else
	{
		if (!(str2 = ft_substr(str, start, *i - start)))
			return (-1);
		j = ft_atoi(str2);
		free(str2);
	}
	return (j);
}

char	ft_type(char *str, int *i)
{
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'd' || str[*i] == 'i' ||
		str[*i] == 'x' || str[*i] == 'X' || str[*i] == 'u' || str[*i] == 'p' ||
		str[*i] == '%')
		return (str[*i]);
	else
		return (0);
}

t_tab	*ft_spec(char *str, int *i, va_list arg)
{
	t_tab	*r;

	if (!(r = malloc(sizeof(t_tab))))
		return (NULL);
	*i += 1;
	r->flag = ft_flag(str, i);
	r->shir = ft_shir(str, i, arg);
	if (r->shir < 0 && r->flag != -1)
	{
		r->flag = '-';
		r->shir = -r->shir;
	}
	r->toch = ft_toch(str, i, arg);
	r->type = ft_type(str, i);
	return (r);
}
