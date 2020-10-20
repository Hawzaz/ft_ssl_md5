/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:23:27 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/07 16:48:54 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		handle_di(t_printf *pt)
{
	precision_pt(pt, 'd', NULL);
	if (pt->fltypes.l == 1)
		pt->num = (long)pt->num;
	else if (pt->fltypes.ll == 1)
		pt->num = (long long)pt->num;
	else if (pt->fltypes.h == 1)
		pt->num = (short)pt->num;
	else if (pt->fltypes.hh == 1)
		pt->num = (signed char)pt->num;
	else
		pt->num = (int)pt->num;
	if (pt->flags.flag_d == 1 && pt->prec == 0 && (int)pt->num <= 0 &&
			pt->flags.flag_s == 1)
	{
		ft_putchar(' ');
		pt->ret++;
		return (1);
	}
	else if (pt->flags.flag_d == 1 && pt->prec == 0 && (int)pt->num == 0)
		return (1);
	else
		ft_putnbr_max(pt->num);
	pt->ret += ft_nbrlen(pt->num);
	return (1);
}

int		handle_o(t_printf *pt)
{
	flagouxx(pt);
	precision_pt(pt, 'o', NULL);
	if (pt->flags.flag_d == 1 && pt->prec == 0 && (int)pt->unum <= 0 &&
			pt->flags.flag_s == 1 && pt->flags.flag_h == 0)
	{
		ft_putchar(' ');
		pt->ret++;
		return (1);
	}
	else if (pt->flags.flag_d == 1 && pt->prec == 0 && (int)pt->unum <= 0 &&
			pt->flags.flag_h == 0)
		return (1);
	else
		ft_putnbr_base(pt->unum, "01234567");
	pt->ret += ft_nbrulen(pt->unum, 8);
	return (1);
}

int		handle_u(t_printf *pt)
{
	flagouxx(pt);
	precision_pt(pt, 'u', NULL);
	if (!pt->fltypes.l && !pt->fltypes.ll && pt->unum > 4294967295)
		pt->unum = 0;
	if (pt->flags.flag_d == 1 && pt->prec == 0 && pt->unum == 0)
		return (1);
	else
		ft_putnbr_base(pt->unum, "0123456789");
	pt->ret += ft_nbrulen(pt->unum, 10);
	return (1);
}

int		handle_x(t_printf *pt)
{
	flagouxx(pt);
	precision_pt(pt, 'x', NULL);
	if (!ft_strequ("%p", pt->con) &&
			!pt->fltypes.l && !pt->fltypes.ll && pt->unum > 4294967295)
		pt->unum = 0;
	if (pt->flags.flag_d == 1 && pt->prec == 0 && (int)pt->unum <= 0 &&
			pt->flags.flag_s == 1)
	{
		ft_putchar(' ');
		pt->ret++;
		return (1);
	}
	else if (pt->flags.flag_d == 1 && pt->prec == 0 && pt->unum == 0)
		return (1);
	else
		ft_putnbr_base(pt->unum, "0123456789abcdef");
	pt->ret += ft_nbrulen(pt->unum, 16);
	return (1);
}

int		handle_big_x(t_printf *pt)
{
	flagouxx(pt);
	precision_pt(pt, 'x', NULL);
	if (!pt->fltypes.l && !pt->fltypes.ll && pt->unum > 4294967295)
		pt->unum = 0;
	if (pt->flags.flag_d == 1 && pt->prec == 0 && pt->unum == 0)
		return (1);
	else
		ft_putnbr_base(pt->unum, "0123456789ABCDEF");
	pt->ret += ft_nbrulen(pt->unum, 16);
	return (1);
}
