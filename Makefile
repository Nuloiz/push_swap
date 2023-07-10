NAME	=	push_swap

SRC		=	tester.c push_swap.c linked_list.c op_switch_elements_in_stack.c op_rotate_stack.c op_swap_stacks.c radix_sort.c

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