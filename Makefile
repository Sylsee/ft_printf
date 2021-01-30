# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 01:32:51 by spoliart          #+#    #+#              #
#    Updated: 2020/11/10 01:36:26 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_aff.c

LIB		=	libprintf.a

GCW		=	gcc -Wall -Wextra -Werror

OBJS	=	$(GCW) 

all		:	$(NAME)

NAME	:
			
