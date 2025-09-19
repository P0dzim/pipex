B_CFILE	=	check_files_bonus.c \
			close_pipes_bonus.c \
			exec_program_bonus.c \
			file_error_bonus.c \
			fork_process_bonus.c \
			heredoc_bonus.c \
			main_bonus.c \
			make_args_bonus.c \
			mini_garbage_bonus.c 

CFILE = mini_garbage.c \
		close_pipes.c \
		file_error.c \
		main.c \
		exec_program.c \
		make_args.c \
		check_files.c \
		fork_process.c

NAME =	pipex

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
	CFILES = $(B_CFILES)
endif

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	cc -Wall -Wextra -Werror $(OFILES) -o pipex -L./libft -lft

$(OFILES):
	cc -Wall -Wextra -Werror -c $(@:.o=.c) -o $(@)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean: 
	rm -f $(OFILES) $(B_OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f pipex

re: fclean all

bonus: $(NAME)

.PHONE: clean fclean re all bonus