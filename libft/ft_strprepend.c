/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:38:49 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/30 16:23:46 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strprepend(char const *add, char **str)
{
	char		*new;
	unsigned	len;
	unsigned	i;
	unsigned	j;

	len = (*str ? ft_strlen(*str) : 0) + (add ? ft_strlen(add) : 0);
	if ((new = malloc(len + 1)))
	{
		i = 0;
		if (add)
			while (*add)
				new[i++] = *add++;
		j = 0;
		if (str && *str)
			while ((*str)[j])
			{
				new[i + j] = (*str)[j];
				++j;
			}
		new[i + j] = '\0';
		free(*str);
		*str = new;
	}
}
