NAME = Codexion
CC = cc
CFLAGS = -Wall -Wextra - Werror 
AR = ar
RM = rm -f

SRCS = main.c \ 

OBJS = $(SRCS:.c=.o)

all:


clean:
	find . -name "__pycache__" -type d -exec rm -rd {} +
	find . -name "mypy_cache" -type d -exec rm -rd {} +
	find . -name ".mypy_cache" -type d -exec rm -rd {} +
	find . -name "*:Zone.Identifier" -type f -delete

fclean: clean

re: