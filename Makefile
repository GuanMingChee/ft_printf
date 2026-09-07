NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:*c:*.o)
all : *.o
re : 
clean :
	rm -f *.o
fclean : clean
	rm $(NAME)
