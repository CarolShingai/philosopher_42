NAME = philo
FLAGS = -Wall -Werror -Wextra

SCRS = ${addprefix srcs/, \}

OBJ = $(SCRS:srcs/%.cc=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
			mkdir -p obj
			@cc $(FLAGS)
			@echo "compiling"

clean:
			@echo "removing"
			@rm -rf $(OBJ)

fclean: clean
			@echo "removing executables"
			@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
