/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:02:29 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/24 12:11:41 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	check_wall_up(char **map, t_vector position)
{	
	int	x;
	int	y;

	x = position.x / 48;
	y = position.y / 48;
	// printf("%d . %d", x, y);
	// exit(1);
	if(map[y - 1][x] == WALL)
		return (0);
	 return (1);
}

int	check_wall_down(char **map, t_vector position)
{
	int	x;
	int	y;

	x = position.x / 48;
	y = position.y / 48;
	// printf("%d . %d", x, y);
	// exit(1);
	if(map[y + 1][x] == WALL)
		return (0);
	 return (1);
}

int	check_wall_left(char **map, t_vector position)
{
	int	x;
	int	y;

	x = position.x / 48;
	y = position.y / 48;
	// printf("%d . %d", x, y);
	// exit(1);
	if(map[y][x - 1] == WALL)
		return (0);
	 return (1);
}

int	check_wall_right(char **map, t_vector position)
{
	int	x;
	int	y;

	x = position.x / 48;
	y = position.y / 48;
	// printf("%d . %d", x, y);
	// exit(1);
	if(map[y][x + 1] == WALL)
		return (0);
	 return (1);
}

int	update(int key, t_game *game)
{
	if (key == 13 && check_wall_up(game->map, game->player_position))
	{
		move_up(game);
	}
	else if (key == 1 && check_wall_down(game->map, game->player_position))
	{
		move_down(game);
	}
	else if (key == 0 && check_wall_left(game->map, game->player_position))
	{
		move_left(game);
	}
	else if (key == 2 && check_wall_right(game->map, game->player_position))
	{
		move_right(game);
	}
	return (0);
}