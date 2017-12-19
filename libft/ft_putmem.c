/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:01:52 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 16:05:20 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(char *varname, void *var, size_t bytes)
{
	unsigned	i;
	char		*str;

	str = (char *)var;
	ft_putstr(varname);
	write(1, " = \"", 4);
	i = 0;
	while (i < bytes)
	{
		if (str[i])
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		++i;
	}
	write(1, "\"\n", 2);
}
