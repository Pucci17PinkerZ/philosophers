CC = cc
NAME = philo
DIRSRC = src
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -I$(DIRSRC)
RM = rm -rf
SRC = $(DIRSRC)/philo.c \
$(DIRSRC)/clean_exit.c \
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