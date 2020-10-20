/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:49:44 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/02 18:26:42 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_pct(t_printf *pt)
{
	ft_putchar('%');
	pt->ret++;
	pt->inc--;
}

int		ft_nbrulen(uintmax_t n, uintmax_t base)
{
	int			cpt;

	cpt = 1;
	while (n >= base)
	{
		n /= base;
		cpt++;
	}
	return (cpt);
}

int		act_l(t_printf *pt, int i)
{
	if (pt->str[i] == 'l' && pt->str[i + 1] == 'l')
	{
		pt->fltypes.ll = 1;
		i++;
	}
	else if (pt->str[i] == 'h' && pt->str[i + 1] == 'h')
	{
		pt->fltypes.hh = 1;
		i++;
	}
	else if (pt->str[i] == 'l')
	{
		pt->fltypes.l = 1;
		i++;
	}
	else if (pt->str[i] == 'h')
	{
		pt->fltypes.h = 1;
		i++;
	}
	return (i);
}

int		handling_types(t_printf *pt)
{
	static	t_types		types[] = {
		{ "%d" }, { "%i" }, { "%o" }, { "%u" }, { "%x" }, { "%X" }, { "%c" },
		{ "%s" }, { "%p" }, { "%%" },
	};

	if (ft_strequ(pt->con, types[0].type) || ft_strequ(pt->con, types[1].type))
		handle_di(pt);
	else if (ft_strequ(pt->con, types[2].type))
		handle_o(pt);
	else if (ft_strequ(pt->con, types[3].type))
		handle_u(pt);
	else if (ft_strequ(pt->con, types[4].type))
		handle_x(pt);
	else if (ft_strequ(pt->con, types[5].type))
		handle_big_x(pt);
	else if (ft_strequ(pt->con, types[6].type))
		handle_c(pt);
	else if (ft_strequ(pt->con, types[7].type))
		handle_s(pt);
	else if (ft_strequ(pt->con, types[8].type))
		handle_p(pt);
	else if (ft_strequ(pt->con, types[9].type))
		handle_pct(pt);
	ft_strdel(&pt->con);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	t_printf	pt;

	ft_memset(&pt, 0, sizeof(pt));
	pt.str = (char *)format;
	va_start(pt.lst, format);
	ft_print(&pt);
	va_end(pt.lst);
	return (pt.ret);
}
