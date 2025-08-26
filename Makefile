CFILES	=	fork_process.c \
			pipex.c \

DIR_SRC	=	./src/
SRC		=	${addprefix DIR_SRC, CFILES}
NAME	=	pipex
LIBFT	=	./libft/libft.a

all: $(NAME)

$(NAME):
	cc libft/*.c src/*.c -o pipex

clean: 
	rm -f *.o

fclean: clean
	rm -f pipex

re: fclean all

.PHONE: clean fclean re all