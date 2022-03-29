CC = gcc
NAME = libftprintf.a
NAME_LIBFT = libft.a
LIBFT_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c			\
	   ft_printf_mode.c		\
	   ft_printf_utils.c	\

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) :
	cd ${LIBFT_DIR}; make; cp ${NAME_LIBFT} ../; \
		cd ../; mv ${NAME_LIBFT} ${NAME}; make compile; ar rsv ${NAME} ${OBJS}

compile : ${SRCS}
	${CC} ${CFLAGS} -c $^

clean :
	rm -f ${OBJS}; cd libft; make clean

fclean : clean
	rm -f ${NAME}; cd libft; make fclean

.PHONY : all compile clean fclean bonus re

re : fclean all
