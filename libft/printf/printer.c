/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:36:33 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/07 19:04:59 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_m(t_printf *pt)
{
	if (pt->flags.flag_m == 1)
	{
		if (pt->sp && pt->flags.flag_s == 1)
		{
			ft_putstr(pt->sp);
			pt->ret += ft_strlen(pt->sp);
		}
		else if (pt->sp)
		{
			ft_putstr(pt->sp);
			pt->ret += ft_strlen(pt->sp);
		}
		if (pt->sp)
			ft_strdel(&pt->sp);
	}
}

int		flagouxx(t_printf *pt)
{
	if (pt->fltypes.l == 1)
		pt->unum = (unsigned long)pt->unum;
	else if (pt->fltypes.ll == 1)
		pt->unum = (unsigned long long)pt->unum;
	else if (pt->fltypes.h == 1)
		pt->unum = (unsigned short)pt->unum;
	else if (pt->fltypes.hh == 1)
		pt->unum = (unsigned char)pt->unum;
	else if (!ft_strequ(pt->con, "%p"))
		pt->unum = (unsigned int)pt->unum;
	return (1);
}

int		handle_num(t_printf *pt, int i)
{
	char	buff[10];
	int		newi;

	newi = 0;
	if ((ft_isnum(pt->str[i]) && (pt->str[i] != '0')))
	{
		newi = buff_fill(pt->str, i, buff);
		pt->nb = ft_atoi(buff);
	}
	if (pt->flags.flag_z == 0)
		pt->flags.flag_s = 1;
	return (newi);
}

int		ft_putchar_spe(t_printf *pt, char c, int i)
{
	i += pt->str[i] == '%' && pt->str[i + 1] == '%' ? 2 : 1;
	write(1, &c, 1);
	pt->ret++;
	return (i);
}

int		ft_print(t_printf *pt)
{
	int		i;

	i = pt->i;
	pt->inc = 0;
	while (pt->str && pt->str[i] && pt->str[i] != '%')
		i = ft_putchar_spe(pt, pt->str[i], i);
	if (pt->str && pt->str[i] == '%' && pt->str[i + 1] == '%')
		i = ft_putchar_spe(pt, '%', i);
	else if (pt->str && pt->str[i] == '%')
	{
		print_parse(pt, i);
		parser_flags(pt, i + 1);
		nul_flags(pt);
		flag_handling(pt);
		handling_types(pt);
		handle_m(pt);
		i += pt->inc + 1;
		clean_pt(pt);
	}
	pt->i = i;
	if (pt->str && pt->str[i])
		ft_print(pt);
	return (1);
}
