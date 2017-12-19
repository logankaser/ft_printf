/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 20:25:45 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 12:45:11 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *current;
	t_list *prev;

	NULL_GUARD((lst && f));
	prev = NULL;
	head = f(ft_lstnew(lst->content, lst->content_size));
	current = head;
	lst = lst->next;
	while (lst)
	{
		prev = current;
		current = f(ft_lstnew(lst->content, lst->content_size));
		prev->next = current;
		lst = lst->next;
	}
	return (head);
}
