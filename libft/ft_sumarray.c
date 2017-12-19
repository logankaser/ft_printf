/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:33:46 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 16:06:53 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sumarray(int *int_array, size_t size)
{
	int			total;
	unsigned	i;

	total = 0;
	i = 0;
	while (i < size)
		total += int_array[i++];
	return (total);
}
