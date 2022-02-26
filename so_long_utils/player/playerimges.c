/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerimges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:13:19 by aamoussa          #+#    #+#             */
/*   Updated: 2022/02/24 08:17:48 by aamoussa         ###   ########.fr       */
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

t_listimg	*storeimges(void)
{
	t_listimg	*node1;
	t_listimg	*node2;
	t_listimg	*node3;
	t_listimg	*node4;	
	t_listimg	*head;

	head = NULL;
	node1 = ft_lstaddimgnew("./so_long_utils/sprites/p3.xpm");
	node2 = ft_lstaddimgnew("./so_long_utils/sprites/p6.xpm");
	node3 =ft_lstaddimgnew("./so_long_utils/sprites/p12.xpm");
	node4 = ft_lstaddimgnew("./so_long_utils/sprites/player.xpm");	
	ft_lstadd(&head, node1);
	ft_lstadd(&head, node2);
	ft_lstadd(&head, node3);
	ft_lstadd(&head, node4);
	return (head);
}