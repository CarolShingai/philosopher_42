NAME = philo
FLAGS = -Wall -Werror -Wextra -pthread -g3
HEADERS = -I ./include

SRCS = ${addprefix srcs/, \
				action.c \
				death.c \
				philo_life.c \
				main.c \
				mutex.c \
				take_fork.c \
				table.c \
				thread.c \
				time.c \
				utils.c \
				validation.c }

OBJ = $(SRCS:srcs/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
			@cc $(FLAGS) $(HEADERS) $(OBJ) -o $@
			@echo "compiling $(NAME)"

obj/%.o: srcs/%.c
			@mkdir -p obj
			@cc $(FLAGS) $(HEADERS) -c $< -o $@
			@echo "compiling $(notdir $<)"

clean:
			@echo "removing object files"
			@rm -rf $(OBJ)

fclean: clean
			@echo "removing executables"
			@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
