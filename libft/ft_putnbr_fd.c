/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:08:27 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/21 15:04:20 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		render_nbr(int nb, int fd)
{
	if (nb >= 10 || nb <= -10)
	{
		render_nbr(nb / 10, fd);
		render_nbr(nb % 10, fd);
	}
	else
		ft_putchar_fd((nb > 0 ? nb : nb * -1) + 48, fd);
}

void			ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	render_nbr(nb, fd);
}
