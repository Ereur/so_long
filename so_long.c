/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:13:02 by aamoussa          #+#    #+#             */
/*   Updated: 2022/03/20 17:35:52 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_utils/so_long.h"

/* what im doing :  im in game loader trying to find the player node number */

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		with;
	int		height;
	void	*img_ptr;
	char	*relativepath;

	relativepath = "wall.xpm";
	if (argc > 1)
	{	
		map = map_reader(argv[1]);
		check_map(map, argv[1]);
		game_loader(map);
	}
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "ARAK L ZHOO");
	// img_ptr = mlx_xpm_file_to_image(mlx_ptr, relativepath, &with, &height);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 47, 0);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 94, 0);
	// if (!img_ptr)
	// {
	// 	printf("the new window fail to open");
	// 	return (0);
	// }
	mlx_loop(mlx_ptr);
}
