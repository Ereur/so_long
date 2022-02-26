/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:39 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/19 15:22:02 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// count how many lines in map file
int	ft_count_line(char *file)
{
	char	*line;
	int		fd;
	int		nbr_of_line;

	nbr_of_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
	{	
		printf("file failed to open");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		nbr_of_line++;
	}
	close(fd);
	return (nbr_of_line);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i++]);
	}
}

// copy map to a 2d ARRAY 
char	**map_reader(char *file)
{
	char	**map;
	int		nmbr_of_lines;
	int		i;
	int		fd;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 1)
	{	
		printf("file failed to open");
		exit(1);
	}
	i = 0;
	nmbr_of_lines = ft_count_line(file);
	map = malloc(sizeof(char *) * (nmbr_of_lines + 1));
	map[nmbr_of_lines] = NULL;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i++])
			break ;
	}
	tmp = map[i - 2];
	map[i - 2] = ft_strjoin(map[i - 2], "\n");
	free(tmp);
	close(fd);
	return (map);
}
