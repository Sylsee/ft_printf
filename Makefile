# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 01:32:51 by spoliart          #+#    #+#              #
#    Updated: 2021/02/10 17:03:33 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_aff.c

LIB		=	libftprintf.a

GCW		=	gcc -Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

NAME	:	$(OBJS)
				make -C libft
				cp libft/libft.a ./$(LIB)
				@ar rc $(NAME) $(OBJS)

%.o		:	%.c
				@$(GCW) -c $< -o $@

clean	:
				rm $(OBJS)

fclean	:	clean
				rm libftprintf.a
