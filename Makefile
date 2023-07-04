NAME	=	push_swap

SRC		=	push_swap.c

OBJS	=	${SRC:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	ar -rc  ${NAME} ${OBJS}
	make all -C tools/libft
	cp tools/libft/libft.a .

clean:
	${RM}	${OBJS}

fclean: clean
	${RM}	${NAME} libft.a


re: fclean all