/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_has_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:47:41 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/15 14:47:05 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_has_only(const char *str, const char *has_only)
{
	char *check;

	while (*str)
	{
		check = (char *)has_only;
		while (*check && *check != *str)
			++check;
		if (!*check)
			return (0);
		++str;
	}
	return (1);
}
