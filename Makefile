NAME	=	push_swap

SRC		=	push_swap.c linked_list.c

OBJS	=	${SRC:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra -g

all: ${NAME}

${NAME}: ${OBJS}
	make all -C tools/libft
	cp tools/libft/libft.a .
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} libft.a

clean:
	${RM}	${OBJS}

fclean: clean
	${RM}	${NAME} libft.a


re: fclean all