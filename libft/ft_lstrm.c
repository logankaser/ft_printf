/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:47:45 by lkaser            #+#    #+#             */
/*   Updated: 2017/10/30 14:36:56 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm(t_list **lst, t_list *to_rm)
{
	t_list *prev;
	t_list *item;

	if (lst)
	{
		prev = NULL;
		item = *lst;
		while (item)
		{
			if (item == to_rm)
			{
				if (prev)
					prev->next = item->next;
				else
					*lst = item->next;
				free(item->content);
				free(item);
				break ;
			}
			prev = item;
			item = item->next;
		}
	}
}
