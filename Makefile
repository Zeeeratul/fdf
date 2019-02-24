# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrobert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 14:53:43 by frrobert          #+#    #+#              #
#    Updated: 2018/12/14 13:39:19 by cdelahay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRC= 	main.c \
		attribute_coord.c \
		color_altitude.c \
		deal_key.c \
		draw.c \
		fdf.c \
		keys_command.c \
		map.c \
		menu.c \
		print_line.c \

OBJ= $(SRC:%.c=%.o)

all:	 $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -L libft/ -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: clean fclean re all
