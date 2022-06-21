/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:02:29 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/27 03:52:57 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	find_the_right_node(t_game *game, t_linked_nodes *head, short	*flag)
{
	int	current;
	int	dest;

	*flag = 0;
	current = game->player_node;
	while (head)
	{
		dest = head->node_nbr;
		if (current + 1 == dest)
		{
			*flag = 1;
			return (dest);
		}
		head = head->next;
	}
	return (dest);
}

int	check_wall_right(t_game *game)
{
	int				x;
	int				y;
	t_linked_nodes	*head;
	int				right_node;
	short			flag;

	head = NULL;
	creat_linked_nodes(game->graph, game->player_node, &head);
	right_node = find_the_right_node(game, head, &flag);
	if (game->graph[game->player_node][right_node].node == '1' && flag)
	{
		find_x_y(&x, &y, right_node, game->map);
		game->map[y][x] = 'P';
		game->player_node = right_node;
		return (1);
	}
	else
	{
		return (0);
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
