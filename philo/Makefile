CC = cc
NAME = philo
DIRSRC = src
DIRPARSING = parsing
DIRINIT = init
DIRROUTINE = routine
DIRCLEAN = clean
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I.

RM = rm -rf
SRC = $(DIRSRC)/philo.c \
$(DIRSRC)/clean/clean_exit.c \
$(DIRSRC)/$(DIRINIT)/setup_struct.c\
$(DIRSRC)/$(DIRPARSING)/check_args.c\
$(DIRSRC)/$(DIRPARSING)/check_args_value.c\
$(DIRSRC)/$(DIRPARSING)/parsing_utils.c\
$(DIRSRC)/$(DIRPARSING)/split.c\
$(DIRSRC)/$(DIRROUTINE)/routine.c\
$(DIRSRC)/$(DIRROUTINE)/utils.c\

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