/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:19:16 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/26 05:52:32 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"



// int	not_multiplied_left(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->playerdirection == UP)
// 	{
// 		x = game->player_position.x / 48;
// 		y = game->player_position.y / 48;
// 		if (game->map[y][x - 1] == WALL)
// 			return (0);
// 		if (game->map[y + 1][x - 1] == WALL)
// 			return (0);
// 		return (1);
// 	}
// 	// else if (game->playerdirection == LEFT)
// 	// {
// 	// 	x = game->player_position.x / 48;
// 	// 	y = game->player_position.y / 48;
// 	// 	if (game->map[y][x - 1] == WALL)
// 	// 		return (0);
// 	// 	if (game->map[y + 1][x - 1] == WALL)
// 	// 		return (0);
// 	// 	return (1);
// 	//}
// 	// x = (game->player_position.x - 24) / 48;
// 	// y = (game->player_position.y) / 48;
// 	// if (game->map[y][x] == WALL)
// 	// 	return (0);
// 	// if (game->map[y][x] == COLLECTIBLE)
// 	// {
// 	// 	game->map[y][x] = '0';
// 	// 	game->collectile_nbr -= 1;
// 	// }
// 	return (1);
// }

// static	int	right(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->player_position.x % 48 != 0 || game->player_position.y % 48 != 0)
// 	{
// 		if (not_multiplied_left(game))
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	x = game->player_position.x / 48;
// 	y = game->player_position.y / 48;
// 	if (game->map[y][x - 1] == WALL)
// 		return (0);
// 	if (game->map[y][x - 1] == COLLECTIBLE)
// 	{	
// 		game->map[y][x - 1] = '0';
// 		game->collectile_nbr -= 1;
// 	}
// 	return (1);
// }

// int	up(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->player_position.y % 48 != 0)
// 	{
// 		if (not_multiplied_left(game))
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	if (right(game))
// 		return (1);
// 	else
// 		return (0);
// 	exit(1);
// }

// int	down(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->player_position.y % 48 != 0)
// 	{
// 		x = game->player_position.x / 48;
// 		y = game->player_position.y / 48;
// 		if (game->map[y][x - 1] == WALL)
// 			return (0);
// 		if (game->map[y + 1][x - 1] == WALL)
// 			return (0);
// 	}
// 	if (right(game))
// 		return (1);
// 	else
// 		return (0);
// 	exit(1);
// }
int	find_the_left_node(t_game *game, t_linked_nodes *head, short	*flag)
{
	int	current;
	int	dest;
	
	*flag = 0;
	current = game->player_node;
	while (head)
	{
		dest = head->node_nbr;
		if (current - 1 == dest)
		{
			*flag = 1;
			return (dest);
		}
		head = head->next;
	}
	return (dest);
}

int	check_wall_left(t_game *game)
{
	int				x;
	int				y;
	t_linked_nodes	*head;
	int				left_node;
	short			flag;

	head = NULL;
	creat_linked_nodes(game->graph,game->player_node, &head);
	left_node = find_the_left_node(game, head, &flag);
	// printf("okay %d  %d , %c . %d\n", up_node, game->player_node, game->graph[game->player_node][up_node].node, flag);
	if (game->graph[game->player_node][left_node].node == '1' && flag)
	{
		find_x_y(&x, &y, left_node, game->map);
		game->map[y][x] = 'P';
		game->player_node = left_node;
		return (1);
	}
	else
	{
		return (0);
	}
	return (1);
	// if (game->playerdirection == RIGHT || game->playerdirection == LEFT)
	// {
	// 	if (right(game))
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	// else if (game->playerdirection == UP)
	// {
	// 	if (up(game))
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	// else if (game->playerdirection == DOWN)
	// {
	// 	if (down(game))
	// 		return (1);
	// 	else
	// 		return(0);
	// }
	exit(1);
}