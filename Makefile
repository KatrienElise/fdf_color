# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rsteigen <rsteigen@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/01 15:38:46 by rsteigen       #+#    #+#                 #
#    Updated: 2019/05/02 13:30:30 by kblum         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
FUNCS =	fdf.c print.c free.c error.c check.c setup.c events.c calc_setup.c\
rot.c draw.c bresem.c actions.c funcs.c bresem02.c bresem37.c touch.c inside.c\
setup_align.c calc_setup_dist_z.c fdf2.c iso.c

all: $(NAME)

$(NAME):
	make -C minilibx_macos/ clean && make -C minilibx_macos/
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -I includes/ -I minilibx_macos -c $(FUNCS)
	gcc $(FLAGS) -I includes/ -I minilibx_macos -c main.c
	gcc -o $(NAME) main.o $(FUNCS:.c=.o) -I includes -I minilibx_macos -L \
	libft/ -lft -L minilibx_macos -lmlx -framework OpenGL -framework APPkit

clean:
	/bin/rm -f $(FUNCS:.c=.o) main.o *~
	make -C libft/ fclean
	make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
