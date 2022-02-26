/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:11:49 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/24 11:40:51 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include<mlx.h>
# include<stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef enum s_components
{
	WALL = '1',
	PLAYER = 'P',
	COLLECTIBLE = 'C',
	EXIT = 'E',	
}	t_components;

typedef struct s_listofimages
{
	char					*content;
	struct s_listofimages	*next;
}	t_listimg;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*img_ptr;
	char		*path;
	int			with;
	int			height;
	t_vector	position;
}	t_image;

typedef struct s_game
{
	t_vector	win_size;
	t_vector	player_position;
	t_vector	door_position;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		new_imge;
	t_listimg	*current_img;
	t_listimg	*first_img;
	char		**map;
}	t_game;

char		**map_reader(char *file);
int			ft_count_line(char *file);
int			check_map(char **map, char *file);
void		game_loader(char **map);
void		*new_image(t_game game);
void		upwall_builder(t_game *game, char **map);
void		leftwall_builder(t_game game);
void		rightwall_builder(t_game game);
void		insertplayer(t_game *game);
int			playermove(int key, t_game *game);
t_listimg	*storeimges(void);
void		move_up(t_game *game);
void		move_down(t_game *game);
int			update(int key, t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);

#endif