# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2021/01/25 17:15:01 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### VARIABLES ######

## COMPILATION ##

CC				=	gcc

CC_FLAGS		=	-Wall -Wextra -Werror

## DELETE ##

RM				=	rm -rf

## NORME ##

NORMINETTE		=	$(shell which norminette)

ifeq ($$?, 1)
	NORMINETTE := ${HOME}/.norminette/norminette.rb
endif

## DIRECTORIES ##

DIR_HEADERS		=	./includes/

DIR_SRCS		=	./srcs/

DIR_OBJS		=	./objs/

SUB_DIRS		=	. \
					char \
					str \
					print \
					mem \
					lst \
					nbr

SUB_DIR_OBJS	=	$(SUB_DIRS:%=$(DIR_OBJS)%)

## FILES ##

SRCS			=	char/ft_isalnum.c \
					char/ft_isalpha.c \
					char/ft_isascii.c \
					char/ft_isdigit.c \
					char/ft_isprint.c \
					char/ft_tolower.c \
					char/ft_toupper.c \
					print/ft_putchar_fd.c \
					print/ft_putendl_fd.c \
					print/ft_putnbr_fd.c \
					print/ft_putstr_fd.c \
					str/ft_split.c \
					str/ft_strchr.c \
					str/ft_strdup.c \
					str/ft_strjoin.c \
					str/ft_strlcat.c \
					str/ft_strlcpy.c \
					str/ft_strlen.c \
					str/ft_strmapi.c \
					str/ft_strncmp.c \
					str/ft_strnstr.c \
					str/ft_strrchr.c \
					str/ft_strtrim.c \
					str/ft_substr.c \
					nbr/ft_atoi.c \
					nbr/ft_itoa.c \
					mem/ft_bzero.c \
					mem/ft_calloc.c \
					mem/ft_memchr.c \
					mem/ft_memcmp.c \
					mem/ft_memcpy.c \
					mem/ft_memccpy.c \
					mem/ft_memmove.c \
					mem/ft_memset.c \
					lst/ft_lstadd_back.c \
					lst/ft_lstadd_front.c \
					lst/ft_lstclear.c \
					lst/ft_lstdelone.c \
					lst/ft_lstiter.c \
					lst/ft_lstlast.c \
					lst/ft_lstmap.c \
					lst/ft_lstnew.c \
					lst/ft_lstsize.c

## COMPILED ##

OBJS		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME		=	libft.a

# **************************************************************************** #

###### RULES ######

all:			$(NAME)

## VARIABLES RULES ##

$(NAME):		$(OBJS)
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)

$(DIR_OBJS)%.o:	$(DIR_SRCS)%.c
					@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS):	$(SUB_DIR_OBJS)

$(SUB_DIR_OBJS):
					@mkdir -p $(SUB_DIR_OBJS)

## OBLIGATORY PART ##

clean:
					@$(RM) $(DIR_OBJS)

fclean:			clean
					@$(RM) $(NAME) libft.so

re:				fclean all

## NORME ##

norme:
					@$(NORMINETTE) $(DIR_SRCS)
					@$(NORMINETTE) $(DIR_HEADERS)

## PHONY ##

.PHONY:			all clean re fclean norme so

so:				fclean $(OBJS)
					gcc $(OBJS) -shared -o libft.so
