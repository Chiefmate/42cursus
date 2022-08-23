# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 11:47:40 by hyunhole          #+#    #+#              #
#    Updated: 2022/08/20 15:45:58 by hyunhole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/

SRCS_NODIR	=	main.c \
				init.c \
				simul.c \
				thread.c \
				thread_utils.c \
				utils.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NODIR))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
