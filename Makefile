NAME = philo
FLAGS = -Wall -Werror -Wextra -pthread
HEADERS = -I ./include

SRCS = ${addprefix srcs/, \
				main.c \
				philosophers.c \
				take_fork.c \
				validation.c }

OBJ = $(SRCS:srcs/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
			@cc $(FLAGS) $(HEADERS) $(OBJ) -o $@
			@echo "compiling $(NAME)"

obj/%.o: srcs/%.c
			mkdir -p obj
			@cc $(FLAGS) $(HEADERS) -c $< -o $@
			@echo "compiling"

clean:
			@echo "removing object files"
			@rm -rf $(OBJ)

fclean: clean
			@echo "removing executables"
			@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
