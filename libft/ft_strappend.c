/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:38:49 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/30 16:24:38 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **str, char const *add)
{
	char		*new;
	unsigned	len;
	unsigned	i;
	unsigned	j;

	len = (*str ? ft_strlen(*str) : 0) + (add ? ft_strlen(add) : 0);
	if ((new = malloc(len + 1)))
	{
		i = 0;
		if (str && *str)
			while ((*str)[i])
			{
				new[i] = (*str)[i];
				++i;
			}
		j = 0;
		if (add)
			while (*add)
				new[i + j++] = *add++;
		new[i + j] = '\0';
		free(*str);
		*str = new;
	}
}
