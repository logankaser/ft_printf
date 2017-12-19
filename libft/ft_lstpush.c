/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:50:45 by lkaser            #+#    #+#             */
/*   Updated: 2017/10/30 18:18:34 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpush(t_list **lst, void *content, size_t size)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->content = content;
	new->content_size = size;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
	return (new);
}
