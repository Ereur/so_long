/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:47:45 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/27 05:26:49 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	find_map_size(t_game game, char **map)
{
	int	i;

	i = 0;
	game.win_size.x = (ft_strlen(map[i]) - 1);
	game.win_size.y = 0;
	while (map[i])
	{
		i++;
		game.win_size.y++;
	}
	return (game.win_size);
}

void	*new_image(t_game game)
{
	game.new_imge.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr,
			game.new_imge.path, &game.new_imge.with, &game.new_imge.height);
	mlx_put_image_to_window(
		game.mlx_ptr,
		game.win_ptr,
		game.new_imge.img_ptr,
		game.new_imge.position.x,
		game.new_imge.position.y
		);
	mlx_destroy_image(game.mlx_ptr, game.new_imge.img_ptr);
	return (game.new_imge.img_ptr);
}

void	game_loader(char **map)
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	game.win_size = find_map_size(game, map);
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.win_size.x * 48),
			(game.win_size.y * 48), "SO_LONG");
	game.new_imge.position.x = 0;
	game.new_imge.position.y = 0;
	game.new_imge.path = "wall1.xpm";
	game.new_imge.img_ptr = NULL;
	upwall_builder(&game, map);
	game.map = map;
	game.graph = graph(map, &game);
	find_j(game.player_x_y.x, game.player_x_y.y,&game.player_node, game.map);
	storeimges(&game);
	find_j(game.ghost_position.x, game.ghost_position.y, &game.ghost_node, game.map);
	// printf("%d \n", game.ghost_node);
	// exit(1);
	game.test = game.player_node;
	mlx_hook(game.win_ptr, 2, 0, update, &game);
	mlx_loop_hook(game.mlx_ptr, playermove, &game);
	mlx_loop(game.mlx_ptr);
}
