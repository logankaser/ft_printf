/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:22:33 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 15:56:15 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putintarray(int *int_array, size_t size)
{
	unsigned i;

	i = 0;
	ft_putstr("[ ");
	while (i < size)
	{
		ft_putnbr(int_array[i++]);
		if (i != size)
			ft_putstr(", ");
	}
	ft_putstr(" ]");
	ft_putchar('\n');
}
