/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:24:27 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/26 10:35:19 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	upwall_builder(t_game *game, char **map)
{
	int	i;
	int	count_line;
	int	j;
	
	i = 0;
	game->new_imge.position.y = 0;
	game->new_imge.position.x =	-48;

	while (map[i])
	{	
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == WALL)
			{
				game->new_imge.position.x += 48;
				game->new_imge.path = "wall1.xpm";
				new_image(*game);
			}
			else if (map[i][j] == PLAYER)
			{
				game->new_imge.position.x += 48;
				game->player_position.x = game->new_imge.position.x;
				game->player_position.y = game->new_imge.position.y;
				game->new_imge.path = "pacman.xpm";
				new_image(*game);
			}
			else if (map[i][j] == COLLECTIBLE)
			{
				game->new_imge.path = "collec.xpm";
				game->new_imge.position.x += 48;
				game->collectile_nbr += 1;
				new_image(*game);
			}
			else if (map[i][j] == EXIT)
			{
				game->new_imge.path = "closeddoor.xpm";
				game->new_imge.position.x += 48;
				game->door_position.x = game->new_imge.position.x;
				game->door_position.y = game->new_imge.position.y;
				new_image(*game);
			}
			else if (map[i][j] == '0')
			{
				game->new_imge.position.x += 48;
			}
			j++;
		}
		game->new_imge.position.y += 48;
		game->new_imge.position.x =	-48;
		i++;
	}
}

// void	leftwall_builder(t_game game)
// {
// 	int	i;
// 	int	nbr_ofright_wall;

// 	nbr_ofright_wall = ft_count_line("map.ber");
// 	i = 0;
// 	game.new_imge.path = "leftwall.xpm";
// 	game.new_imge.position.y = 7;
// 	game.new_imge.position.x = 1;
// 	while (i++ < nbr_ofright_wall)
// 	{
// 		new_image(game);
// 		game.new_imge.position.y += 46;
// 	}
// 	game.new_imge.path = "corner_left_down.xpm";
// 	game.new_imge.position.y = 47 * ((nbr_ofright_wall - 2) + 0.8);
// 	game.new_imge.position.x = 1;
// 	new_image(game);
// 	game.new_imge.path = "corner_up_left_wall.xpm";
// 	game.new_imge.position.y = 0;
// 	game.new_imge.position.x = 1;
// 	new_image(game);
// }

// void	rightwall_builder(t_game game)
// {
// 	int	i;
// 	int	nbr_ofright_wall;

// 	nbr_ofright_wall = ft_count_line("map.ber");
// 	i = 0;
// 	game.new_imge.path = "right_wall.xpm";
// 	game.new_imge.position.y = 7;
// 	game.new_imge.position.x = (nbr_ofright_wall + 2) * 60.8;
// 	while (i++ < nbr_ofright_wall)
// 	{
// 		new_image(game);
// 		game.new_imge.position.y += 46;
// 	}
// 	game.new_imge.path = "corner_right_down.xpm";
// 	game.new_imge.position.y = 47 * ((nbr_ofright_wall - 2) + 0.8);
// 	game.new_imge.position.x = (nbr_ofright_wall + 2) * 60.8;
// 	new_image(game);
// 	game.new_imge.path = "corner_right_up.xpm";
// 	game.new_imge.position.y = 1;
// 	game.new_imge.position.x = (nbr_ofright_wall + 2) * 60.8;
// 	new_image(game);
// }
