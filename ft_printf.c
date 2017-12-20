/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:14:26 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/19 21:39:49 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <unistd.h>
#define SWITCH(a,b) if (a) {b;}
#define CASE(a,b) else if (a) {b;}

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

static unsigned	read_num(char **f)
{
	unsigned	num;

	num = 0;
	while (ft_isdigit(**f))
	{
		num *= 10;
		num += **f - '0';
		++*f;
	}
	return (num);
}

static void		format_parse(char **f, va_list args, size_t *len)
{
	t_printf	pf;

	while (IS_ANY5(**f, '#', '0', '-', '+', ' '))
	{
		SWITCH(**f == '#', pf.pre = 1)
		CASE(**f == '0', pf.pad_zero = 1)
		CASE(**f == '-', pf.left_align = 1)
		CASE(**f == '+', pf.pre_plus = 1)
		CASE(**f == ' ', pf.pad_pos = 1)
		++*f;
	}
	pf.width = read_num(f);
	**f == '.' && (++*f);
	pf.prec = read_num(f);
	//format_print(pf, args, len);
	(void)args;
	(void)len;
}

static void		format_iter(char *f, va_list args, size_t *len)
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
			format_parse(&f, args, len);
			*len += d;
			d = 0;
		}
		d += f[d] != 0;
	}
	write(1, f, d);
	*len += d;
}

int				ft_printf(char *format, ...)
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
