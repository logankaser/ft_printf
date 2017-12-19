/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 09:35:25 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/20 09:50:22 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t size)
{
	unsigned i;

	i = 0;
	while ((a[i] || b[i]) && i < size)
	{
		if (a[i] != b[i])
			return (*((unsigned char *)a + i) - *((unsigned char *)b + i));
		++i;
	}
	return (0);
}
