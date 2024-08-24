#	Program name
NAME = Colleen

#	Colors
DEFAULT    = \033[0m
BLACK    = \033[0;30m
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
BLUE    = \033[0;34m
PURPLE    = \033[0;35m
CYAN    = \033[0;36m
BWHITE    = \033[1;37m

# Utils
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Rules
all: $(NAME)

$(NAME):
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $@.c -o $@

clean:
	@echo "$(RED)! Removing$(DEFAULT) example files"
	@$(RM) tmp_*

fclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(NAME)"
	@$(RM) $(NAME)

re: fclean all

cre:
	@clear
	@make re --no-print-directory

example: cre
	@./$(NAME) > tmp_$(NAME);
	@diff -s tmp_$(NAME) $(NAME).c

