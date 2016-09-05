SRC_NAME =	main.c \
			hook.c

NAME = fdf

FLAGS = -Wall -Wextra -Werror

Flagframe = -lmlx -framework OpenGL -framework AppKit

LIB = ./Libft/libft.a ./minilibx_macos/libmlx.a

OBJET = $(SRC_NAME:.c=.o)

all: $(NAME)
	@echo "Make In Progress"
	@echo "Make Done."

$(NAME): $(LIB) $(OBJET)
	@gcc $(FLAGS) $(OBJET) -L./Libft/ $(Flagframe) -lft -o $(NAME)

$(LIB):
	make -C ./Libft/

%.o: %.c
	@gcc $(FLAGS) -I./Libft/INCLUDES -c $<

clean:
	@echo "Clean In Progress"
	@rm -f $(OBJET)
	@echo "Clean Done."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

proper:
	@make
	@make clean -C ./Libft/
	@make clean

fcleanl:
	@make fclean -C ./Libft/
	@echo "./Libft/ Is Clean"
