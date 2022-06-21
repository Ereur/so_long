/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:26:27 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/26 23:38:02 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	find_the_node_nb(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	find_x_y(int *x, int *y, int i, char **map)
{
	int	node_count;
	int j;
	
	node_count = 0;
	*x = 1;
	*y = 1;
	while (map[*y])
	{	
		(*x) = 1;
		while (*x < ft_strlen(map[0]) - 2)
		{
			if (node_count == i)
				return ;
			node_count++;
			(*x)++;
		}
		(*y)++;
	}
}

void	find_j(int x, int y, int *j, char **map)
{
	int	node_count;
	int i;
	int b;

	node_count = 0;
	i = 1;
	while (map[i])
	{
		b = 1;
		/* x = 4  y = 2*/
		while (b < ft_strlen(map[0]) - 2)
		{
			if (x == b && y == i)
			{
				*j = node_count;
				return ;
			}
			node_count++;
			b++;
		}
		i++;
	}
}

void	make_edges(char **map, t_vertex **graph, int v)
{
	int	i;
	int	j;
	int	x,y;

	i = 0;
	x = 1;
	y = 1;
	j = 0;
	// find_x_y(&x, &y, 500, map);
	while (graph[i])
	{	
		find_x_y(&x, &y, i, map);
		graph[i][j].down = '0';
		graph[i][j].up = '0';
		graph[i][j].right = '0';
		graph[i][j].left = '0';	
		if (map[y][x] != '1')
		{
			if ((y - 1) >= 1 && (y - 1) <= v - 1)
			{
				if (map[y - 1][x] != '1')
				{
					find_j(x, y - 1, &j, map);
					graph[i][j].node = '1';
					graph[i][j].up = '1';
				}
			}
			if ((y + 1) >= 1 && (y + 1) <= v - 1)
			{
				if (map[y + 1][x] != '1')
				{
					find_j(x, y + 1, &j, map);
					graph[i][j].node = '1';
					graph[i][j].down = '1';
				}
			}
			if ((x + 1) >= 1 && (x + 1) <= ft_strlen(map[0]) - 2)
			{
				if (map[y][x + 1] != '1')
				{
					find_j(x + 1, y, &j, map);
					graph[i][j].node = '1';
					graph[i][j].right = '1';
				}
			}
			if ((x - 1) >= 1 && (x - 1) <= ft_strlen(map[0]) - 2)
			{
				if (map[y][x - 1] != '1')
				{
					find_j(x - 1, y, &j, map);
					graph[i][j].node = '1';
					graph[i][j].left = '1';
				}
			}
		}
		i++;
	}
	// printf("test : %c\n", graph[i][j].up);
	// if (i == 273)
	// 	exit(1);
}

int	check(t_vertex **graph, int i)
{
	int	j;

	j = 0;
	while (graph[i][j].node)
		if (graph[i][j++].node == '1')
			return (1);
	return (0);
}

void	find_edge_direction(int curent, int dest)
{
	if (curent < dest && curent + 1 != dest && curent - 1 != dest)
	{
		printf ("to Down | ");
	}
	if (curent > dest && curent + 1 != dest && curent - 1 != dest)
	{
		printf ("to UP | ");
	}
	if (curent + 1 == dest)
	{
		printf ("to RIGHT | ");
	}
	if (curent - 1 == dest)
	{
		printf ("to left | ");
	}
}

void	printgraph(t_vertex **graph, int v)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// while(graph[i])
	// 	printf("%s\n",graph[i++]);
	while (graph[i])
	{	
		if (check(graph, i))
			printf("\nthe vertex %d linked with : \n", i);
		j = 0;
		while (j < v)
		{
			if (graph[i][j].node == '1')
			{	
				printf("|  ->%d ", j);
				find_edge_direction(i , j);
			}
			j++;
		}
		// if (i == 38)
		// 	exit(1);
		i++;
	}
}

t_vertex	**graph(char **map, t_game *game)
{
	int	matrix_size;
	int	v;
	t_vertex **graph;
	int	i, j;
	v = find_the_node_nb(map);
	matrix_size = ft_strlen(map[0]);
	v = (matrix_size - 3) * (v - 2);
	game->nbr_of_nodes = v;
	graph = malloc(sizeof(t_vertex *) * (v + 1));
	graph[v] = NULL;
	i = 0;
	while (i < v)
	{	
		j = 0;
		graph[i] = malloc(sizeof(t_vertex) * (v + 1));
		while (j < v)
		{
			graph[i][j].node = '0';
			j++;
		}
		graph[i][j].node = 0;
		i++;
	}
	make_edges(map, graph, find_the_node_nb(map));
	// printgraph(graph, v);
	// j = 0;
	// while (graph[0][j].node)
	// {
	// 	printf("the vertex 0 ")
	// }
	return (graph);
}