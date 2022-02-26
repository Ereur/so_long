/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:38:14 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/20 12:38:23 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// first while checking the first wall and the last wal
void	check_map_walls(char **map, int down_wall, int len_of_wall)
{
	int	i;

	i = 0;
	while (i < len_of_wall - 1)
	{	
		if ((map[0][i] != '1') || (map[down_wall][i] != '1'))
		{
			printf("map should be surounded by walls");
			exit(1);
		}
		i++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len_of_wall - 2] != '1')
		{	
			printf("map should be surounded by walls");
			exit(1);
		}
		i++;
	}
}

void	check_collec_and_exits(char **map)
{
	int	i;
	int	c;
	int	j;
	int	e;

	c = 0;
	e = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (c == 0 || e == 0)
	{
		printf("there must be one 'P' and 'E', and at least one 'C' ");
		exit(1);
	}
}

void	check_player(char **map)
{
	int	i;
	int	p;
	int	j;

	p = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		if (p > 1)
		{
			printf("must be only one player");
			exit(1);
		}
		i++;
	}
	if (!p)
	{
		printf("must be one player");
		exit(1);
	}
}

int	check_map(char **map, char *file)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]);
	while (map[i])
	{	
		if (j != ft_strlen(map[i]))
		{
			printf("map must be rectandular");
			exit(1);
		}
		i++;
	}
	check_map_walls(map, i - 1, j);
	check_player(map);
	check_collec_and_exits(map);
	return (1);
}
