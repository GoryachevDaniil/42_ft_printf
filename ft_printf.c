/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:06:10 by mturquin          #+#    #+#             */
/*   Updated: 2020/12/13 14:15:15 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_raspil(char type, va_list arg, t_tab *t)
{
	int i;

	if (type == 'c')
		i = ft_print_c(t, va_arg(arg, int));
	else if (type == 's')
		i = ft_print_s(t, va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		i = ft_print_d_i(t, va_arg(arg, int));
	else if (type == 'x' || type == 'X')
		i = ft_print_x(t, va_arg(arg, unsigned int));
	else if (type == 'p')
		i = ft_print_p(t, va_arg(arg, long int));
	else if (type == 'u')
		i = ft_print_u(t, va_arg(arg, unsigned int));
	else if (type == '%')
		i = ft_print_procent(t);
	else
		i = 0;
	free(t);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	t_tab	*t;
	va_list	arg;

	i = -1;
	j = 0;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			t = ft_spec((char*)format, &i, arg);
			if (t->type == '\0')
				return (j);
			j += ft_raspil(t->type, arg, t);
		}
		else
		{
			ft_putchr(format[i]);
			j++;
		}
	}
	va_end(arg);
	return (j);
}
