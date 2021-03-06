/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:15:27 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 11:43:59 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*fn)(unsigned i, char *))
{
	unsigned i;

	i = 0;
	if (str && fn)
		while (*str)
			fn(i++, str++);
}
