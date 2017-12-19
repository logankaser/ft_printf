/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:22:33 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 15:55:53 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarray(char **str)
{
	ft_putstr("[ ");
	while (*str)
	{
		ft_putchar('\"');
		ft_putstr(*str);
		ft_putchar('\"');
		++str;
		if (*str)
			ft_putstr(", ");
	}
	ft_putstr(" ]");
	ft_putchar('\n');
}
