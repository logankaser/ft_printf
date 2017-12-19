/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:38:19 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/01 16:12:00 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list *new;

	NULL_GUARD(new = malloc(sizeof(t_list)));
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		NULL_GUARD(new->content = malloc(size));
		if (!new->content)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, size);
		new->content_size = size;
	}
	new->next = NULL;
	return (new);
}
