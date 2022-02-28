/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:02:29 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/28 12:38:49 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	not_multiplied_up(t_game *game)
{
	int	x;
	int	y;

	x = (game->player_position.x) / 48;
	y = (game->player_position.y - 24) / 48;
	if (game->map[y][x] == WALL)
		return (0);
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->map[y][x] = '0';
		game->collectile_nbr -= 1;
	}
	return (1);
}

int	not_multiplied_down(t_game *game)
{
	int	x;
	int	y;

	x = (game->player_position.x) / 48;
	y = (game->player_position.y - 24) / 48;
	if (game->map[y + 1][x] == WALL)
		return (0);
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->map[y][x] = '0';
		game->collectile_nbr -= 1;
	}
	return (1);
}

int	not_multiplied_left_loking_up(t_game *game)
{
	int	x;
	int	y;

	x = (game->player_position.x) / 48;
	y = (game->player_position.y - 24) / 48;
	if (game->map[y - 1][x - 1] == WALL)
		return (0);
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->map[y][x] = '0';
		game->collectile_nbr -= 1;
	}
	return (1);
}

int	not_multiplied_left(t_game *game)
{
	int	x;
	int	y;

	if (game->playerdirection == UP)
	{
		if (not_multiplied_left_loking_up(game))
			return (1);
		else
			return (0);
	}
	// x = (game->player_position.x - 24) / 48;
	// y = (game->player_position.y) / 48;
	// if (game->map[y][x] == WALL)
	// 	return (0);
	// if (game->map[y][x] == COLLECTIBLE)
	// {
	// 	game->map[y][x] = '0';
	// 	game->collectile_nbr -= 1;
	// }
	return (1);
}

int	check_wall_up(t_game *game)
{	
	int	x;
	int	y;

	if (game->player_position.y % 48 != 0)
	{
		if (not_multiplied_up(game))
			return (1);
		else
			return (0);
	}
	// if (game->flag == 0)
	// 	return (0);
	x = game->player_position.x / 48;
	y = game->player_position.y / 48;
	if (game->map[y - 1][x] == WALL)
		return (0);
	if (game->map[y - 1][x] == COLLECTIBLE)
	{
		game->map[y - 1][x] = '0';
		game->collectile_nbr -= 1;
	}
	game->flag = 0;
	return (1);
}

int	check_wall_down(t_game *game)
{
	int	x;
	int	y;

	if (game->player_position.y % 48 != 0)
	{
		if (not_multiplied_down(game))
			return (1);
		else
			return (0);
	}
	x = game->player_position.x / 48;
	y = game->player_position.y / 48;
	if (game->map[y + 1][x] == WALL)
		return (0);
	if (game->map[y + 1][x] == COLLECTIBLE)
	{	
		game->map[y + 1][x] = '0';
		game->collectile_nbr -= 1;
	}
	return (1);
}

int	check_wall_left(t_game *game)
{
	int	x;
	int	y;

	printf("%0d,   %d\n",game->player_position.x, game->player_position.y);
	if (game->player_position.x % 48 != 0 || game->player_position.y % 48 != 0)
	{
		if (not_multiplied_left(game))
			return (1);
		else
			return (0);
	}
	x = game->player_position.x / 48;
	y = game->player_position.y / 48;
	if (game->map[y][x - 1] == WALL)
		return (0);
	if (game->map[y][x - 1] == COLLECTIBLE)
	{	
		game->map[y][x - 1] = '0';
		game->collectile_nbr -= 1;
	}
	return (1);
}

int	not_multiplied_right_loking_up(t_game *game)
{
	int	x;
	int	y;

	x = (game->player_position.x) / 48;
	y = (game->player_position.y - 24) / 48;
	if (game->map[y - 1][x + 1] == WALL)
		return (0);
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->map[y][x] = '0';
		game->collectile_nbr -= 1;
	}
	return (1);
}

int	not_multiplied_right(t_game	*game)
{
	if ( game->playerdirection == UP)
	{
		if (not_multiplied_right_loking_up(game))
			return (1);
		else
			return (0);
	}
	return (1);
}

int	check_wall_right(t_game *game)
{
	int	x;
	int	y;
	if (game->player_position.x % 48 != 0 || game->player_position.y % 48 != 0)
	{
		if (not_multiplied_right(game))
			return (1);
		else
			return (0);
	}
	x = game->player_position.x / 48;
	y = game->player_position.y / 48;
	if (game->map[y][x + 1] == WALL)
		return (0);
	if (game->map[y][x + 1] == COLLECTIBLE)
	{	
		game->map[y][x + 1] = '0';
		game->collectile_nbr -= 1;
	}
	return (1);
}

void	ft_open_door(t_game *game)
{
	if (game->collectile_nbr == 0)
	{
		game->new_imge.path = "opendoor.xpm";
		game->new_imge.position.x = game->door_position.x;
		game->new_imge.position.y = game->door_position.y;
		new_image(*game);
	}
}

void	ft_printmoves(t_game *game)
{
	game->new_imge.path = "wall1.xpm";
	game->new_imge.position.x = 0;
	game->new_imge.position.y = 0;
	new_image(*game);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 0, 0, 0xffffff, ft_itoa(game->count_moves));
}

int	update(int key, t_game *game)
{	
	if (key == 13 && check_wall_up(game))
	{	
			move_up(game);
			game->count_moves += 1;
			ft_printmoves(game);
	}
	else if (key == 1 && check_wall_down(game))
	{
		move_down(game);
		game->count_moves += 1;
		ft_printmoves(game);
	}
	else if (key == 0 && check_wall_left(game))
	{
		move_left(game);
		game->count_moves += 1;
		ft_printmoves(game);

	}
	else if (key == 2 && check_wall_right(game))
	{
		move_right(game);
		game->count_moves += 1;
		ft_printmoves(game);
	}
	ft_open_door(game);
	return (0);
}
