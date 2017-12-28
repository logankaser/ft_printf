/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:32:35 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/16 14:49:18 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *m, size_t size)
{
	unsigned bit;

	bit = 0;
	if (!(size % 8))
	{
		size /= 8;
		while (bit < size)
			((unsigned long long*)m)[bit++] = 0;
	}
	else if (!(size % 4))
	{
		size /= 4;
		while (bit < size)
			((unsigned*)m)[bit++] = 0;
	}
	else
		while (bit < size)
			((unsigned char *)m)[bit++] = 0;
}
