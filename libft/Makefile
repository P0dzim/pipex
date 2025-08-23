CFILES		= ft_strncmp.c ft_memcmp.c ft_putendl_fd.c ft_isalnum.c ft_isascii.c ft_strnstr.c ft_striteri.c ft_strjoin.c ft_strdup.c ft_itoa.c ft_memcpy.c ft_strtrim.c ft_calloc.c ft_isprint.c ft_strlen.c ft_isalpha.c ft_strlcat.c ft_memset.c ft_bzero.c ft_split.c ft_putnbr_fd.c ft_substr.c ft_strlcpy.c ft_memchr.c ft_isdigit.c ft_putstr_fd.c ft_strchr.c ft_memmove.c ft_toupper.c ft_strrchr.c ft_putchar_fd.c ft_atoi.c ft_strmapi.c ft_tolower.c ft_reverse_split.c
OFILES		= ${CFILES:.c=.o}
FLAGS		= -Wall -Wextra -Werror
HFILES		= libft.h
NAME		= libft.a
B_CFILES	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
B_OFILES	= ${B_CFILES:.c=.o}

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
	CFILES += $(B_CFILES)
endif

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

$(OFILES): 
	cc $(FLAGS) -c ${@:.o=.c} -o ${@}

clean:
	rm -f $(OFILES) $(B_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)
