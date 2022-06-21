/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:18:23 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/21 19:02:04 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	move_up(t_game *game)
{
	int		a;
	int		j;
	int		i;

	if (!game->current_img)
		game->current_img = game->first_img;
	game->new_imge.position.x = game->player_position.x;
	game->new_imge.position.y = game->player_position.y;
	game->new_imge.path = "blackpac.xpm";
	new_image(*game);
	game->new_imge.path = game->current_img->content;
	game->playerdirection = UP;
	game->new_imge.position.y -= 48;
	new_image(*game);
	game->player_position.x = game->new_imge.position.x;
	game->player_position.y = game->new_imge.position.y;
	game->current_img = game->current_img->next;
}

void	move_down(t_game *game)
{
	game->new_imge.position.x = game->player_position.x;
	game->new_imge.position.y = game->player_position.y;
	game->new_imge.path = "blackpac.xpm";
	new_image(*game);
	game->new_imge.path = "pacmandown.xpm";
	game->new_imge.position.y += 48;
	// game->new_imge.path = game->current_img->content;
	game->playerdirection = DOWN;
	new_image(*game);
	game->player_position.x = game->new_imge.position.x;
	game->player_position.y = game->new_imge.position.y;
}

void	move_left(t_game *game)
{
	game->new_imge.position.x = game->player_position.x;
	game->new_imge.position.y = game->player_position.y;
	game->new_imge.path = "blackpac.xpm";
	new_image(*game);
	game->new_imge.path = "pacmanleft.xpm";
	game->new_imge.position.x -= 48;
	game->playerdirection = LEFT;
	// game->new_imge.path = game->current_img->content;
	new_image(*game);
	game->player_position.x = game->new_imge.position.x;
	game->player_position.y = game->new_imge.position.y;
}

void	move_right(t_game *game)
{
	game->new_imge.position.x = game->player_position.x;
	game->new_imge.position.y = game->player_position.y;
	game->new_imge.path = "blackpac.xpm";
	new_image(*game);
	game->new_imge.path = "pacmanright.xpm";
	game->new_imge.position.x += 48;
	// game->new_imge.path = game->current_img->content;
	game->playerdirection = RIGHT;
	new_image(*game);
	game->player_position.x = game->new_imge.position.x;
	game->player_position.y = game->new_imge.position.y;
}
