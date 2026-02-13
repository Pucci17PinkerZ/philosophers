# --- COLORS ---
RED      = \033[0;31m
BLUE     = \033[0;34m
GREEN    = \033[0;32m
RESET    = \033[0m

# --- VARIABLES ---
CC       = cc
NAME     = philo
CFLAGS   = -Wall -Wextra -Werror
INCLUDES = -I.

# --- DIRECTORIES ---
DIRSRC     = src
DIRPARSING = parsing
DIRINIT    = init
DIRROUTINE = routine
DIRCLEAN   = clean
OBJ_DIR    = obj

# --- SOURCES ---
SRC = $(DIRSRC)/main.c \
      $(DIRSRC)/$(DIRCLEAN)/clean_exit.c \
      $(DIRSRC)/$(DIRINIT)/setup_struct.c \
      $(DIRSRC)/$(DIRPARSING)/check_args.c \
      $(DIRSRC)/$(DIRPARSING)/check_args_value.c \
      $(DIRSRC)/$(DIRPARSING)/parsing_utils.c \
      $(DIRSRC)/$(DIRPARSING)/split.c \
      $(DIRSRC)/$(DIRROUTINE)/routine.c \
      $(DIRSRC)/$(DIRROUTINE)/utils.c \
      $(DIRSRC)/$(DIRROUTINE)/monitoring.c

# --- OBJECTS ---
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# --- RULES ---

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo -e "$(GREEN)Build successful!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -e "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "$(RED)Removing executable $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re