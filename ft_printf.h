/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:44:19 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/12 04:32:12 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tab
{
	int			flag;
	int			shir;
	int			toch;
	char		type;
}				t_tab;

int				ft_printf(const char *str, ...);
int				ft_raspil(char type, va_list arg, t_tab *t);
t_tab			*ft_spec(char *str, int *i, va_list arg);
int				ft_flag(char *str, int *i);
int				ft_shir(char *str, int *i, va_list arg);
int				ft_toch(char *str, int *i, va_list arg);
char			ft_type(char *str, int *i);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *str);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
int				ft_print_c(t_tab *t, char c);
void			ft_print_shir(int shir, int len, char c);
void			ft_putchr(char c);
void			ft_putstr(char *c);
int				ft_print_s(t_tab *t, char *s);
char			*ft_toch_of_str(int prec, char *s);
size_t			ft_strlen(const char *str);
int				ft_print_d_i(t_tab *t, int i);
char			*ft_toch_d_i(int toch, int nb);
void			ft_put_numbers(t_tab *t, char *number);
char			*ft_toch_nbs(char *nb, int *i, int toch);
int				ft_print_x(t_tab *t, unsigned int i);
char			*ft_toch_x(int toch, unsigned int nb, char type);
void			ft_put_numbers_x(t_tab *t, char *number);
char			*ft_toch_nbs_x(char *nbs, int *i, int toch);
void			*ft_memset(void *dest, int c, size_t n);
char			*ft_itoa_base(unsigned long long int i,
							unsigned long long int j, char c);
char			*ft_not(int r, int rev);
int				ft_print_p(t_tab *t, long int c);
char			*ft_toch_p(int toch, long int c);
char			*ft_toch_nb(char *nb, int *i, int toch);
int				ft_put_nb(t_tab *t, char *nbs, int len);
void			*ft_calloc(unsigned num, size_t size);
int				ft_print_u(t_tab *t, unsigned int i);
char			*ft_toch_u(int toch, unsigned int nb);
char			*ft_itoa_u(unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_print_procent(t_tab *t);
int				ft_putstr2(char *str);
int				ft_print_shir2(int shir, int len, char c);
int				ft_putchr2(char c);

#endif
