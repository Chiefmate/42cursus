NAME=libft.a
CC=gcc
CFLAG=-Wall -Wextra -Werror
RM=rm -f
AR=ar
ARFLAGS=crs
INCLUDES=./libft.h
SRCS=ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c \
    ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
    ft_memcmp.c ft_memchr.c ft_strnstr.c ft_strncmp.c \
    ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_atoi.c \
    ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
    ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
                ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
                ft_lstmap.c
OBJS=ft_isalpha.o ft_isalnum.o ft_isdigit.o ft_isascii.o ft_isprint.o \
    ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o \
    ft_memcmp.o ft_memchr.o ft_strnstr.o ft_strncmp.o \
    ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_atoi.o \
    ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o \
    ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
    ft_putendl_fd.o ft_putnbr_fd.o
OBJS_BONUS=ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
                ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o \
                ft_lstmap.o

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
