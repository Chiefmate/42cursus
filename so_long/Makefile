# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 11:48:54 by hyunhole          #+#    #+#              #
#    Updated: 2022/06/27 20:31:30 by hyunhole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/
LIBFT_DIR 	=	./libft/
LIBMLX_DIR	=	./minilibx_opengl_20191021/

SRCS_NODIR	=	so_long.c \
				check_map.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NODIR))
OBJS = $(SRCS:.c=.o)

all: subsystem $(NAME)

subsystem:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) $^ $(LIBFT_DIR)libft.a -L $(LIBMLX_DIR) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : subsystem all clean fclean re
