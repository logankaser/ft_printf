/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:47:45 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/01 16:04:47 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst,
		char (*pred)(const void *, const void *), const void *data)
{
	while (lst)
	{
		if (pred(lst->content, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
