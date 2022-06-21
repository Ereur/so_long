/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:11:49 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/27 05:23:02 by aamoussa         ###   ########.fr       */
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

typedef struct s_vertex
{
	char	node;
	char	right;
	char	left;
	char	up;
	char	down;
}	t_vertex;

typedef struct s_linked_nodes
{	
	int						node_nbr;
	struct s_linked_nodes	*next;
}	t_linked_nodes;

typedef enum s_components
{
	WALL = '1',
	PLAYER = 'P',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	UP = 1,
	DOWN = 2,
	RIGHT = 3,
	LEFT = 4,
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
	int			count_moves;
	int			collectile_nbr;
	t_vector	door_position;
	int			flag;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		new_imge;
	t_listimg	*current_img;
	t_listimg	*first_img;
	char		**map;
	int			playerdirection;
	t_vertex	**graph;
	t_vector	player_x_y;
	int			player_node;
	int			nbr_of_nodes;
	int			*paths;
	t_linked_nodes	*shortest_path;
	t_vector		ghost_position;
	int				ghost_node;
	int				test;
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
int			playermove(t_game *game);
void		storeimges(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
int			update(int key, t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);
int			check_wall_down(t_game *game);
int			check_wall_up(t_game *game);
int			check_wall_left(t_game *game);
t_vertex	**graph(char **map, t_game *game);
void			find_j(int x, int y, int *j, char **map);
void			find_x_y(int *x, int *y, int i, char **map);
void			creat_linked_nodes(t_vertex **graph, int current, t_linked_nodes **head);
void			ft_lstadd_back_node(t_linked_nodes	**lst, t_linked_nodes*new);
t_linked_nodes	*ft_lstnew_node(int	node_nbr);
void			traverce_graph(t_game *game, int start, int end);


#endif