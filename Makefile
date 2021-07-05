# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mturquin <mturquin@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 12:02:29 by mturquin          #+#    #+#              #
#    Updated: 2020/12/13 14:05:01 by mturquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c\
			ft_print_c.c\
			ft_print_u.c\
			ft_spec.c\
			ft_atoi.c\
			ft_print_d_i.c\
			ft_print_x.c\
			ft_strdup.c\
			ft_calloc.c\
			ft_print_p.c\
			ft_printf.c\
			ft_strjoin.c\
			ft_itoa.c\
			ft_print_procent.c\
			ft_strlen.c\
			ft_itoa_base.c\
			ft_print_s.c\
			ft_putchr.c\
			ft_substr.c\
			ft_memset.c\
			ft_print_shir.c\
			ft_putstr.c\

OBJS	=	${SRCS:.c=.o}

NAME	= 	libftprintf.a 

СС		=	gcc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all:		${NAME}

.c.o:		
			${CC} ${CFLAGS} -c $< -o $(<:.c=.o) 

$(NAME):	${OBJS} 
			ar rc ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

