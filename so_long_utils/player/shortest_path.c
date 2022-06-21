/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:22:29 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/27 05:48:44 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	check_queue(int j, t_linked_nodes *seen, t_linked_nodes **queue)
{	
	t_linked_nodes	*tmp;

	tmp = *queue;
	while (seen)
	{
		if (j == seen->node_nbr)
			return (0);
		seen = seen->next;
	}
	while (tmp)
	{
		if (j == tmp->node_nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	enqueue(t_vertex **graph, int current, t_linked_nodes **queue, t_linked_nodes *seen, int tmp[])
{	
	int				j;
	t_linked_nodes	*ptr;

	j = 0;
	while (graph[current][j].node)
	{
		if (graph[current][j].node == '1' && check_queue(j, seen, queue))
		{
			ptr = ft_lstnew_node(j);
			ft_lstadd_back_node(queue, ptr);
			tmp[j] = current;
		}
		j++;
	}
}

void	ft_dequee(t_linked_nodes **quee)
{
	t_linked_nodes	*tmp;
	t_linked_nodes	*tmp1;

	tmp = *quee;
	*quee = (*quee)->next;
	free(tmp);
}

void	find_path(int start, int end, int *paths, t_linked_nodes **valid_path, t_game *game)
{
	t_linked_nodes *prev;
	t_linked_nodes	*next;
	t_linked_nodes	*current;

	// ft_lstadd_back_node(valid_path, ft_lstnew_node(end));
	while (paths[end] != start)
	{
		end = paths[end];
		ft_lstadd_back_node(valid_path, ft_lstnew_node(end));
	}
	ft_lstadd_back_node(valid_path, ft_lstnew_node(start));
	// prev = NULL;
	// next = NULL;
	// current = *valid_path;
	// while (current)
	// {	
	// 	next = current->next;
	// 	current->next = prev;
	// 	prev = current;
	// 	current = next;
	// }
	// *valid_path = prev;
	game->shortest_path = *valid_path;
}

void	traverce_graph(t_game *game, int start, int end)
{
	t_linked_nodes	*new;
	t_linked_nodes	*quee;
	t_linked_nodes	*seen;
	t_linked_nodes	*tmp;
	int				i;

	tmp = NULL;
	game->shortest_path = NULL;
	new = ft_lstnew_node(game->player_node);
	creat_linked_nodes(game->graph, game->player_node, &tmp);
	quee = NULL;
	seen = NULL;
	ft_lstadd_back_node(&seen, new);
	game->paths = malloc(sizeof(int) * game->nbr_of_nodes);
	i = 0;
	while (i < game->nbr_of_nodes)
		game->paths[i++] = -1;
	while (tmp)
	{
		game->paths[tmp->node_nbr] = game->player_node;
		tmp = tmp->next;
	}
	creat_linked_nodes(game->graph, game->player_node, &quee);
	while (quee)
	{
		enqueue(game->graph, quee->node_nbr, &quee, seen, game->paths);
		ft_lstadd_back_node(&seen, ft_lstnew_node(quee->node_nbr));
		ft_dequee(&quee);
	}
	i = 0;
	find_path(start, end, game->paths, &game->shortest_path, game);
	while (game->shortest_path)
	{
		printf("| %d |", game->shortest_path->node_nbr);
		game->shortest_path = game->shortest_path->next;
	}
	printf("\n");
}
