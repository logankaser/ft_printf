/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:32:35 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/16 14:49:18 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *m, int value, size_t size)
{
	unsigned bit;

	bit = 0;
	while (bit < size)
		((unsigned char *)m)[bit++] = (unsigned char)value;
	return (m);
}
