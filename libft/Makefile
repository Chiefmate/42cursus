NAME=libft.a
CC=gcc
CFLAG=-Wall -Wextra -Werror
RM=rm -f
AR=ar
ARFLAGS=crs
INCLUDES=./libft.h
SRCS=libft1.c libft2.c libft3.c libft4.c libft5.c add1.c add2.c add3.c
SRCS_BONUS=bonus1.c bonus2.c
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY : all clean fclean re