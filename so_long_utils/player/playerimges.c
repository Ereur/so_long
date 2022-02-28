/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerimges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:13:19 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/28 08:13:14 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	ft_lstadd(t_listimg **lst, t_listimg *new)
{
	t_listimg	*tmp;

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


t_listimg	*ft_lstaddimgnew(char *content)
{
	t_listimg	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr)
	{
		ptr->content = content;
		ptr->next = NULL;
	}
	return (ptr);
}

void	storeimges(t_game *game)
{
	t_listimg	*node1;
	t_listimg	*node2;
	t_listimg	*node3;
	t_listimg	*node4;	

	game->first_img = NULL;
	node1 = ft_lstaddimgnew("pacmanupclose.xpm");
	node2 = ft_lstaddimgnew("pacmanup.xpm");
	ft_lstadd(&(game->first_img), node1);
	ft_lstadd(&(game->first_img), node2);
	game->current_img = game->first_img;
}