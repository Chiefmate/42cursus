# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 11:48:54 by hyunhole          #+#    #+#              #
#    Updated: 2022/06/04 15:01:44 by hyunhole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/

LIB_DIR		=	./libft/
LIB_NAME	=	libft.a

SRC		=	push_swap.c \
			utils_sort_1.c \
			rules1.c rules2.c rules3.c rules4.c \
			sort.c sort_smlutil.c sort_smltuil2.c \
			error.c \
			check_stack.c \
			fortest.c

SRCS	= $(addprefix $(SRCS_DIR), $(OBJS))
LIBS	= $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS	= $(SRC:.c=.o)

all : $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(NAME) : $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(SRCS)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re