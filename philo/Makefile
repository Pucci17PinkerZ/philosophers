CC = cc
NAME = philo
DIRSRC = src
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I.

RM = rm -rf
SRC = $(DIRSRC)/philo.c \
$(DIRSRC)/clean_exit.c \
$(DIRSRC)/utils.c\
$(DIRSRC)/parsing/check_args.c\
$(DIRSRC)/parsing/check_args_value.c\
$(DIRSRC)/parsing/clean_parsing.c\
$(DIRSRC)/parsing/parsing_utils.c\
$(DIRSRC)/parsing/split.c\

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re