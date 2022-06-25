# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 11:48:54 by hyunhole          #+#    #+#              #
#    Updated: 2022/06/05 17:58:13 by hyunhole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/
LIB_DIR 	=	./libft/

SRCS		=	push_swap.c \
			utils_sort_1.c utils_sort_sml1.c utils_sort_sml2.c  utils_sort_sml3.c \
			stack_ops_1.c stack_ops_2.c rules1.c rules2.c rules3.c \
			sort.c sort2.c \
			parser.c \
			error.c

SRCS_WPATH	= $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(SRCS:.c=.o)
OBJS_WPATH = $(SRCS_WPATH:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: subsystem $(NAME)

subsystem:
	make -C $(LIB_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIB_DIR)libft.a -o $(NAME)

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS_WPATH)

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

call: all clean
	make -C $(LIB_DIR) fclean

# .PHONY : all clean fclean re