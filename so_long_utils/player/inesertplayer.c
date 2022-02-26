/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inesertplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 06:54:42 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/24 08:17:36 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	insertplayer(t_game *game)
// {
// 	game->new_imge.path = "./so_long_utils/sprites/player.xpm";
// 	game->new_imge.position.x = 10;
// 	game->new_imge.position.y = 100;
// 	game->new_imge.img_ptr = new_image(*game);
// }

char	*get_img_path(int img)
{
	char	*path;
	char	*file;
	
	file = ft_strjoin("./so_long_utils/sprites/", ft_itoa(img));
	path = ft_strjoin(file, ".xpm");
	free(file);
	return (path);
}

int	playermove(int key, t_game *game)
{
	int		a;
	int		j;
	int 	i;

	if(!game->current_img->next)
	{	
		game->current_img->next = game->first_img;
	}
	game->new_imge.path = "./so_long_utils/sprites/black3.xpm";
	new_image(*game);
	game->new_imge.position.x += 12;
	game->new_imge.path = game->current_img->content;
	new_image(*game);
	game->current_img = game->current_img->next;
	return (0);
}