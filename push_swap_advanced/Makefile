# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 11:48:54 by hyunhole          #+#    #+#              #
#    Updated: 2022/06/27 19:27:01 by hyunhole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

SRCS_DIR	=	./src/
LIB_DIR 	=	./libft/

SRCS_NODIR	=	push_swap.c \
				utils_sort_1.c utils_sort_2.c \
				utils_sort_sml1.c utils_sort_sml2.c  utils_sort_sml3.c \
				utils_sort_sml4.c utils_sort_sml5.c \
				stack_ops_1.c stack_ops_2.c stack_ops_3.c \
				rules1.c rules2.c rules3.c \
				sort.c sort2.c sort3.c \
				parser.c \
				error.c \
				fortest.c
SRCS 		=	$(addprefix $(SRCS_DIR), $(SRCS_NODIR))
OBJS		=	$(SRCS:.c=.o)

all: subsystem $(NAME)

subsystem:
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIB_DIR)libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : subsystem all clean fclean re