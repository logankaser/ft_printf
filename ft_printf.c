/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:14:26 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/18 15:06:37 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>

/*
**%[%][flags][width][(dot)precision][length]specifier
**
**Specifiers:
**	s	string
**	S	wide char string
**	p	pointer
**	di	int, D = ld
**	u	unsigned, U = lu
**	o	unsigned in octal, O = lo
**	x	unsigned in hexadecimal
**	X	unsigned in hexadecimal uppercase
**	cC	char
**
**Flags:
**	#		(o,O) prepend '0', x prepend "0x", X prepend "0X"
**	0		Prepend pad with '0' to width (if specified) for numeric types
**	-		Left align within width (if specified)
**	+		Prepend '+' for positive numeric types
**	(space)	Prepend pad positive numbers with a space
**
**Width:
**	<n>	Minimum of n characters are printed
**	*	(Bonus) Width is an int arg before the specifed arg
**
**Precision:
**	(dot)<n>	(idD, uU, oO, xX) Pad with leading zeros if less than n
**	(dot)*		(Bonus) Precision is an int arg before the specifed arg
**
**Length (Aka cast as this):
**	hh	(idD) char,			(uU, oO, xX) unsigned char
**	h	(idD) short,		(uU, oO, xX) unsigned short
**	l	(idD) long,			(uU, oO, xX) unsigned long
**	ll	(idD) long long,	(uU, oO, xX) unsigned long long
**	j	(idD) intmax_t,		(uU, oO, xX) uintmax_t
**	z	(idD) size_t,		(uU, oO, xX) size_t
**
**Return Value:
**	Length of printed string
**.
*/

static void	format_parse(char **f, va_list args, size_t *len)
{

}

static void	format_iter(char *f, va_list args, size_t *len)
{
	size_t d;

	d = 0;
	while (f[d])
	{
		if (f[d] == '%')
		{
			if (f[d + 1] == '%')
			{
				write(1, f, ++d);
				*len += d;
				f += ++d;
				d = 0;
				continue;
			}
			write(1, f, d);
			f += d + 1;
			format_parse(&f, args, &d);
			*len += d;
			d = 0;
		}
		d += f[d] != 0;
	}
	write(1, f, d);
	*len += d;
}

int			ft_printf(char *format, ...)
{
	va_list	args;
	size_t	len;

	if (format)
	{
		va_start(args, format);
		len = 0;
		format_iter(format, args, &len);
		va_end(args);
		return (len);
	}
	return (0);
}

#include <stdio.h>
int			main(int argc, char **argv)
{
	int r;

	(void)argc;
	r = ft_printf(argv[1]);
	printf("\n%i\n", r);
	return (0);
}
