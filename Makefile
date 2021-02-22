# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 01:32:51 by spoliart          #+#    #+#              #
#    Updated: 2021/02/22 18:56:09 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES=	./includes/

DIR_SRCS=	./srcs/

DIR_OBJS=	./objs/

SRCS	=	ft_flags.c		\
			ft_utils.c		\
			ft_print_d.c	\
			ft_print_s.c	\
			ft_print_p.c	\
			ft_print_x.c	\
			../ft_printf.c

LIBFT 	=	./libft/

NAME	=	libftprintf.a

GCW		=	gcc -Wall -Wextra -Werror

RM		=	rm -rf

OBJS	=	$(SRCS:%.c=$(DIR_OBJS)%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
						@make -C $(LIBFT)
						@cp $(LIBFT)libft.a $(NAME)
						@ar rc $(NAME) $(OBJS)
						@ranlib $(NAME)
						@mv ft_printf.o $(DIR_OBJS)

$(DIR_OBJS)%.o:	$(DIR_SRCS)%.c
						@mkdir -p $(DIR_OBJS)
						@$(GCW) -I $(INCLUDES) -c $< -o $@

%.o:			%.c
						@$(GCW) -c $< -o $@

re:				fclean all

clean:
						@make clean -C $(LIBFT)
						@$(RM) $(DIR_OBJS) ft_printf.o

fclean:			clean
						@make fclean -C $(LIBFT)
						@$(RM) $(NAME)

.PHONY:			all re clean fclean
