/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:26:59 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/26 02:38:37 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

// int	not_multiplied_up(t_game *game, int direction)
// {
// 	int	x;
// 	int	y;

// 	if (direction == UP)
// 	{
// 		x = (game->player_position.x) / 48;
// 		y = (game->player_position.y) / 48;
// 		if (game->map[y][x] == WALL)
// 			return (0);
// 		return (1);
// 	}
// 	else if (direction == LEFT)
// 	{
// 		x = (game->player_position.x) / 48;
// 		y = (game->player_position.y) / 48;
// 		if (game->map[y - 1][x] == WALL)
// 			return (0);
// 		if (game->map[y - 1][x + 1] == WALL)
// 			return (0);
// 		return (1);
// 	}
// 	exit(1);
// }

// static int	up(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->player_position.y % 48 != 0)
// 	{
// 		if (not_multiplied_up(game, UP))
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	x = game->player_position.x / 48;
// 	y = (game->player_position.y) / 48;
// 	if (game->map[y - 1][x] == WALL)
// 		return (0);
// 	if (game->map[y - 1][x] == COLLECTIBLE)
// 	{	
// 		game->map[y - 1][x] = '0';
// 		game->collectile_nbr -= 1;
// 	}
// 	return (1);
// }

// static int	left(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->player_position.x % 48 != 0)
// 	{
// 		if (not_multiplied_up(game, LEFT))
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	x = game->player_position.x / 48;
// 	y = game->player_position.y / 48;
// 	if (game->map[y - 1][x] == WALL)
// 		return (0);
// 	return (1);
// }
t_linked_nodes	*ft_lstnew_node(int	node_nbr)
{
	t_linked_nodes	*ptr;

	ptr = malloc(sizeof(t_linked_nodes));
	if (ptr)
	{
		ptr->node_nbr = node_nbr;
		ptr->next = NULL;
	}
	return (ptr);
}

void	ft_lstadd_back_node(t_linked_nodes	**lst, t_linked_nodes	*new)
{
	t_linked_nodes	*tmp;
	
	tmp = *lst;
	if (!(*lst))
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{	
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	creat_linked_nodes(t_vertex **graph, int current, t_linked_nodes **head)
{	
	int				j;
	t_linked_nodes	*ptr;

	j = 0;
	while (graph[current][j].node)
	{
		if (graph[current][j].node == '1')
		{
			ptr = ft_lstnew_node(j);
			ft_lstadd_back_node(head, ptr);
		}
		j++;
	}
}

int	find_the_up_node(int current, t_linked_nodes *head, short	*flag)
{
	int	dest;

	*flag = 0;
	while (head)
	{
		dest = head->node_nbr;
		if (current > dest && current + 1 != dest && current - 1 != dest)
		{
			*flag = 1;
			return (dest);
		}
		head = head->next;
	}
	return (dest);
}

int	check_wall_up(t_game *game)
{
	int				x;
	int				y;
	t_linked_nodes	*head;
	int				up_node;
	short			flag;

	head = NULL;
	creat_linked_nodes(game->graph, game->player_node, &head);
	up_node = find_the_up_node(game->player_node, head, &flag);
	if (game->graph[game->player_node][up_node].node == '1' && flag)
	{
		find_x_y(&x, &y, up_node, game->map);
		game->map[y][x] = 'P';
		game->player_node = up_node;
		return (1);
	}
	else
	{
		return (0);
	}
	return (1);
}
