NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
AR = ar
RM = rm -f

SRCS = main.c parsing.c parsing/parsing_nbr.c parsing/parsing_time.c parsing/scheduler.c outils/free.c outils/str.c outils/time.c \
	   coder_fonction/coder_fonction.c build/create.c build/init.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) -f $(OBJS)
	find . -name "__pycache__" -type d -exec rm -rd {} +
	find . -name "mypy_cache" -type d -exec rm -rd {} +
	find . -name ".mypy_cache" -type d -exec rm -rd {} +
	find . -name "*:Zone.Identifier" -type f -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re