# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 11:48:54 by hyunhole          #+#    #+#              #
#    Updated: 2022/06/04 12:07:05 by hyunhole         ###   ########.fr        #
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
			util_dlst_0.c util_dlst_1.c util_dlst_2.c util_dlst_3.c util_dlst_4.c \
			util_stack_0.c util_stack_1.c util_stack_init.c util.c util_print.c \
			op_swap_and_push.c op_rotate.c op_rev_rotate.c \
			quick_sort.c \
			error.c \
			check_stack.c \
			range3_a.c \
			range3_b.c \
			push_sort.c push_sort_out.c\

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