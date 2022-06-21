# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 11:45:26 by aamoussa          #+#    #+#              #
#    Updated: 2022/03/26 05:45:29 by aamoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit

NAME = so_long

FUNC = ./so_long_utils/map_reader.c ./so_long_utils/map_checker.c ./so_long_utils/get_next_line.c ./so_long_utils/game_loader.c \
		./so_long_utils/wall_builder.c  ./so_long_utils/player/inesertplayer.c  ./so_long_utils/player/playerimges.c ./so_long_utils/player/move_up.c \
		./so_long_utils/update.c ./so_long_utils/player/move_down.c ./so_long_utils/player/move.c ./so_long_utils/player/move_left.c ./so_long_utils/map_to_graph.c \
		./so_long_utils/player/shortest_path.c
OBJ = *.o

all : $(NAME)

$(NAME):
#$(MAKE) -C ./so_long_utils/libft
	cc -I /usr/local/include so_long.c $(FUNC) ./so_long_utils/libft/libft.a -o so_long $(PATH)

clean:

fclean:
	rm -rf $(NAME)

re : fclean all

.PHONY: re fclean all clean bonus
