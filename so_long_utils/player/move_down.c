/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:19:22 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/26 05:52:12 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

// int	not_multiplied_down(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	// printf("%d\n", game->player_position.x);
// 	// printf("%d", game->player_position.y);
// 	// exit(1);
// 	x = game->player_position.x / 48;
// 	y = game->player_position.y / 48;
// 	if (game->map[y + 1][x + 1] == WALL)
// 		return (0);
// 	x = (game->player_position.x) / 48;
// 	y = (game->player_position.y) / 48;
// 	if (game->map[y + 1][x] == WALL)
// 		return (0);
	
// 	return (1);
// }

// static int	down(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->player_position.x % 48 != 0)
// 	{
// 		if (not_multiplied_down(game))
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	x = game->player_position.x / 48;
// 	y = game->player_position.y / 48;
// 	if (game->map[y + 1][x] == WALL)
// 		return (0);
// 	if (game->map[y + 1][x] == COLLECTIBLE)
// 	{	
// 		game->map[y + 1][x] = '0';
// 		game->collectile_nbr -= 1;
// 	}
// 	return (1);
// }

// static int	right(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->player_position.x % 48 != 0)
// 	{
// 		if (not_multiplied_down(game))
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	x = game->player_position.x / 48;
// 	y = game->player_position.y / 48;
// 	if (game->map[y + 1][x] == WALL)
// 		return (0);
// 	return (1);
// }
int	find_the_down_node(t_game *game, t_linked_nodes *head, short	*flag)
{
	int	current;
	int	dest;
	
	*flag = 0;
	current = game->player_node;
	while (head)
	{
		dest = head->node_nbr;
		if (current < dest && current + 1 != dest && current - 1 != dest)
		{
			*flag = 1;
			return (dest);
		}
		head = head->next;
	}
	return (dest);
}

int	check_wall_down(t_game *game)
{
	int				x;
	int				y;
	t_linked_nodes	*head;
	int				down_node;
	short			flag;

	head = NULL;
	creat_linked_nodes(game->graph, game->player_node, &head);
	down_node = find_the_down_node(game, head, &flag);
	// printf("okay %d  %d , %c . %d\n", up_node, game->player_node, game->graph[game->player_node][up_node].node, flag);
	if (game->graph[game->player_node][down_node].node == '1' && flag)
	{
		find_x_y(&x, &y, down_node, game->map);
		game->map[y][x] = 'P';
		game->player_node = down_node;
		return (1);
	}
	else
	{
		return (0);
	}
	return (1);
	// if (game->playerdirection == UP || game->playerdirection == DOWN)
	// {
	// 	if (down(game))
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	// else if (game->playerdirection == RIGHT || game->playerdirection == LEFT)
	// {
	// 	if (right(game))
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	return (1);	
}
